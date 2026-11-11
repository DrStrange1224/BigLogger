cmake_minimum_required(VERSION 4.4)

project(BigLogger)

option(BUILD_TESTING "Enable testing and build tests" ON)
option(CMAKE_BUILD_TYPE "Debug/Release" OFF)

add_subdirectory(src)
if(CMAKE_BUILD_TYPE)
    target_compile_definitions(BigLogger PUBLIC CMAKE_BUILD_TYPE)
endif()

if(BUILD_TESTING)
    enable_testing()
    add_subdirectory(test)
    target_link_libraries(Test PUBLIC BigLogger)
endif()

if(CMAKE_BUILD_TYPE MATCHES "Debug")
    install(
        TARGETS BigLogger DebugTools

        RUNTIME
            DESTINATION ${CMAKE_INSTALL_PREFIX}/lib
        
        FILE_SET HEADERS
    )
else()
    install(
        TARGETS BigLogger

        RUNTIME
            DESTINATION ${CMAKE_INSTALL_PREFIX}/lib
        
        FILE_SET HEADERS
    )
endif()