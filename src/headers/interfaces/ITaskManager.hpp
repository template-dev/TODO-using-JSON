#pragma once

#include <string>

class ITaskManager {
public:
  virtual ~ITaskManager() = default;
  virtual void start() = 0;
  virtual void add() = 0;
  virtual void remove(const std::string& title) = 0;
  virtual void edit(const std::string& title) = 0;
  virtual void printAllTasks() = 0;
  virtual void setTaskStatus(const std::string& title) = 0;
};
