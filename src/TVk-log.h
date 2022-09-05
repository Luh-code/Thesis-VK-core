#ifndef TVK_LOG_H
#define TVK_LOG_H

#include <sstream>

namespace TVkLog
{
    // * Variadic unpack

    static void variadic_unpack(std::string& buf) {}
    
    template<typename T, typename... Args>
        static void variadic_unpack(std::string& buf, const T arg, const Args... args)
    {
        std::ostringstream oss;
        oss << arg;
        buf.append(oss.str());
        
        variadic_unpack(buf, args...);
    }
    
    template<typename... Args>
        static void variadic_unpack(std::string& buf, void* arg, const Args... args)
    {
        std::ostringstream oss;
        oss << arg;
        buf.append(oss.str());
        variadic_unpack(buf, args...);
    }
    
    template<typename... Args>
        static void variadic_unpack(std::string& buf, char* arg, const Args... args)
    {
        buf.append(arg);
        variadic_unpack(buf, args...);
    }
    
    template<typename... Args>
        static void variadic_unpack(std::string& buf, const char* arg, const Args... args)
    {
        buf.append(arg);
        variadic_unpack(buf, args...);
    }
    
    template<typename... Args>
        static void variadic_unpack(std::string& buf, int arg, const Args... args)
    {
        buf.append(std::to_string(arg));
        variadic_unpack(buf, args...);
    }
    
    template<typename... Args>
        static void variadic_unpack(std::string& buf, unsigned arg, const Args... args)
    {
        buf.append(std::to_string(arg));
        variadic_unpack(buf, args...);
    }
    
    template<typename... Args>
        static void variadic_unpack(std::string& buf, long arg, const Args... args)
    {
        buf.append(std::to_string(arg));
        variadic_unpack(buf, args...);
    }
    
    template<typename... Args>
        static void variadic_unpack(std::string& buf, unsigned long arg, const Args... args)
    {
        buf.append(std::to_string(arg));
        variadic_unpack(buf, args...);
    }
    
    template<typename... Args>
        static void variadic_unpack(std::string& buf, long long arg, const Args... args)
    {
        buf.append(std::to_string(arg));
        variadic_unpack(buf, args...);
    }
    
    template<typename... Args>
        static void variadic_unpack(std::string& buf, unsigned long long arg, const Args... args)
    {
        buf.append(std::to_string(arg));
        variadic_unpack(buf, args...);
    }
    
    template<typename... Args>
        static void variadic_unpack(std::string& buf, float arg, const Args... args)
    {
        buf.append(std::to_string(arg));
        variadic_unpack(buf, args...);
    }
    
    template<typename... Args>
        static void variadic_unpack(std::string& buf, double arg, const Args... args)
    {
        buf.append(std::to_string(arg));
        variadic_unpack(buf, args...);
    }
    
    template<typename... Args>
        static void variadic_unpack(std::string& buf, long double arg, const Args... args)
    {
        buf.append(std::to_string(arg));
        variadic_unpack(buf, args...);
    }
}

// * Functions and delegates for integrated Logger

namespace TVk
{
    static std::function<void(const std::string&)> _Debug = [](const std::string& _msg) -> void {
        std::cout<<"(DEBUG) "<<_msg<<std::endl;
    };
    static std::function<void(const std::string&)> _Info = [](const std::string& _msg) -> void {
        std::cerr<<"(INFO)  "<<_msg<<std::endl;
    };
    static std::function<void(const std::string&)> _IInfo = [](const std::string& _msg) -> void {
        std::cerr<<"(INFO)  "<<_msg<<std::endl;
    };
    static std::function<void(const std::string&)> _Warn = [](const std::string& _msg) -> void {
        std::cerr<<"(WARN)  "<<_msg<<std::endl;
    };
    static std::function<void(const std::string&)> _Err = [](const std::string& _msg) -> void {
        std::cerr<<"(ERROR) "<<_msg<<std::endl;
    };
    static std::function<void(const std::string&)> _Crit = [](const std::string& _msg) -> void {
        std::cerr<<"!(CRIT) "<<_msg<<std::endl;
    };

    template<typename... Args>
    void Debug(const Args &... _msg){
        std::string buf;
        TVkLog::variadic_unpack(buf, _msg...);
        _Debug(buf);
    };
    template<typename... Args>
    void Info(const Args &... _msg){
        std::string buf;
        TVkLog::variadic_unpack(buf, _msg...);
        _Info(buf);
    };
    template<typename... Args>
    void IInfo(const Args &... _msg){
        std::string buf;
        TVkLog::variadic_unpack(buf, _msg...);
        _IInfo(buf);
    };
    template<typename... Args>
    void Warn(const Args &... _msg){
        std::string buf;
        TVkLog::variadic_unpack(buf, _msg...);
        _Warn(buf);
    };
    template<typename... Args>
    void Err(const Args &... _msg){
        std::string buf;
        TVkLog::variadic_unpack(buf, _msg...);
        _Err(buf);
    };
    template<typename... Args>
    void Crit(const Args &... _msg){
        std::string buf;
        TVkLog::variadic_unpack(buf, _msg...);
        _Crit(buf);
        assert(false);
    };
} // namespace TVk

#endif // TVK_LOG_H