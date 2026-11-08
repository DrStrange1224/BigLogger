cmake_minimum_required(VERSION 4.4)

project(BigLogger)

add_library(BigLoggerLib)
target_sources(BigLoggerLib
    PRIVATE
        BigLogger.cpp
    
    PUBLIC
        FILE_SET HEADERS
        FILES
            BigLogger.h
)

option(LOGGER_TEST_ENABLED OFF)
if(LOGGER_TEST_ENABLED)
    add_executable(Test test.cpp)
    target_link_libraries(Test PUBLIC BigLoggerLib)
endif()