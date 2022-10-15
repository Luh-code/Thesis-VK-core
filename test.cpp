
#include <iostream>
#include <map>
#include <typeinfo>
//#include <concepts>

#define CAST_TO_STRUCT(t) (reinterpret_cast<t>(base))
#define SOME_TYPE CAST_TO_STRUCT(const SomeType&) //(reinterpret_cast<const SomeType&>(base))

using namespace std;

struct SomeType
{
  int a, b;
};


class SomeClass
{
public:
  template<typename T>
    inline void operator[](T)
  {
    std::cout<<"Test\n"<<"Type: "<<typeid(T()).name()<<std::endl;
  }
};

const char base = 0;

int main()
{
  SomeClass sc0;
  sc0[SOME_TYPE];//.doSomeThing(); // Error
  std::cout<<"size: "<<sizeof(SOME_TYPE)<<std::endl;
}