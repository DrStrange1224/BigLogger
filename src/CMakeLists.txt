add_library(BigLoggerLib)
target_sources(BigLoggerLib
    PRIVATE
        BigLogger.cpp
    
    PUBLIC
        FILE_SET HEADERS
        FILES
            BigLogger.h
)