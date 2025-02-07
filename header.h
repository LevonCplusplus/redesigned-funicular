#include <iostream>
#include <cstring> 
struct book
{
    char title[100];
    char author[100];
    char isbn[20];
    int available;
 book():available(0){};
 void createbook()
 {
    available=1;
    std::cout<<"title"<<std::endl;
    std::cin>>title>>author>>isbn;
 }
  
};
struct Library
{
private:
    book * arr;
    int capacity;
    int size;
public:
    Library():size(0),capacity(10)
    {
        arr=new book[10];
    }
    ~Library()
    {
        delete[] arr;
        arr=nullptr;
    }
    void listlibrary ()
    { 
        for(int i=0;i<size;++i)
        {
            std::cout<<arr[i].title<<" "<<arr[i].author<<std::endl;
        }
    }
    void search (char a[],char b[])
    {
        for(int i=0;i<size;++i)
        if(strcmp(a,arr[i].title)==0||strcmp(b,arr[i].author)==0)
        {
           std::cout<<arr[i].title<<arr[i].author<<arr[i].isbn;
        }
        
    }
    void addbook()
    {
        if(size==capacity)
        {
            book *arr1=new book[2*size];
            delete[] arr;
            arr=arr1;
            arr1=nullptr;
            capacity=2*size;
        }
        book k;
        k.createbook();
        arr[size]=k;
        size++;
    }
    void borrowbook()
    {
        char isbn1[20];
        std::cin>>isbn1;
        for(int i=0;i<size;++i)
        {
            if(strcmp(arr[i].isbn,isbn1)==0)
            {
                arr[i].available=0;
                return;
            }
        }
        std::cout<<"book is'nt availiable"<<std::endl;
    }
    void returnbook()
    {
       char isbn1[20];
       std::cin>>isbn1;
       for(int i=0;i<size;++i)
       {
         if(strcmp(arr[i].isbn,isbn1)==0)
         {
            arr[i].available=1;
            return ;
         }
       }
       std::cout<<"book was not borrowed"<<std::endl;

    }
};

