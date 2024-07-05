#include <csignal>
#include <iostream>
#include <thread>

#include "Meqdad.hpp"

namespace {

volatile std::sig_atomic_t RunningState = true;

}

void signalHandler(int signal) {
  if (signal == SIGINT) {
    std::cout << "SIGINT received. Stopping the program..." << std::endl;
    RunningState = false;
  }
}

void printUuidEvery5Seconds() {
  std::string uuid{Meqdad::uuid()};

  while (RunningState) {
    std::cout << Meqdad::timestamp() << ": " << uuid << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(5));
  }
}

int main() {
  std::signal(SIGINT, signalHandler);

  std::thread uuidThread{printUuidEvery5Seconds};

  uuidThread.join();
  return 0;
}
