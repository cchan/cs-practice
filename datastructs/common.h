#pragma once
#include <exception>

class bad_alloc_exception{
  virtual const char* what() const throw(){
    return "Failed to allocate memory.";
  }
} bad_alloc;

typedef unsigned int size_t;
