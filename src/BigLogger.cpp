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
    }
    out = std::ofstream(path);
    TLS_DEBUG_MSG("Success BigLogger creating");
}

void biglg::BigLogger::custom_log(std::string tag, std::string msg){
    out << std::format("[{}] {}", tag, msg) << std::endl;
}

void biglg::BigLogger::info(std::string msg){
    custom_log("INFO", msg);
}

void biglg::BigLogger::warn(std::string msg){
    custom_log("WARN", msg);
}

void biglg::BigLogger::err(std::string msg){
    custom_log("ERR", msg);
}
