#include "engine/mice_manager.h"

#include <li.h>
#include <thread>
#include <map>
#include <charconv>

#include <print>

namespace engine {
  bool EventCompare::operator()(const std::string& a, const std::string& b) const {
    int numA{}, numB{};
    std::from_chars(a.data()+sizeof("event"), a.data()+a.size(), numA);
    std::from_chars(b.data()+sizeof("event"), b.data()+b.size(), numB);

    return numA < numB;
  }

  struct MiceManager::Impl {
    std::map<std::string, Mouse, EventCompare>& m_mice;
    std::shared_ptr<li::LibInput> m_li;
    std::thread m_miceThread;
    
    Impl(auto& mice) :
      m_mice(mice),
      m_li{li::LibInput::MakeFromUDev()} {
      m_li->onDeviceAdded = [this](li::DeviceEvent ev) {
        if(ev.type == ev.kPointer_Type)
          m_mice[ev.sysname] = {};
      };
      m_li->onDeviceRemoved = [this](li::DeviceEvent ev) {
        if(m_mice.contains(ev.sysname))
          m_mice.erase(ev.sysname);
      };
      m_li->onPointerMotion = [this](li::PointerMotionEvent ev) {
        if(m_mice.contains(ev.sysname)) {

          m_mice[ev.sysname].x += ev.x;
          m_mice[ev.sysname].y += ev.y;
        }
      };

      m_miceThread = std::thread([this] {
        m_li->startWaitEvents();
      });
    }

    ~Impl() {
      m_li->stopWaitEvents();
      m_miceThread.join();
    }
  };

  MiceManager::MiceManager() :
    m_impl{new Impl(m_mice)} {}
  MiceManager::~MiceManager() {
    delete m_impl;
  }

  MiceManager& MiceManager::GetInstance() {
    static MiceManager s_mgr;
    return s_mgr;
  }
} // namespace engine