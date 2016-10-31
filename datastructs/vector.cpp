#include "vector.h"
#include <cstdlib>
#include <stdexcept>
#include <iostream>

template <typename T>
vector<T>::vector(){
}

template <typename T>
vector<T>::~vector(){
  free(data);
}

size_t ceil_pow_2(size_t s){
  size_t ceil = 2;
  while (s & 1){
    s >>= 1;
    ceil <<= 1;
  }
  return ceil;
}

template <typename T>
vector<T>::vector(size_t s){
  data_size = s;
  real_size = ceil_pow_2(s);
  
  std::cout << "data: " << data_size << " real: " << real_size << std::endl;
  std::cout.flush();
  
  return;
  
  data = (T*)calloc(real_size, sizeof (T)); //new T[s];
  
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
  if (s > real_size){
    data = (T*)realloc(data, s);
    if(data == nullptr)
      throw std::runtime_error("Failed to reallocate memory.");
    real_size = s;
  }
}

template <typename T>
void vector<T>::resize(size_t s){
  if (s > real_size){
    data = (T*)realloc(data, s);
    if(data == nullptr)
      throw std::runtime_error("Failed to reallocate memory.");
    real_size = s;
  }
}

template <typename T>
void vector<T>::push_back(const T& element){
  if (data_size >= real_size)
    reserve(data_size * 2);
  data[data_size++] = element;
}

template <typename T>
size_t vector<T>::size(){
  return data_size;
}
