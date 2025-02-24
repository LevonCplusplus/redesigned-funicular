#include <iostream>
#include <vector>
#include <string>
#include "User.h"
#include "task.h"
#include "taskmanager.h"

int main()
{
  Task BITSET("BItset", "description", "21.06","category",3,2,false);
  Task BITSET2("BItset1", "description1", "21.061","category1",1,3,false);

  TaskManager poxos;
  poxos.registerUser("levon","varosyan");
  poxos.addtask(&BITSET2);
  poxos.addtask(&BITSET);
  poxos.addTaskForUser(4251637849,&BITSET);
  poxos.displayTasksForUser(4251637849);
  return 0;
}
