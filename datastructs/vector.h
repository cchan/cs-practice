#pragma once
#include <cstdlib>
#include <stdexcept>
#include <iostream>

template <typename T>
class vector{
private:
  T* data;
  size_t data_size = 0;
  size_t reserved_size = 0;
  size_t ceil_pow_2(size_t) const;
public:
  vector();
  ~vector();
  vector(size_t);
  T operator[](size_t) const;
  T& operator[](size_t);
  void reserve(size_t);
  void resize(size_t);
  void push_back(const T&);
  size_t size();
};

template <typename T>
vector<T>::vector(){
}

template <typename T>
vector<T>::~vector(){
  free(data);
}

template<typename T>
size_t vector<T>::ceil_pow_2(size_t s) const{
  if(!s)return 0;
  s--;
  size_t ceil = 1;
  while (s){
    s >>= 1;
    ceil <<= 1;
  }
  return ceil;
}

template <typename T>
vector<T>::vector(size_t s){
  data_size = s;
  reserved_size = ceil_pow_2(s);
  
  data = (T*)calloc(reserved_size, sizeof (T)); //new T[s];
  
  //initialize?
  
  if(data == nullptr)
    throw std::runtime_error("Failed to allocate memory");
}

template <typename T>
T vector<T>::operator[](size_t i) const{
  if(i >= data_size)
    throw std::range_error("Index out of range");
  return data[i];
}

template <typename T>
T& vector<T>::operator[](size_t i){
  if(i >= data_size)
    throw std::range_error("Index out of range");
  return data[i];
}

template <typename T>
void vector<T>::reserve(size_t s){
  if (s > reserved_size){
    data = (T*)realloc(data, s);
    if(data == nullptr)
      throw std::runtime_error("Failed to reallocate memory.");
    reserved_size = s;
  }
}

template <typename T>
void vector<T>::resize(size_t s){
  if (s > reserved_size){
    data = (T*)realloc(data, s);
    if(data == nullptr)
      throw std::runtime_error("Failed to reallocate memory.");
    reserved_size = s;
  }
}

template <typename T>
void vector<T>::push_back(const T& element){
  if (data_size >= reserved_size)
    reserve(data_size * 2);
  data[data_size++] = element;
}

template <typename T>
size_t vector<T>::size(){
  return data_size;
}
