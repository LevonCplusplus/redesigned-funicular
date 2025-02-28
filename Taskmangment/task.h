 #ifndef  TASK
 #define TASK
enum class Priority{Low=1,Medium,High};
enum class Status{Pending=1, InProgress, Completed};
class Task{
    int m_user_id;
    int m_task_id;
    std:: string m_title;
    std:: string m_description;
    std:: string m_deadline;
    std:: string m_category;
    Priority m_priority;
    Status m_status;
    bool m_completed;
  public:
    Task();
    Task(const std::string& title, const std::string& description, const std::string& deadline, const std::string& category, int priority,int status,bool completed);
    Task(const Task& other); 
    Task& operator=(const Task&); 
    Task(Task&& other) noexcept; 
    ~Task();
    int ganaratetaskid();
    int gettaskuserid()const;
    int getid()const;
    void markCompleted();
    void setstatus(int);
    void setprio(int);
    void setuserid(int);
    void  edit(const std::string& newTitle, const std::string& newDescription, const std::string& newDeadline, const std::string& newCategory, int newPriority, int newstatus, bool newcompleted);
    void displayTask() const;
    bool operator==(const Task & obj2);
    bool operator!=(const Task & obj2);
    Task& operator++();
    friend std::ostream&   operator<<(std::ostream & ost,const Task & obj);
    friend std::istream&   operator>>(std::istream & ost,Task & obj);
    const Task  operator++(int);
  };

#endif