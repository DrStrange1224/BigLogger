#pragma once

#include <string>
#include <filesystem>
#include <format>
#include <iostream>
#include <fstream>

#if CMAKE_BUILD_TYPE == Debug
#  include <debugTools.h>
#  define TLS_DEBUG_MSG(msg) tls::debug_msg(msg)
#  define TLS_DEBUG_ERR(msg, err) tls::debug_err(msg, err)
#else
#  define TLS_DEBUG_MSG(msg) ((void)0)
#  define TLS_DEBUG_ERR(msg, err) ((void)0)
#endif

namespace biglg{

    class BigLogger{
    private:
        std::string name;
        std::filesystem::path path;
        std::ofstream out;

    public:
        BigLogger(std::string _name, std::string _path);
        ~BigLogger();
        
        void custom_log(std::string tag, std::string msg);
        void info(std::string msg);
        void warn(std::string msg);
        void err(std::string msg);
    };

}