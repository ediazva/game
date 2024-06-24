#include "engine/audio_system.h"

#include "engine/raylib.h"

namespace engine {
  AudioSystem::AudioSystem() {
    raylib::InitAudioDevice();
  }

  AudioSystem::~AudioSystem() {
    raylib::CloseAudioDevice();
  }
} // namespace engine