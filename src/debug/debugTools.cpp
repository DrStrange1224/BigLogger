#include <debugTools.h>

void tls::debug_msg(std::string msg){
    std::cout << msg << std::endl;
}

void tls::debug_err(std::string msg, std::exception exc){
    std::cerr << msg << std::endl << "Error code: " << exc.what() << std::endl;
}