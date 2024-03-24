#include "headers/TaskManager.hpp"

void TaskManager::start() {
  if(m_file.is_open()) {
    do {
      system("cls");
      std::cout << "---[ MENU ]---" << std::endl
                << "1. Add task        \t(/add [title] [description])" << std::endl
                << "2. Remove task     \t(/remove [title])" << std::endl
                << "3. Completed task  \t(/completed [title])" << std::endl
                << "4. Edit task       \t(/edit [title] [description])" << std::endl
                << "5. Print all tasks \t(/print)" << std::endl
                << "Write the command '/exit' to exit" << std::endl;

      std::getline(std::cin, m_command);

      if(m_command == "/exit") break;
    } while(true);
  }
  else {
    std::cerr << "The file couldn't be opened!\n";
  }
}

void TaskManager::add() {

}

void TaskManager::remove() {

}

void TaskManager::edit() {

}

void TaskManager::printAllTasks() {

}

void TaskManager::completeTask() {

}

TaskManager::~TaskManager() {}
