#include <iostream>
#include <typeinfo>

typedef struct TestStr {
    double a = 10.3;
    int b = 1337;
    float c = 420.5;
    char d = 'f';
} TestStr;

template<typename T, typename Arg, typename... Args>
    void _unpack (T* _s)
{
    if (sizeof(*_s)>0)
    {
        int pos = 0;
        _unpack<T, Arg, Args...>(_s, (reinterpret_cast<char*>(_s)), pos);
    }
}
template<typename T, typename Arg, typename... Args>
    void _unpack (T* _s, char* _a, int _pos)
{
    const std::type_info& ti = typeid(Arg);
    std::cout<<ti.name()<<" ";
    std::cout<<*reinterpret_cast<Arg*>(_a)<<std::endl;
    _pos+=sizeof(Arg);
    if (!(sizeof(*_s)>_pos)) return;
    _unpack<T, Args...>(_s, (reinterpret_cast<char*>(_s)+_pos), _pos);
}

template<typename T>
    void _unpack (T* _s, char* _a, int _pos) {}

template<typename T, typename... Args>
    void unpack (T* _s)
{
    _unpack<T, Args...>(_s);
}

int main()
{
    TestStr t;
    std::cout<<sizeof(t)<<std::endl;
    unpack<TestStr, double, int, float, char>(&t);
    
    return 0;
}