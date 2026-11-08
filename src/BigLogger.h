#pragma once

#include <string>
#include <filesystem>
#include <format>
#include <iostream>
#include <fstream>

#ifdef LOGGER_TEST_ENABLED
#  include <testTools.h>
#  define TLS_DEBUG_MSG(msg) tls::debug_msg(msg)
#  define TLS_DEBUG_ERR(msg, ec) tls::debug_err(msg, ec)
#else
#  define TLS_DEBUG_MSG(msg) ((void)0)
#  define TLS_DEBUG_ERR(msg, ec) ((void)0)
#endif

namespace biglg{

    class BigLogger{
    private:
        std::string name;
        std::filesystem::path path;

    public:
        BigLogger(std::string _name, std::string _path);
    };

}