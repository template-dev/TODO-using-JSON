#pragma once

#include <string>

class ITaskManager {
public:
  virtual ~ITaskManager()       = default;
  virtual void start()          = 0;
  virtual void add()            = 0;
  virtual void remove()         = 0;
  virtual void edit()           = 0;
  virtual void printAllTasks()  = 0;
  virtual void setTaskStatus()  = 0;
};
