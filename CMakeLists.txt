cmake_minimum_required(VERSION 3.21)

# C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# macOS universal build
set(CMAKE_OSX_ARCHITECTURES "arm64;x86_64")

# Hide symbols by default
set(CMAKE_CXX_VISIBILITY_PRESET hidden)

# Project definition
project(GeodeTestMod VERSION 1.0.0)

# Source files
add_library(${PROJECT_NAME} SHARED
    src/main.cpp
    src/MyCustomSettingV3.cpp
    src/MyButtonSettingV3.cpp
)

# Geode SDK detection
if(NOT DEFINED ENV{GEODE_SDK})
    message(FATAL_ERROR "Unable to find Geode SDK! Please define GEODE_SDK environment variable to point to Geode")
else()
    message(STATUS "Found Geode: $ENV{GEODE_SDK}")
endif()

# Add Geode SDK
add_subdirectory($ENV{GEODE_SDK} ${CMAKE_CURRENT_BINARY_DIR}/geode)

# Register mod with Geode
setup_geode_mod(${PROJECT_NAME})
