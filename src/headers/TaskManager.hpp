#pragma once

#include "interfaces/ITaskManager.hpp"
#include <iostream>
#include <fstream>
#include <chrono>
#include <thread>
#include <algorithm>
#include <nlohmann/json.hpp>

class TaskManager : public ITaskManager {
public:
  TaskManager(const std::string& filename = "")
    : m_filename{filename}
    , m_file{filename, std::ios::in | std::ios::out | std::ios::app}
    , m_isRunning{true}
  {}

  TaskManager(const TaskManager& other)             = delete;
  TaskManager(TaskManager&& other)                  = delete;
  TaskManager& operator=(const TaskManager& other)  = delete;
  TaskManager& operator=(TaskManager&& other)       = delete;
  ~TaskManager()                                    = default;

  void start()          override;
  void add()            override;
  void remove()         override;
  void edit()           override;
  void printAllTasks()  override;
  void setTaskStatus()  override;

private:
  void mainMenu(const std::string& command);
  std::string toLowerCase(const std::string& str);

private:
  std::string m_filename;
  std::fstream m_file;
  bool m_isRunning;
  nlohmann::json m_tasksArray = nlohmann::json::array();
};
