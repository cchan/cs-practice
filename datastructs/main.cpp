#include <iostream>
#include "vector.h"

int main(){
  //This doesn't work:
  //"Vector is implemented using internal pointers to the actual storage."
  //You can't allocate contiguous memory for a resizable vector.
  
  vector<vector<int> > vec(5, vector<int>(4,5));
  
  vec[0][0];
  return 0;
  vec[1][1] = 2;
  vec[3][3] = 1;
  
  for(size_t i = 0; i < vec.size(); i++){
    for(size_t j = 0; j < vec.size(); j++)
      std::cout << vec[i][j] << " ";
    std::cout << std::endl;
  }
}
