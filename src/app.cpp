#include "headers/TaskManager.hpp"
#include <iostream>

int main(int argc, char* argv[]) {
  TaskManager taskManager("tasks.json");
  taskManager.start();
}
