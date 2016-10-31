#pragma once
#include "common.h"

template <typename T>
class vector{
private:
  T* data;
  size_t data_size = 0;
  size_t real_size = 0;
public:
  vector();
  ~vector();
  vector(size_t s);
  T& operator[](size_t i);
  void reserve(size_t s);
  void push_back(const T& element);
  size_t size();
};
