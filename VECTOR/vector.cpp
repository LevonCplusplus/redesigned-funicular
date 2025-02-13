#include "vector.h"
int main()
{
    Vector vec;
    for(int i=0;i<10;++i)
    {
      int n;
      std::cin>>n;
      vec.push_back(n);
    }
    vec.insert(7,27);
   for(int i=0;i<vec.get_Size();++i)
    std::cout<< vec.at(i);

    return 0; 
}
