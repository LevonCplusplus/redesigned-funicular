#include <iostream>
#include <vector>
#include <string>
#include "task.h"
Task::Task():m_user_id(0),m_task_id(ganaratetaskid()),m_title(""),m_description(""),m_deadline(""),m_category(""),m_priority(Priority::Low),m_status(Status::Pending),m_completed(false){}

Task::Task(const std::string& title, const std::string& description, const std::string& deadline, const std::string& category,const int priority,const int status,bool completed){
    m_user_id = 0;
    m_task_id = ganaratetaskid();
    m_title = title;
    m_description = description;
    m_deadline = deadline;
    m_category = category;
    m_priority =static_cast<Priority> (priority);
    m_status =static_cast<Status> (status);
    m_completed = completed;

}
int Task:: ganaratetaskid()
{
    static int taskid = 3546546376;
    return taskid++;
}
Task:: Task(const Task& other):Task(other.m_title,other.m_description,other.m_deadline,other.m_category,static_cast<int>(other.m_priority),static_cast<int>(other.m_status),other.m_completed)
{
    m_user_id = other.m_user_id;
    m_task_id = other.m_task_id;
}

Task:: Task(Task&& other) noexcept{
      
    m_user_id = other.m_user_id;
    m_task_id = other.m_task_id;
    m_title = std::move(other.m_title);
    m_description = std::move(other.m_description);
    m_deadline = std::move(other.m_deadline);
    m_category = std::move(other.m_category);
    m_priority = other.m_priority;
    m_status = other.m_status;
    m_completed = other.m_completed;

}
    
Task& Task:: operator=(const Task & other){
    m_user_id = other.m_user_id;
    m_task_id = other.m_task_id;
    m_title = other.m_title;
    m_description = other.m_description;
    m_deadline = other.m_deadline;
    m_category = other.m_category;
    m_priority = other.m_priority;
    m_status = other.m_status;
    m_completed = other.m_completed;
    return *this;
}   
int Task:: getid()const{
   
    return  m_task_id;
}
int Task:: gettaskuserid()const
{
    return m_user_id;
}

void Task:: markCompleted(){
      
    m_completed = true;

}
void Task:: edit(const std::string& newTitle, const std::string& newDescription, const std::string& newDeadline, const std::string& newCategory, int newPriority, int newstatus, bool newcompleted){
    
    m_title = newTitle;
    m_description = newDescription;
    m_deadline = newDeadline;
    m_category = newCategory;
    m_priority = static_cast<Priority> (newPriority);
    m_status = static_cast<Status> (newstatus);
    m_completed = newcompleted;
}
void Task:: setstatus(int a){

        m_status = static_cast<Status> (a);
}
void Task:: setprio(int p){
     
    m_priority = static_cast<Priority> (p);
}
void Task:: displayTask() const{
     
    std::cout<<"Title ="<<m_title<<"\nDescription ="<<m_description<<"\nCategory ="<<m_category<<"\nDeadline ="<<m_deadline<<std::endl;

}
Task::~Task()
  {}