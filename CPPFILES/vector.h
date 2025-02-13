#include <iostream>
class Vector{
    int* m_data;
    size_t m_size;
    size_t m_capacity;
    void reallocate(size_t capacity);
public:
  Vector();
  Vector(const Vector &);
  ~Vector();
  int at (size_t index)const;
  void push_back(int val);
  void pop_back();
  size_t get_Size();
  size_t get_Cap();
  void resize(size_t size);
  void reserve(size_t capacity);
  int front()const;
  int back()const;
  bool is_empty()const;
  void shrink_to_fit(); 
  void insert(size_t index,int value);
  void erase(size_t index); 
  void clear();
  };

