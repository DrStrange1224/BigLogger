add_library(DebugTools SHARED)
target_sources(DebugTools
    PRIVATE
        DebugTools.cpp

    PUBLIC
        FILE_SET HEADERS
        FILES
            DebugTools.h
)