add_library(BigLogger)
target_sources(BigLogger
    PRIVATE
        BigLogger.cpp
    
    PUBLIC
        FILE_SET HEADERS
        FILES
            BigLogger.h
)

add_subdirectory(debug)
if(CMAKE_BUILD_TYPE MATCHES "Debug")
    target_link_libraries(BigLogger PUBLIC DebugTools)
endif()