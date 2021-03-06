cmake_minimum_required(VERSION 3.23)

# Include build functions from Pico SDK (must be done before set project)
include($ENV{PICO_SDK_PATH}/external/pico_sdk_import.cmake)

# Project definition
project(hello_world_console LANGUAGES C CXX)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

option(ENABLE_USB_CONSOLE "Use USB as console destination" OFF)

# Initialize SDK for the project (see pico-sdk directory in build directory)
pico_sdk_init()

# Define target ${CMAKE_PROJECT_NAME}
add_executable(${CMAKE_PROJECT_NAME}
    main.cpp
)

target_link_libraries(${CMAKE_PROJECT_NAME}
    pico_stdlib
)

# Console configuration
if (ENABLE_USB_CONSOLE)
    pico_enable_stdio_usb(${CMAKE_PROJECT_NAME} 1)
    pico_enable_stdio_uart(${CMAKE_PROJECT_NAME} 0)
endif ()

# Create bin/dis/elf.map/hex/uf2 files
pico_add_extra_outputs(${CMAKE_PROJECT_NAME})

# Fix make clean to delete bin/dis/elf.map/hex/uf2 files
set_property(TARGET APPEND PROPERTY ADDITIONAL_CLEAN_FILES
    "${CMAKE_PROJECT_NAME}.bin"
    "${CMAKE_PROJECT_NAME}.dis"
    "${CMAKE_PROJECT_NAME}.elf.map"
    "${CMAKE_PROJECT_NAME}.hex"
    "${CMAKE_PROJECT_NAME}.uf2"
)

# Add a target to load the program using picotool
add_custom_target(load
    COMMAND doas picotool load -v -x ${CMAKE_PROJECT_NAME}.bin
)
