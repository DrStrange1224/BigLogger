#pragma once

#include <string>
#include <filesystem>
#include <format>
#include <iostream>

namespace biglg{

    class BigLogger{
    private:
        std::string name;
        std::string path;

    public:
        BigLogger(std::string _name, std::string _path);
    };

}