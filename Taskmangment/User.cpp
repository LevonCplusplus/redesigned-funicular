#include <iostream>
#include <vector>
#include <string>
#include "User.h"
#include "task.h"
User:: User():m_id(0),m_username(""),m_password(""),m_tasks(0),m_is_loggedin(false){}

User:: User(int id,const std::string& username, const std::string& password):User(){
  m_id = id;  
  m_username = username;
  m_password = password;
}

User:: User(User && other)//move constructor
{
    m_username = std::move(other.m_username);
    m_password = std::move(other.m_password);
    m_tasks = std::move(other.m_tasks);
    m_is_loggedin = other.m_is_loggedin;
    m_id = 0;
    m_is_loggedin = false;
}

User:: ~User(){
    for(int i = 0; i < m_tasks.size();++i )
    {
        delete m_tasks[i];
    }
}  
// {
//     if(m_id == other.m_id)
//     {
//        return *this;   
//     }
//     for(int i = 0; i < m_tasks.size();++i )
//     {
//         delete m_tasks[i];
//         m_tasks[i]= new Task( *(other.m_tasks[i]) );
//     }
//     return *this;
// } 
User& User:: operator=(User && other)
{
    m_id = other.m_id;
    m_username = std::move(other.m_username);
    m_password = std::move(other.m_password);
    m_tasks = std::move(other.m_tasks);
    m_is_loggedin = other.m_is_loggedin;
    m_id = 0;
    m_is_loggedin = false;
    return *this;
} 


bool User:: correctUsername(const std::string & username){
    return (m_username == username);
}

bool User:: correctPassword(const std:: string& password){
   
    return (password == m_password);
}

void User:: addTask( Task* k){
     if( k == nullptr)
     {
        exit(-1);
     }
     k->setuserid(m_id);
    m_tasks.push_back(k);
}

void User:: deletetask(int taskid)
{
    for(int i = 0; i < m_tasks.size(); ++i)
    {
      if(m_tasks[i]->getid() == taskid)
      {
        m_tasks.erase(m_tasks.begin()+i);    
        return;
      }
    }
}
void User:: editTask(Task * t, const Task& updatedtask){
    (*t) = updatedtask; 
}
Task* User:: searchtask(int taskid){

    for(int i = 0; i < m_tasks.size(); ++i)
    {for(int i = 0; i < m_tasks.size();++i )
        //     {
        //         delete m_tasks[i];
        if(m_tasks[i]->getid() == taskid)
        {
            return m_tasks[i];
        }
    }
    return nullptr;
}
void User:: login(){

    m_is_loggedin = true;
}
void User:: logout(){

    m_is_loggedin = false;
}
void User:: listTasks() const{
       
   for(int i = 0;i < m_tasks.size(); ++i)
   {
     m_tasks[i]->displayTask();
   }

}
int User:: getuserid()const{
    return m_id;
}

