#include "engine/mice_manager.h"

#include "engine/raylib.h"

#include <li.h>
#include <thread>
#include <map>
#include <charconv>

namespace engine {
  bool EventCompare::operator()(const std::string& a, const std::string& b) const {
    int numA{}, numB{};
    std::from_chars(a.data()+sizeof("event"), a.data()+a.size(), numA);
    std::from_chars(b.data()+sizeof("event"), b.data()+b.size(), numB);

    return numA < numB;
  }

  struct SingleType : public MiceManager::Type {
    SingleType(MiceManager::MouseList& list) :
      Type(list) {
        list["default"] = {};
      }
    ~SingleType() {}

    virtual void update() override {
      listRef["default"].x = raylib::GetMouseX();
      listRef["default"].y = raylib::GetMouseY();
    }
  };
  
  struct MultipleType : public MiceManager::Type {
    std::shared_ptr<li::LibInput> m_li;
    std::thread m_miceThread;
    
    MultipleType(MiceManager::MouseList& list) :
      Type(list),
      m_li{li::LibInput::MakeFromUDev()} {
      m_li->onDeviceAdded = [this](li::DeviceEvent ev) {
        if(ev.type == ev.kPointer_Type)
          listRef[ev.sysname] = {};
      };
      m_li->onDeviceRemoved = [this](li::DeviceEvent ev) {
        if(listRef.contains(ev.sysname))
          listRef.erase(ev.sysname);
      };
      m_li->onPointerMotion = [this](li::PointerMotionEvent ev) {
        if(listRef.contains(ev.sysname)) {

          listRef[ev.sysname].x += ev.x;
          listRef[ev.sysname].y += ev.y;
        }
      };

      m_miceThread = std::thread([this] {
        m_li->startWaitEvents();
      });
    }

    ~MultipleType() {
      m_li->stopWaitEvents();
      m_miceThread.join();
    }

    virtual void update() override {}
  };

  MiceManager::MiceManager() :
    m_type{new SingleType(m_mice)},
    m_multiple{} {}
  MiceManager::~MiceManager() {}

  void MiceManager::enableMultipleMouse() {
    if(!m_multiple) {
      m_multiple = true;
      m_type.reset(new MultipleType(m_mice));
    }
  }

  void MiceManager::disableMultipleMouse() {
    if(m_multiple) {
      m_multiple = false;
      m_type.reset(new SingleType(m_mice));
    }
  }

  void MiceManager::update() {
    m_type->update();
  }

  MiceManager& MiceManager::GetInstance() {
    static MiceManager s_mgr;
    return s_mgr;
  }
} // namespace engine