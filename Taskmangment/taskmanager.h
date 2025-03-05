 #ifndef TASKMANAGER
 #define TASKMANAGER
 #include <iostream>
 #include <vector>
 #include <string>
 #include <fstream>
 #include "User.h"
 #include "task.h"
class TaskManager{
    std::vector<User*> t_users;
    std::vector<Task*> t_tasks;
  public:
    TaskManager();
    TaskManager(const TaskManager& other);
    TaskManager(TaskManager&& other) noexcept;
    TaskManager& operator=(TaskManager && other) noexcept;
    ~TaskManager();
    void registerUser(const std::string& username, const std::string& password);
    bool login(const std::string& username, const std::string& password);
    void logout(const std::string&);
    //Task Management
    int generateuserid();
    void addtask(Task*);
    void addTaskForUser(int userid,Task*); 
    void deleteTaskForUser(const int taskid); 
    void editTaskForUser(int taskid, const Task& updatedTask);
    void displayTasksForUser(int user_id) const;
    void save(User* obj);
    void display();
  };
  #endif