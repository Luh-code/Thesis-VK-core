#ifndef TVK_MODULAR_H
#define TVK_MODULAR_H

#include "pch.h"
#include "TVk-creation.h"

namespace TVk
{
    typedef struct TestStr {
        double a = 10.3;
        int b = 1337;
        float c = 420.5;
        char d = 'f';
    } TestStr;

    typedef char* _Adress;
    typedef std::vector<_Adress> _StructData;

    template<typename T, typename Arg, typename... Args>
        void _extractStruct (_StructData& _data, T* _s, bool _print)
    {
        if (sizeof(*_s)>0)
        {
            int pos = 0;
            _extractStruct<T, Arg, Args...>(_data, _s, (reinterpret_cast<char*>(_s)), pos, _print);
        }
    }
    template<typename T, typename Arg, typename... Args>
        void _extractStruct (_StructData& _data, T* _s, char* _a, int _pos, bool _print)
    {
        if (_print) Debug(*reinterpret_cast<Arg*>(_a)); // TODO: Move this to a sepereate variadic unpack
        _data.push_back(reinterpret_cast<_Adress>(_a));
        _pos+=sizeof(Arg);
        if (!(sizeof(*_s)>_pos)) return;
        _extractStruct<T, Args...>(_data, _s, (reinterpret_cast<char*>(_s)+_pos), _pos, _print); // TODO: Change _pos to count iterations not byte offset
    }

    template<typename T>
        void _extractStruct (_StructData& _sd, T* _s, char* _a, int _pos, bool _print) {}

    template<typename... Args, typename T>
        _StructData& extractStruct (T* _s, bool _print)
    {
        _StructData* _sd = new _StructData();
        _extractStruct<T, Args...>(*_sd, _s, _print);
        return *_sd;
    }


    template<typename T, typename Arg, typename... Args>
        void _modifyStruct (T* _s, _StructData& _sd)
    {
        int pos = 0;
        _modifyStruct<T, Arg, Args...>(_s, _sd, (reinterpret_cast<char*>(_s)), pos);
    }
    template<typename T, typename Arg, typename... Args>
        void _modifyStruct (T* _s, _StructData& _sd, char* _a, int _pos)
    {
        *reinterpret_cast<Arg*>(_a)=*reinterpret_cast<Arg*>(_sd[_pos]);

        _pos++;
        if (!(_pos<_sd.size())) return; // ? replace with _pos<_sd.size()
        _modifyStruct<T, Args...>(_s, _sd, (reinterpret_cast<char*>(_a)+sizeof(Arg)), _pos);
    }

    template<typename T>
        void _modifyStruct (T* _s, _StructData& _sd, char* _a, int _pos) {}

    template<typename... Args, typename T>
        void modifyStruct (T* _s, _StructData& _sd)
    {
        _modifyStruct<T, Args...>(_s, _sd);
    }

    template<typename... Args, typename T>
        void modifyStruct (T* _s, FLAG _props, T* _ms)
    {
        _StructData& sd0 = extractStruct<Args...>(_s, false);
        _StructData& sd1 = extractStruct<Args...>(_ms, false);

        FLAG f = 0b1;
        for (uint32_t i = 0; i < sd0.size(); i++)
        {
            if (IS_FLAG_SET(_props, f))
                sd0[i]=sd1[i];
            f=f<<1;
        }

        modifyStruct<Args...>(_s, sd0);
    }
}

#endif // TVK_MODUALR_H