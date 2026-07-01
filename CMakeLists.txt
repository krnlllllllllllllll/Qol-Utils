cmake_minimum_required(VERSION 3.21)

project(GeodeTestMod VERSION 1.0.0)

# C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# macOS universal build (ignored on Windows)
set(CMAKE_OSX_ARCHITECTURES "arm64;x86_64")

# Hide symbols by default
set(CMAKE_CXX_VISIBILITY_PRESET hidden)

# Load Geode SDK
if(NOT DEFINED ENV{GEODE_SDK})
    message(FATAL_ERROR "Unable to find Geode SDK! Please define GEODE_SDK environment variable.")
endif()

include($ENV{GEODE_SDK}/cmake/Geode.cmake)

# Your mod sources
add_library(${PROJECT_NAME} SHARED
    src/main.cpp
    src/MyCustomSettingV3.cpp
    src/MyButtonSettingV3.cpp
)

# Register mod
setup_geode_mod(${PROJECT_NAME})
