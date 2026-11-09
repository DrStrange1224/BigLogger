#include <BigLogger.h>

std::error_code biglg::BigLogger::check_path(std::filesystem::path path){
    TLS_DEBUG_MSG(std::format("START: Checking if path exists: {}", path));

    std::error_code ec;
    if (std::filesystem::exists(path)){
        TLS_DEBUG_MSG("File already exists");
    }
    else{
        TLS_DEBUG_MSG("Directories don't exist");
        if (std::filesystem::create_directories(path.parent_path(), ec)){
            TLS_DEBUG_MSG("Directory created");
        }else{
            TLS_DEBUG_MSG("Directory NOT created");
        }
        if (ec){
            TLS_DEBUG_ERR("Error while creating directory!", ec);
        }
    }

    TLS_DEBUG_MSG(std::format("SUCCESS: Checking if path exists: {}", path));
    return ec;
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

    auto ec = check_path(path);
    if (ec){
        std::cerr << "ERROR" << std::endl;
    }

    out.close();
    out = std::ofstream(path);

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
        // TLS_DEBUG_ERR("Logger empty", )
        throw new std::runtime_error("Logger name can't be empty");
    }
    this->name = name;

    TLS_DEBUG_MSG(std::format("SUCCESS: Setting name: {}", name));
}