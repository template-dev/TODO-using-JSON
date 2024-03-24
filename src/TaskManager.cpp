#include "headers/TaskManager.hpp"

void TaskManager::start() {
  if(m_file.is_open()) {
    std::string command = "";

    m_file.seekg(0, std::ios::end);
    if (m_file.tellg() != 0) {
      m_file.seekg(0, std::ios::beg);
      m_tasksArray = nlohmann::json::parse(m_file);
    }
    m_file.close();

    do {
      system("cls");
      std::cout << "---[ MENU ]---" << std::endl
                << "1. Add task                \t(/add)" << std::endl
                << "2. Remove task             \t(/remove)" << std::endl
                << "3. Change the task status  \t(/setstatus)" << std::endl
                << "4. Edit task               \t(/edit)" << std::endl
                << "5. Print all tasks         \t(/print)" << std::endl
                << "Write the command '/exit' to exit" << std::endl;

      std::cout << "Enter your command, please: ";
      std::getline(std::cin, command);
      functional(command);
    } while(m_isRunning);
  }
  else {
    std::cerr << "The file couldn't be opened!\n";
  }
}

void TaskManager::functional(const std::string& command) {
  if(command != "/exit") {
    std::string title = "";
    std::string description = "";

    if(command == "/add") {
      std::cout << "Please enter a title: ";
      std::getline(std::cin, title);
      std::cout << "Please enter a description: ";
      std::getline(std::cin, description);
      add(title, description);
    }
    else if(command == "/remove") {
      std::cout << "Please enter a title: ";
      std::getline(std::cin, title);
      remove(title);
    }
    else if(command == "/setstatus") {
      bool status = false;
      std::cout << "Please enter a title: ";
      std::getline(std::cin, title);
      setTaskStatus(title);
    }
    else if(command == "/edit") {
      std::cout << "Please enter a title: ";
      std::getline(std::cin, title);
      edit(title);
    }
    else if(command == "/print") {
      printAllTasks();
      std::cin.get();
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
  }
  else {
    m_isRunning = false;
  }
}

void TaskManager::add(const std::string& title, const std::string& description) {
  m_file.open(m_filename);
  if(!title.empty()) {
    nlohmann::json newTask = {
      {"title", title},
      {"description", description},
      {"completed", false}
    };

    m_tasksArray.push_back(newTask);

    m_file.seekp(0);
    m_file << std::setw(4) << m_tasksArray << std::endl;
    m_file.flush();

    std::cout << "The data has been successfully recorded!" << std::endl;
    m_file.close();
  }
  else {
    std::cout << "You didn't enter the title!";
  }
}

void TaskManager::remove(const std::string& title) {
  auto removeIt = std::find_if(m_tasksArray.begin(), m_tasksArray.end(), [&title](const auto& task){
    return task["title"] == title;
  });

  if(removeIt != m_tasksArray.end()) {
    m_tasksArray.erase(removeIt);
    m_file.open(m_filename, std::ios::out | std::ios::trunc);
    m_file << std::setw(4) << m_tasksArray << std::endl;
    m_file.close();
    std::cout << "The " << title << " has been successfully removed!" << std::endl;
  }
  else {
    std::cout << "The " << title << " has not been deleted!" << std::endl;
  }
}

void TaskManager::edit(const std::string& title) {
  if(title.empty())
    return;

  m_file.open(m_filename, std::ios::out | std::ios::trunc);
  std::string newTitle = "";
  std::string newDescription = "";
  std::string answerForChange = "";

  for(auto& task : m_tasksArray) {
    if(task["title"] == title) {
      std::cout << "Do you want to change the title? (yes/no): ";
      std::getline(std::cin, answerForChange);
      answerForChange = toLowerCase(answerForChange);

      if(answerForChange == "yes") {
        std::cout << "Please enter a new title:" << std::endl;
        std::getline(std::cin, newTitle);
        task["title"] = newTitle;
      }

      std::cout << "Please enter a new description: ";
      std::getline(std::cin, newDescription);
      if(!newDescription.empty()) {
        task["description"] = newDescription;
      }

      std::cout << "You have successfully changed the status of the task!" << std::endl;
      break;
    }
  }
  m_file << std::setw(4) << m_tasksArray << std::endl;
  m_file.close();
}

void TaskManager::printAllTasks() {
  system("cls");
  std::cout << "\n---[ TASKS ]---\n";
  for (const auto& task : m_tasksArray) {
    std::cout << "Title: " << task["title"] << std::endl;
    std::cout << "Description: " << task["description"] << std::endl;
    std::cout << "Completed: " << task["completed"] << std::endl;
    std::cout << std::endl;
  }
  std::cout << "Press Enter to go to the menu...";
}

void TaskManager::setTaskStatus(const std::string& title) {
  m_file.open(m_filename, std::ios::out);
  std::string status = "";

  for(auto& task : m_tasksArray) {
    if(task["title"] == title) {
      std::cout << "Please enter the status of the task: ";
      std::getline(std::cin, status);
      task["completed"] = (status == "true") ? true : false;
      break;
    }
  }

  m_file << std::setw(4) << m_tasksArray << std::endl;
  m_file.close();
}

std::string TaskManager::toLowerCase(const std::string& str) {
  std::string result = str;
  std::transform(result.begin(), result.end(), result.begin(), ::tolower);
  return result;
}
