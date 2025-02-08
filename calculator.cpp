#include "calcheader.h"

int main()
{

    std::cout<<"select a shape:\n1. Circle\n2. Rectangle\n3. Triangle\n4. Square"<<std::endl;
    unsigned int shape1;
    std::cin>>shape1;
    if(shape1 > square)
    {
        return 0;
        //exit(1);
    }
    if(shape1 == circle)
    {
        int r;
        std::cin>>r;
        std::cout<<area(r);
    }
    else if(shape1 == rectangle)
    {
        int height;
        int width;
        std::cin >> height >> width;
        std::cout << area(width,height,'r');   
    }
    else {
        int side;
        std::cin>>side;
        std::cout<<area(side);
    }
    return 0; 
}