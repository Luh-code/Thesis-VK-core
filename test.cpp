
#include <iostream>
//#include <concepts>

using namespace std;

struct TestStr
{
  int a, b;  
};

//template<typename T>
//concept TestConcept = requires(T a)
//{
//    { hash<T>{}(a) } -> convertible_to<size_t>;
//};

template<class T>
void test (T)
{
    cout<<"Testfunc"<<std::endl;
}

int main()
{
    cout<<"Hello World\n";

    TestStr t1 = {1, 2};
    test(TestStr());
    
    return 0;
}
