#include <iostream>
#include <vector>
#include <string>
#include "User.h"
#include "task.h"
#include "taskmanager.h"
TaskManager:: TaskManager():t_users(0),t_tasks(0){}
  
TaskManager:: TaskManager(const TaskManager& other){

    t_users = other.t_users;
    t_tasks = other.t_tasks;
}

TaskManager:: TaskManager(TaskManager && other) noexcept {

    t_users = std::move(other.t_users);
    t_tasks = std::move(other.t_tasks);
}

TaskManager::~TaskManager(){
    for(int i = 0;i < t_users.size();++i)
    {
        delete t_users[i];
    }
}

void TaskManager:: registerUser(const std::string& username, const std::string& password){
   User* u=(new User(ganarateuserid(),username,password));
    t_users.push_back(u);

}
int TaskManager:: ganarateuserid()
{ 
    static int a = 1;
    return a++;
}
bool TaskManager:: login(const std::string& username, const std::string& password){
   for(int i = 0; i < t_users.size() ; ++i )
   {
      if( ( t_users[i] -> correctUsername(username) ) && ( t_users[i] -> correctPassword(password) ) )
      {
          t_users[i]->login();
          std:: cout<< "user logged in succesfully"<<std::endl;
          return true;
      }
   }
   std::cout << "no such a user"<< std::endl;
   return false;
}  
    
void TaskManager:: logout(const std::string& username)
{

    for(int i = 0; i < t_users.size(); ++i)
    {
        if( t_users[i]->correctUsername(username))
        {
            t_users[i]->logout();
            std:: cout<< "user logged  out succesfully"<<std::endl;
            return;
        }
    }
    std::cout << "no such a user"<< std::endl;

}
void TaskManager:: addtask( Task * t){
    if(!t)
    {
        exit(-1);
    }
   t_tasks.push_back(t);
}

void TaskManager:: addTaskForUser(const int userid,Task* t){
    if(!t)
    {
        exit(-1);
    } 

    for(int i = 0;i < t_users.size(); ++i)
     {
        if(userid == t_users[i]->getuserid())
        {
            t_users[i]->addTask(t);
            addtask(t);
            return;
        }
     }
     std::cout<<"no such a user"<<std::endl;
}

void  TaskManager :: deleteTaskForUser(const int taskid){
    
    for(int i = 0;i < t_users.size(); ++i)
    {
        Task * t = t_users[i]->searchtask(taskid);
        if( t )
        {
            t_users[i]->deletetask(taskid);
            break;

        }

    }
    
} 

void TaskManager:: editTaskForUser(int taskid, const Task& updatedTask)
{
    for(int i = 0;i < t_users.size(); ++i)
    {
        Task * t = t_users[i]->searchtask(taskid);
        if(t)
        {
            (*t) = updatedTask;
        }
    }
}

void TaskManager:: displayTasksForUser(int userid) const{
    for(int i = 0; i < t_users.size(); ++i)
    {
        if( t_users[i]->getuserid() == userid )
        {
           t_users[i]->listTasks();;
        }
    }
}