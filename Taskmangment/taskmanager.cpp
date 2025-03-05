#include <iostream>
#include <vector>
#include <string>
#include "User.h"
#include "task.h"
#include "taskmanager.h"
TaskManager:: TaskManager():t_users(0),t_tasks(0){}
  
// TaskManager:: TaskManager(const TaskManager& other){
    
//     t_users = other.t_users;
//     t_tasks = other.t_tasks;
// }

TaskManager:: TaskManager(TaskManager && other) noexcept {

    t_users = std::move(other.t_users);
    t_tasks = std::move(other.t_tasks);
}
TaskManager& TaskManager::operator=(TaskManager && other) noexcept {
    if(this == &other)
    {
        exit(-1);
    }
    t_users = std::move(other.t_users);
    t_tasks = std::move(other.t_tasks);
    return *this;
}
TaskManager::~TaskManager(){
    for(int i = 0;i < t_users.size();++i)
    {
        delete [] t_users[i];
    }
    for(int i = 0;i < t_tasks.size();++i)
    {
        delete [] t_tasks[i];
    }
}

void TaskManager:: registerUser(const std::string& username, const std::string& password){
   User* u=(new User(generateuserid(),username,password));
    t_users.push_back(u);
    
}
int TaskManager:: generateuserid()
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
   std::cout<< "task added"<<std::endl;
    for(int i = 0; i < t_users.size(); ++i)
     {
        if(userid == t_users[i]->getuserid())
        {

            t_users[i] -> addTask(t);
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
            t_users[i]-> deletetask(taskid);
            break;

        }
    }
   std::cout<<"no such a task"<<std::endl;
    
} 

void TaskManager:: editTaskForUser(int taskid, const Task& updatedTask)
{
    for(int i = 0;i < t_users.size(); ++i)
    {
        Task * t = t_users[i] -> searchtask(taskid);
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
// void TaskManager::save(User* obj) {
//     std::ofstream fout("shadow.txt", std::ios::binary | std::ios::app); 
//     if (fout.is_open()) {
//         fout.write(reinterpret_cast<char*>(obj), sizeof(User)); 
//         fout.close();
//     } else {
//         std::cout << "Error opening file for writing." << std::endl;
//     }
//     std::cout << "Data saved." << std::endl;
// }

// void TaskManager::display() {
//     std::ifstream fin("shadow.txt", std::ios::binary);
//     if (fin.is_open()) {
//         User* u = new User{} ;
//         while (fin.read(reinterpret_cast<char*>(u), sizeof(*u))){
//             //fin.read(reinterpret_cast<char*>(&u), sizeof(u));  
//             u->listTasks();  
//         }
//         fin.close();
//     } else {
//         std::cout << "Error opening file for reading." << std::endl;
//     }
// }