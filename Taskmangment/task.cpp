#include <iostream>
#include <vector>
#include <string>
#include "task.h"
Task::Task():m_user_id(0),m_task_id(generatetaskid()),m_title(""),m_description(""),m_deadline(""),m_category(""),m_priority(Priority::Low),m_status(Status::Pending),m_completed(false){}

Task::Task(const std::string& title, const std::string& description, const std::string& deadline, const std::string& category,const int priority,const int status,bool completed){
    
    m_user_id = 0;
    m_task_id = generatetaskid();
    m_title = title;
    m_description = description;
    m_deadline = deadline;
    m_category = category;
    m_priority = static_cast<Priority> (priority);
    m_status = static_cast<Status> (status);
    m_completed = completed;

}
int Task:: generatetaskid()
{
    static int taskid = 100;
    return taskid++;
}
void Task:: setuserid(int p)
{
    m_user_id = p;
}

Task:: Task(const Task& other):Task(other.m_title,other.m_description,other.m_deadline,other.m_category,static_cast<int>(other.m_priority),static_cast<int>(other.m_status),other.m_completed)
{
    if(this == &other)
    {
        exit(-1);
    }
    m_user_id = other.m_user_id;
    m_task_id = other.m_task_id;
}


Task:: Task(Task&& other) noexcept{
     
    m_user_id = other.m_user_id;
    m_task_id = other.m_task_id;
    m_completed = other.m_completed;
    
    other.m_user_id = 0;
    other.m_task_id = 0;
    other.m_completed = false;

    m_title = std::move(other.m_title);
    m_description = std::move(other.m_description);
    m_deadline = std::move(other.m_deadline);
    m_category = std::move(other.m_category);
    m_priority = std::move(other.m_priority);
    m_status = std::move(other.m_status);
    
}
Task& Task:: operator=(Task&& other) noexcept{
    if(&other == this)
    {
        exit(-1);
    }
    m_user_id = other.m_user_id;
    m_task_id = other.m_task_id;
    m_completed = other.m_completed;
    
    other.m_user_id = 0;
    other.m_task_id = 0;
    other.m_completed = false;

    m_title = std::move(other.m_title);
    m_description = std::move(other.m_description);
    m_deadline = std::move(other.m_deadline);
    m_category = std::move(other.m_category);
    m_priority = std::move(other.m_priority);
    m_status = std::move(other.m_status);
    
    return *this;
}
    
    
Task& Task:: operator=(const Task & other){
    
    if(&other == this)
    {
        exit(-1);
    }
    Task T (other);
    std::swap(*this,T);
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

    if(a > 3 || a < 0)
    {
        exit(-1);
    }
    m_status = static_cast<Status>(a);
}
void Task:: setprio(int p){
    
    if(p > 3 || p < 0)
    {
        exit(-1);
    }
    m_priority = static_cast<Priority>(p);
}
void Task:: displayTask() const{
     
    std::cout<<"Title ="<<m_title<<"\nDescription ="<<m_description<<"\nCategory ="<<m_category<<"\nDeadline ="<<m_deadline<<std::endl;

}
Task::~Task()
  {}

//operator overloading
bool Task:: operator==(const Task & obj2)const
{
    return (m_task_id == obj2.m_task_id);
}
bool Task:: operator!=(const Task & obj2)const
{
    return (m_task_id != obj2.m_task_id);
}
Task& Task:: operator++()
{
    if(static_cast<int>(m_priority) == 3){
        return *this;
    }
    m_priority = static_cast <Priority>(static_cast <int>(m_priority)+1);
    return *this;
}
const Task Task:: operator++(int)
{
    if(static_cast<int>(m_priority) == 3){
        return *this;
    }
   Task t = *this;
   m_priority = static_cast <Priority>(static_cast <int>(m_priority)+1);
   return t; 
}

std::ostream& operator<<(std::ostream &ost, const Task &obj)
{
    ost << "USER " << obj.m_user_id 
        << "\n TASKID " << obj.m_task_id
        << "\n TITLE " << obj.m_title 
        << "\n DESCRIPTION " << obj.m_description
        << "\n DEADLINE " << obj.m_deadline
        << "\n CATEGORY " << obj.m_category
        << "\n PRIORITY " << static_cast<int>(obj.m_priority)
        << "\n STATUS " << static_cast<int>(obj.m_status)
        << "\n COMPLETE " << obj.m_completed << std::endl;
    return ost;
}
std::istream&   operator>>(std::istream & ist,Task & obj){
    std::cout<<"input Title ";
    ist >> obj.m_title; 
    std::cout<<"\n input DESCRIPTION ";
    ist >> obj.m_description;
    std::cout<< "\n input DEADLINE ";
    ist >> obj.m_deadline;
    std::cout<< "\n input CATEGORY ";
    ist >> obj.m_category;

  return ist;   
}
bool Task:: operator>(const Task& other)const
{
  return static_cast<int>(m_priority)  >  static_cast<int>(other.m_priority);
}
bool Task:: operator<(const Task& other)const
{
  return static_cast<int>(m_priority)  <  static_cast<int>(other.m_priority);
}
Task& Task:: operator--(){//prefix
    if(static_cast<int>(m_status) == 1){
        return *this;
     }
   m_status = static_cast<Status> ( static_cast<int>(m_status)-1 );
   return *this;
}
const Task Task:: operator--(int)
{
    if(static_cast<int>(m_status) == 1){
       return *this;
    }
    Task t=(*this);
    m_status = static_cast<Status> ( static_cast<int>(m_status)-1 );
    return t;   
}