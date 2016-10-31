#include "vector.h"
#include <cstdlib>

template <typename T>
vector<T>::vector(){
}

template <typename T>
vector<T>::~vector(){
  free(data);
}

template <typename T>
vector<T>::vector(size_t s){
  data_size = s;
  
  size_t real_size = 2;
  while (s >>= 1) real_size <<= 1;
  
  data = calloc(s, sizeof (T)); //new T[s];
  
  //initialize?
  
  if(data == nullptr)
    throw bad_alloc;
}

template <typename T>
T& vector<T>::operator[](unsigned int i){
  return data[i];
}

template <typename T>
void vector<T>::reserve(size_t s){
  if (s > real_size){
    data = realloc(data, s);
    if(data == nullptr)
      throw bad_alloc;
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
