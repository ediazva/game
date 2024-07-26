#include "engine/mice_manager.h"
#include <thread>
#include <chrono>
using namespace std::chrono;

int main() {
  auto& mgr = engine::MiceManager::GetInstance();
  std::this_thread::sleep_for(2s);
  puts("A");
  for(auto&& x : mgr.mice()) {
    puts("X");
  }

  return 0;
}