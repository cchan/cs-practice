#ifndef HEAP_H
#define HEAP_H

// Implements a min heap

#include <functional>
#include <algorithm>
#include <iterator>
#include <vector>

template<typename T>
class heap{
  std::vector<T> _elements;
  std::function< int(T, T) > _comparator;
public:
  heap(const std::function< int(T, T) > & comparator) : _comparator(comparator) {};
  bool empty() const{
    return _elements.empty();
  }
  size_t size() const{
    return _elements.size();
  }
  const T& top() const{
    return _elements.front();
  }
  void push(const T& x){
    _elements.push_back(x);
    size_t curr = _elements.size();
    // (this is a min heap)
    while(curr > 1 && _comparator(_elements[curr - 1], _elements[curr/2 - 1]) < 0){
      std::iter_swap(_elements.begin() + curr - 1, _elements.begin() + curr/2 - 1);
      curr /= 2;
    }
  }
  void pop(){
    std::iter_swap(_elements.begin() + 1 - 1, _elements.begin() + _elements.size() - 1);
    _elements.pop_back();
    size_t curr = 1;
    size_t child;
    while(_elements.size() >= curr*2) {
      if(_elements.size() >= curr*2 + 1){
        if(_comparator(_elements[curr*2 - 1], _elements[curr*2 + 1 - 1]) < 0)
          child = curr * 2;
        else
          child = curr * 2 + 1;
      }
      else{
        child = curr * 2;
      }
      if(_comparator(_elements[curr - 1], _elements[child - 1]) > 0)
        std::iter_swap(_elements.begin() + curr - 1, _elements.begin() + child - 1);
      curr = child;
    }
  }
};

#endif // ! HEAP_H
