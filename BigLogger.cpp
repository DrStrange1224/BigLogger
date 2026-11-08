#include <BigLogger.h>

biglg::BigLogger::BigLogger(std::string _name, std::string _path){
    name = _name;
    auto p = std::filesystem::current_path();
    p /= _path;
    if (std::filesystem::exists(p)){
        std::cout << p << std::endl;
        path = _path;
    }else{
        std::cerr << "No path exists like: " << p << std::endl;
    }
}
