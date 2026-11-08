add_library(BigLogger)
target_sources(BigLogger
    PRIVATE
        BigLogger.cpp
    
    PUBLIC
        FILE_SET HEADERS
        FILES
            BigLogger.h
)

if(CMAKE_BUILD_TYPE MATCHES "Debug")
    add_subdirectory(debug)
    target_link_libraries(BigLogger PUBLIC DebugTools)
endif()