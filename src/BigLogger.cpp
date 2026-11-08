#include <BigLogger.h>

biglg::BigLogger::BigLogger(std::string _name, std::string _path){
    name = _name;
    path = std::filesystem::current_path() / _path;

    //if file already exists just use it
    if (std::filesystem::exists(path)){
        TLS_DEBUG_MSG("File already exists");
    }
    //else try to create it
    else{
        std::error_code err;
        if (std::filesystem::create_directories(path.parent_path(), err)){
            TLS_DEBUG_MSG("Directory created!");
        }
        if (err){
            TLS_DEBUG_ERR("Error while creating directory!", err);
        }
        std::ofstream _(path);
    }
    TLS_DEBUG_MSG("Success BigLogger creating");
}
