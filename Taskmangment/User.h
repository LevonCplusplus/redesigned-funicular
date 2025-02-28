 #ifndef USER
 #define USER
#include "task.h"
class User{
    int m_id;
    std::string m_username;
    std::string m_password;
    std::vector <Task*> m_tasks;
    bool m_is_loggedin;
public:
    User();
    User(int m_id,const std::string& username, const std::string& password);
    User& operator= (const User& other) = delete;
    User(const User& other) = delete;
    User(User && other);
    ~User();
    bool correctUsername(const std:: string&);
    void login();
    bool correctPassword(const std::string &);
    void logout();  
    User& operator=(User && other);
    void addTask(Task*);
    void deletetask(int);
    void editTask(Task* t, const Task& updatedtask);
    Task* searchtask(int);
    int getuserid()const;
    void listTasks() const;
};

#endif