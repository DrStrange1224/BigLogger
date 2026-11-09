#include <BigLogger.h>

std::error_code biglg::BigLogger::check_path(std::filesystem::path path){
    std::error_code ec;
    if (std::filesystem::exists(path)){
        TLS_DEBUG_MSG("File already exists");
    }
    else{
        if (std::filesystem::create_directories(path.parent_path(), ec)){
            TLS_DEBUG_MSG("Directory created!");
        }
        if (ec){
            TLS_DEBUG_ERR("Error while creating directory!", ec);
        }
    }
    return ec;
}

biglg::BigLogger::BigLogger(std::string name, std::string path)
{
    set_name(name);
    set_path(std::filesystem::current_path() / path);
    
    out = std::ofstream(path);
    TLS_DEBUG_MSG("Success BigLogger creating");
}

biglg::BigLogger::~BigLogger(){
    out.close();
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

std::filesystem::path biglg::BigLogger::get_path(){
    return path;
}

void biglg::BigLogger::set_path(std::string path){
    set_path(std::filesystem::path(path));
}

void biglg::BigLogger::set_path(std::filesystem::path path){
    auto ec = check_path(path);
    if (ec){
        std::cerr << "ERROR" << std::endl;
    }

    out.close();
    out = std::ofstream(path);
}

std::string biglg::BigLogger::get_name(){
    return name;
}

void biglg::BigLogger::set_name(std::string name){
    for (int i = name.length() - 1; i >= 0; i--){
        if (std::isspace(name[i])) name.erase(i, 1);
    }
    if (name.empty()){
        throw new std::runtime_error("Logger name can't be empty");
    }
    this->name = name;
}