cmake_minimum_required(VERSION 4.4)

project(BigLogger)

option(BUILD_TESTING "Enable testing and build tests" ON)

add_subdirectory(src)
target_compile_definitions(BigLogger PRIVATE CMAKE_BUILD_TYPE)

if(BUILD_TESTING)
    enable_testing()
    add_subdirectory(test)
    target_link_libraries(Test PUBLIC BigLogger)
endif()

install(
    TARGETS BigLogger DebugTools

    RUNTIME
        DESTINATION ${CMAKE_INSTALL_PREFIX}/lib
    
    FILE_SET HEADERS
)