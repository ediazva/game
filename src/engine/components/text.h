#pragma once
#include "engine/components/component.h"
#include "raylib.h"

namespace engine {
  // TODO: Font type?
  struct TextComponent : public Component {
    std::string str{};
    ::Color color{ ::BLACK };
    int fontSize{ 50 };

    TextComponent() = default;
    TextComponent(const std::string& str, ::Color color, int fontSize) : str(str), color(color), fontSize(fontSize) {
    }
    // TextComponent(const std::string& str, ::Color& color, int fontSize) : str(str), color(color), fontSize(fontSize) {
    // }
  };
} // namespace engine
