cmake_minimum_required(VERSION 3.0)

project(classCreator)

set(SRCS
    src/main.cpp
    src/Core/Core.cpp
    src/Dir/Dir.cpp
    src/File/File.cpp
    src/Parser/Parser.cpp
    src/Writer/Writer.cpp
    src/State/State.cpp
    )

set(HEADERS
    inc/Core/Core.hpp
    inc/Dir/Dir.hpp
    inc/File/File.hpp
    inc/Parser/Parser.hpp
    inc/Writer/Writer.hpp
    inc/State/State.hpp
    )

add_executable(classCreator ${SRCS} ${HEADERS})
target_include_directories(classCreator PUBLIC inc)
