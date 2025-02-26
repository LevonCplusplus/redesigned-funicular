#include "vector.h"
Vector::Vector():m_size(0),m_capacity(5){
  m_data=new int [m_capacity];
};
Vector::~Vector(){
  delete[] m_data;
}
Vector::Vector(const Vector & vec)
{
    m_size=vec.m_size;
    m_capacity=vec.m_capacity;
    m_data=new int[vec.m_capacity];
    for(int i=0;i<vec.m_size;++i)
    {
        m_data[i]=vec.m_data[i];
    }
}
int Vector::at (size_t index)const{
    if( index < 0 || index >= m_size )
      exit(-1);
 return m_data[index];   
}
void Vector::reallocate(size_t capacity)
{
    int *p=new int[capacity];
    /*if(!p)
    {
        exit(-1);
    }*/
    for(int i=0;i<m_size;++i)
    {
        p[i]=m_data[i];
    }
    delete[]m_data;
    m_data=p;
    p=nullptr;
    m_capacity=capacity;
}
void Vector::push_back(int val){
  if(m_size == m_capacity)
  {
     reallocate(2 * m_capacity);
  }
  m_data[m_size] = val;
  ++ m_size;
}

void Vector::pop_back(){
   --m_size;
}
size_t Vector:: get_Size(){
   return m_size;
}
size_t Vector:: get_Cap(){
    return m_capacity;
}
void Vector:: resize(size_t size){
    m_size=size;
}
void Vector:: reserve(size_t capacity){
 reallocate(capacity);
}
int Vector:: front()const{
   return m_data[0];
}
int Vector:: back()const{
   return m_data[m_size-1];
}
bool Vector:: is_empty()const{
   if(!m_size){
     return true;
   }
 return false;
}
void Vector:: shrink_to_fit(){
    reallocate(m_size);
} 
void Vector:: insert(size_t index,int value){
      if(m_size == m_capacity)
      {
         reallocate(m_capacity*2);
      }
	for(int i=m_size-1;i>=index;--i)
      {
        m_data[i+1]=m_data[i];
      }
      m_data[index]=value;
      m_size++;
}
void Vector:: erase(size_t index){
 for(int i=index;i<m_size-1;++i)
 {
     m_data[i]=m_data[i+1];
 }   
} 
void Vector:: clear(){
    m_size=0;
}
