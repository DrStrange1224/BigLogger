#pragma once

#include <iostream>
#include <string>
#include <exception>

namespace tls{
    void debug_msg(std::string msg);
    void debug_err(std::string msg, std::exception exc);
}