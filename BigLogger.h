#pragma once

#include <string>
#include <filesystem>
#include <format>
#include <iostream>
#include <fstream>

namespace biglg{

    class BigLogger{
    private:
        std::string name;
        std::filesystem::path path;

    public:
        BigLogger(std::string _name, std::string _path);
    };

}