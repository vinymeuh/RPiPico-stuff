cmake_minimum_required(VERSION 3.23)

# Include build functions from Pico SDK (must be done before set project)
include($ENV{PICO_SDK_PATH}/external/pico_sdk_import.cmake)

# Project definition
project(hello_world_blinky LANGUAGES C CXX)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Initialize SDK for the project (see pico-sdk directory in build directory)
pico_sdk_init()

# Define source and libraries used
add_executable(${CMAKE_PROJECT_NAME}
    main.cpp
)

target_link_libraries(${CMAKE_PROJECT_NAME}
    pico_stdlib
)

# Create map/bin/hex/uf2 files
pico_add_extra_outputs(${CMAKE_PROJECT_NAME})
