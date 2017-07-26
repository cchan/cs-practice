#include <iostream>

template<typename T_retval, typename... T_param>
class Callable{
  typedef T_retval(*functype)(T_param...);
  functype f;
public:
  Callable(functype _f){
    f = _f;
  }
  T_retval operator()(T_param... parameter){
    return f(parameter...);
  }
};

template<typename T_retval, typename... T_param>
Callable<T_retval, T_param...> make_callable(T_retval(*func)(T_param...)){
  return Callable<T_retval, T_param...>(func);
}

long long product(int x, int y, int z){
  return (long long)x * (long long)y * (long long) z;
}

int main(){
  std::cout << make_callable(product)(5, 10, 3) << std::endl;
}
