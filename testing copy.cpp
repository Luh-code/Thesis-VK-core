#include <iostream>
#include <typeinfo>

typedef struct TestStr {
    static const size_t size = 3;
    float a = 10.0f;
    int b = 1337;
    int c = 420;
} TestStr;

template<typename T, typename Arg, typename... Args>
    void unpack (T _s)
{
    if (_s->size>0)
    {
        int pos = 0;
        unpack<T, Arg, Args...>(_s, *(reinterpret_cast<Arg*>(_s)), pos);
    }
}
//template<typename T>
//    void unpack (T _s, int _pos) {return;}
template<typename T, typename Arg, typename... Args>
    void unpack (T _s, Arg _a, int pos)
{
    const std::type_info& ti = typeid(_a);
    std::cout<<ti.name()<<" ";
    std::cout<<static_cast<Arg>(_a)<<std::endl;
    pos++;
    if (!(_s->size>pos)) return;
    unpack<T, Args...>(_s, *(reinterpret_cast<Arg*>(_s+pos)), pos);
    //std::cout<<static_cast<decltype(_a)>(a)
}

/*template<typename T, typename Arg>
    void unpack (T _s, Arg _a, int pos)
{
    const std::type_info& ti = typeid(_a);
    std::cout<<ti.name()<<" ";
    std::cout<<static_cast<Arg>(_a)<<std::endl;
    //pos++;
    //if (!(_s->size>pos)) return;
    //unpack<T, Args...>(_s, *(reinterpret_cast<Arg*>(_s+pos)), pos);
    //std::cout<<static_cast<decltype(_a)>(a)
}*/

template<typename T, typename... Args>
    void testF (T _s)
{
    unpack<T, Args...>(_s);
    //const std::type_info& ti1 = typeid(Args[1]));
    //std::cout<<ti1.name()<<std::endl;
    //unpack(&_s, &(Args...));
}

int main()
{
    TestStr t;
    //int* pt = reinterpret_cast<int*>(&t.a);
    //pt += 0;//(sizeof(t)/t.size)*1;
    std::cout<<sizeof(t)<<std::endl;
    testF<TestStr*, float, int, int>(&t);
    //std::cout<<sizeof(pt)<<std::endl;
    //std::cout<<static_cast<float>(*pt)<<std::endl;
    
    return 0;
}