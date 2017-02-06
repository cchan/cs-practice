#pragma once
#include <cstdlib>
#include <stdexcept>
#include <iostream>

/*
A vector implementation using C++ template features 
as well as C-style realloc() et al.

The usual amortized-constant-insertion kind of features.
*/

template <typename T>
class vector{
private:
  T* data;
  size_t data_size = 0;
  size_t reserved_size = 0;
public:
  static size_t ceil_pow_2(size_t);
  vector();
  ~vector();
  vector(const vector<T>&);
  vector(size_t);
  vector(size_t, const T&);
  T operator[](size_t) const;
  T& operator[](size_t);
  void reserve(size_t);
  void resize(size_t);
  void push_back(const T&);
  size_t size() const;
};

template <typename T>
std::ostream& operator<<(std::ostream& out, const vector<T>& vec);



template<typename T>
size_t vector<T>::ceil_pow_2(size_t s){
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
vector<T>::vector(){
}

template <typename T>
vector<T>::~vector(){
  for(size_t i = 0; i < data_size; i++)
    data[i].~T();
  free(data);
}

template <typename T>
vector<T>::vector(const vector<T>& other){
  data_size = other.data_size;
  reserved_size = other.reserved_size;
  
  data = (T*)malloc(reserved_size * sizeof (T));
  
  if(data == nullptr)
    throw std::runtime_error("Failed to allocate memory");
  
  for(size_t i = 0; i < data_size; i++)
    data[i] = T(other[i]);
}

template <typename T>
vector<T>::vector(size_t s){
  data_size = s;
  reserved_size = ceil_pow_2(s);
  
  data = (T*)malloc(reserved_size * sizeof (T)); //new T[s];
  
  if(data == nullptr)
    throw std::runtime_error("Failed to allocate memory");
  
  for(size_t i = 0; i < s; i++)
    data[i] = T();
}

template <typename T>
vector<T>::vector(size_t s, const T& fill){
  data_size = s;
  reserved_size = ceil_pow_2(s);
  
  data = (T*)malloc(reserved_size * sizeof (T)); //new T[s];
  
  if(data == nullptr)
    throw std::runtime_error("Failed to allocate memory");
  
  for(size_t i = 0; i < s; i++)
    data[i] = T(fill);
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
    s = ceil_pow_2(s);
    
    T* new_data = (T*)realloc(data, s * sizeof (T));
    
    if(new_data == nullptr)
      throw std::runtime_error("Failed to reallocate memory.");
    
    data = new_data;
    reserved_size = s;
  }
}

template <typename T>
void vector<T>::resize(size_t s){
  reserve(s);
  while(data_size < s)
    data[data_size++] = T();
}

template <typename T>
void vector<T>::push_back(const T& element){
  reserve(data_size + 1);
  data[data_size++] = element;
}

template <typename T>
size_t vector<T>::size() const{
  return data_size;
}

template <typename T>
std::ostream& operator<<(std::ostream& out, const vector<T>& vec){
  out << '[';
  if(vec[0])
    out << vec[0];
  for(size_t i = 1; i < vec.size(); i++)
    out << ',' << vec[i];
  out << ']';
  return out;
}
