
#include "header.h"

int main()
{
    Library library;
    int n;
    std::cout<<"input books title, author, isbn /n";
    for(int i=0;i<3;++i)
    {
        library.addbook();
    }
    library.listlibrary();
    library.borrowbook();
    library.returnbook();
    return 0;
}