#include "headers/TaskManager.hpp"
#include <iostream>

int main(int argc, char* argv[]) {
  try {
    TaskManager taskManager("tasks.json");
    taskManager.start();
  }
  catch(const std::exception& ex) {
    std::cerr << ex.what() << std::endl;
  }
}
