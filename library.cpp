
#include "header.h"

int main()
{
    Library library;
    int n;
    std::cin>>n;
    std::cout<<"input books title, author, isbn /n";
    for(int i=0;i<n;++i)
    {
        library.addbook();
    }
    library.listlibrary();
    library.borrowbook();
    library.returnbook();
    return 0;
}