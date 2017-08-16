project(libusb)
cmake_minimum_required(VERSION 3.3)

list(
        APPEND HEADER_FILES
        usb.hpp
)

list(
        APPEND SOURCE_FILES
        usb.cpp
)
set(ALL_SOURCE_FILES ${HEADER_FILES} ${SOURCE_FILES})
source_group(${PROJECT_NAME} FILES ${ALL_SOURCE_FILES})
add_library(${PROJECT_NAME} ${PLATFORM_LIBRARY_TYPE} ${ALL_SOURCE_FILES})
target_link_libraries(${PROJECT_NAME}  libusb-1.0.a libhidapi-libusb.a)