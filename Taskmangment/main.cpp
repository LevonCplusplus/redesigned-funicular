#include <iostream>
#include <vector>
#include <string>
#include "User.h"
#include "task.h"
#include "taskmanager.h"

int main()
{
  Task* BITSET = new Task{};
  std::cin >> *BITSET;
  Task* BITSET2 = new Task{};
  std::cin >> *BITSET2;
  TaskManager Manager;
  Manager.registerUser("levon","varosyan");
  Manager.addtask(BITSET2);
  Manager.addtask(BITSET);
  Manager.addTaskForUser(1,BITSET);
  std::cout<<*BITSET;
  std::cout<<*BITSET2;

  return 0;
}
