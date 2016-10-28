class bad_alloc_exception: public exception{
  virtual const char* what() const throw(){
    return "Bad allocation";
  }
} bad_alloc;

class vector<T>{
private:
  T* data;
  size_t data_size = 0;
  size_t real_size = 0;
public:
  vector(){}
  ~vector(){
    free(data);
  }
  vector(size_t s){
    data_size = s;
    
    size_t real_size = 2;
    while (s >>= 1) real_size <<= 1;
    
    data = calloc(sizeof(T) * s); //new T[s];
    
    for(int i = 0;
    
    if(data == nullptr)
      throw bad_alloc;
  }
  void reserve(size_t s){
    if (s > real_size){
      data = realloc(data, s);
      if(data == nullptr)
        throw bad_alloc;
      real_size = s;
    }
  }
  void push_back(const T& element){
    if (data_size >= real_size)
      reserve(data_size * 2);
    data[data_size++] = element;
  }
  size_t size(){
    return data_size;
  }
}
