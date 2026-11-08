#include <debugTools.h>

void tls::debug_msg(std::string msg){
    std::cout << msg << std::endl;
}

void tls::debug_err(std::string msg, std::error_code err){
    std::cerr << msg << std::endl << "Error code: " << err << std::endl;
}