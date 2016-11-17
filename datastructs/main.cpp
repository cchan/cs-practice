#include <iostream>
#include "vector.h"

int main(){
  vector<int> vec(5, 4);
  
  vec[0] = 3;
  vec[1] = 2;
  vec[3] = 1;
  
  for(size_t i = 0; i < vec.size(); i++)
    std::cout << i << ": " << vec[i] << std::endl;
}
