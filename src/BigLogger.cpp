#include <BigLogger.h>

bool biglg::BigLogger::check_path(std::filesystem::path path){
    TLS_DEBUG_MSG(std::format("START: Checking if path exists: {}", path));

    if (std::filesystem::exists(path)){
        TLS_DEBUG_MSG("File already exists");
    }
    else{
        TLS_DEBUG_MSG("Directories don't exist");
        std::error_code ec;
        if (std::filesystem::create_directories(path.parent_path(), ec)){
            TLS_DEBUG_MSG("Directory created");
        }else{
            TLS_DEBUG_MSG("CORRUPT: Directory NOT created");
            return false;
        }
        if (ec){
            auto er = std::system_error(ec);
            TLS_DEBUG_ERR("Error while creating directory!", er);
            throw er;
        }
    }

    TLS_DEBUG_MSG(std::format("SUCCESS: Checking if path exists: {}", path));
    return true;
}

biglg::BigLogger::BigLogger(std::string name, std::string path)
{
    TLS_DEBUG_MSG("START: BigLogger creating");

    set_name(name);
    set_path(std::filesystem::current_path() / path);
    out = std::ofstream(path);

    TLS_DEBUG_MSG("SUCCESS: BigLogger creating");
}

biglg::BigLogger::~BigLogger(){
    TLS_DEBUG_MSG("START: Closing ofstream");

    out.close();

    TLS_DEBUG_MSG("SUCCESS: Closing ofstream");
}

void biglg::BigLogger::custom_log(std::string tag, std::string msg){
    TLS_DEBUG_MSG(std::format("START: Logging message: [{}] {}", tag, msg));

    out << std::format("[{}] {}", tag, msg) << std::endl;

    TLS_DEBUG_MSG(std::format("SUCCESS: Logging message: [{}] {}", tag, msg));
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

std::filesystem::path biglg::BigLogger::get_path(){
    return path;
}

void biglg::BigLogger::set_path(std::string path){
    set_path(std::filesystem::path(path));
}

void biglg::BigLogger::set_path(std::filesystem::path path){
    TLS_DEBUG_MSG(std::format("START: Setting path: {}", path));

    if (!check_path(path)){
        out.close();
        out = std::ofstream(path);
    }else{
        TLS_DEBUG_MSG("CORRUPT: Couldn't set new path");
    }

    TLS_DEBUG_MSG(std::format("SUCCESS: Setting path: {}", path));
}

std::string biglg::BigLogger::get_name(){
    return name;
}

void biglg::BigLogger::set_name(std::string name){
    TLS_DEBUG_MSG(std::format("START: Setting name: {}", name));

    TLS_DEBUG_MSG("Deleting spaces from name");
    for (int i = name.length() - 1; i >= 0; i--){
        if (std::isspace(name[i])) name.erase(i, 1);
    }
    if (name.empty()){
        TLS_DEBUG_ERR("Logger empty", std::runtime_error("Logger name empty or contains only whitespaces"));
        throw new std::runtime_error("Logger name can't be empty");
    }
    this->name = name;

    TLS_DEBUG_MSG(std::format("SUCCESS: Setting name: {}", name));
}