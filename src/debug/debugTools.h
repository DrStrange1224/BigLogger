#pragma once

#include <iostream>
#include <string>

namespace tls{
    void debug_msg(std::string msg);
    void debug_err(std::string msg, std::error_code err);
}