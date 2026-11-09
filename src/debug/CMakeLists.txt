add_library(DebugTools)
target_sources(DebugTools
    PRIVATE
        DebugTools.cpp

    PUBLIC
        FILE_SET HEADERS
        FILES
            DebugTools.h
)