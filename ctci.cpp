#include <iostream>
using namespace std;

// ALL CTCI PROBLEMS, IN C++.

namespace m1{ //That is, Moderate 1, or problem 16.1.
  void swap(int &x, int &y){
    x ^= y;
    y ^= x;
    x ^= y;
  }

  void main(){
    int x = 3, y = 4;
    cout << x << " " << y << endl;
    swap(x, y);
    cout << x << " " << y << endl;
  }
}

int main(){
  m1::main();
}
