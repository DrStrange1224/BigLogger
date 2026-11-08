cmake_minimum_required(VERSION 4.4)

project(BigLogger)

option(LOGGER_TEST_ENABLED OFF)

add_subdirectory(src)
add_subdirectory(test)