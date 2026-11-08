add_library(DebugTools)
target_sources(DebugTools
    PRIVATE
        debugTools.cpp

    PUBLIC
        FILE_SET HEADERS
        FILES
            debugTools.h
)