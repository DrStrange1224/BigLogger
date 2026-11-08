add_library(BigLogger)
target_sources(BigLogger
    PRIVATE
        BigLogger.cpp
    
    PUBLIC
        FILE_SET HEADERS
        FILES
            BigLogger.h
)