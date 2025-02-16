#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
template <class T>
class Vector{
    T * m_data;
    size_t m_size;
    size_t m_capacity;
    void reallocate(size_t capacity);
public:
  Vector();
  Vector(const Vector &);
  ~Vector();
  T& at (size_t index);
  void push_back(T &);
  void pop_back();
  size_t get_Size();
  size_t get_Cap();
  void resize(size_t size);
  void reserve(size_t capacity);
  T front()const;
  T back()const;
  bool is_empty()const;
  void shrink_to_fit(); 
  void insert(size_t index,T & value);
  void erase(size_t index); 
  void clear();
  };
#include "vecfunc.tpp"
#endif
