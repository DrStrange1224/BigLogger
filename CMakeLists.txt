cmake_minimum_required(VERSION 4.4)

project(BigLogger)

option(LOGGER_TEST_ENABLED "enables test tools" OFF)

add_subdirectory(src)

if(LOGGER_TEST_ENABLED)
    target_compile_definitions(BigLogger PRIVATE LOGGER_TEST_ENABLED)
    
    add_subdirectory(test)
    target_compile_definitions(TestTools PRIVATE LOGGER_TEST_ENABLED)
    target_link_libraries(BigLogger PUBLIC TestTools)
endif()