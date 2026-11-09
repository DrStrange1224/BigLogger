#pragma once

#include <exception>

namespace exc{
    class BLError : public std::exception{
    public:
        const char* what() const noexcept override{return "BLError";}
    };

    class WrongNameError : public exc::BLError{
    public:
        const char* what() const noexcept override{return "Wrong name error";}
    };

    class DirectoryCreatingError : public exc::BLError{
    public:
        const char* what() const noexcept override{return "Directory creating error";}
    };
}