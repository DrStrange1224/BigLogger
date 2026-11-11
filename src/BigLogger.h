#pragma once

#include <string>
#include <filesystem>
#include <format>
#include <iostream>
#include <fstream>

#ifdef CMAKE_BUILD_TYPE
#  include <DebugTools.h>
#  define TLS_DEBUG_MSG(msg) tls::debug_msg(msg)
#  define TLS_DEBUG_ERR(msg, exc) tls::debug_err(msg, exc)
#else
#  define TLS_DEBUG_MSG(msg) ((void)0)
#  define TLS_DEBUG_ERR(msg, exc) ((void)0)
#endif

namespace biglg{

    class BigLogger{
    private:

        //TODO do i need logger name???
        std::string name;
        std::filesystem::path path;
        std::ofstream out;

        bool check_path(std::filesystem::path path);

    public:
        BigLogger(std::string _name, std::string _path);
        ~BigLogger();
        
        //simple logs
        void custom_log(std::string tag, std::string msg);
        void info(std::string msg);
        void warn(std::string msg);
        void err(std::string msg);

        //get-set path
        std::filesystem::path get_path();
        void set_path(std::string path);
        void set_path(std::filesystem::path path);

        //get-set name
        std::string get_name();
        void set_name(std::string name);
    };

}