#pragma once

#include "interfaces/ITaskManager.hpp"
#include <iostream>
#include <string>
#include <fstream>

class TaskManager : public ITaskManager {
public:
  TaskManager(const std::string& filename = "")
    : m_filename{filename}
    , m_command{""}
    , m_file{filename, std::ios::in | std::ios::out | std::ios::app}
    , m_isExit{false}
  {}
  ~TaskManager();

  void start()          override;
  void add()            override;
  void remove()         override;
  void edit()           override;
  void printAllTasks()  override;
  void completeTask()   override;

private:
  std::string m_filename;
  std::string m_command;
  std::fstream m_file;
  bool m_isExit;
};
