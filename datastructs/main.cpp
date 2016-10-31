#include <iostream>
#include "vector.h"

int main(){
  vector<int> vec(4);
  
  vec[0] = 3;
  vec[1] = 2;
  vec[2] = 1;
  vec[3] = 5;
  
  for(int i = 0; i < vec.size(); i++)
    std::cout << i << ": " << vec[i] << std::endl;
}
