cmake_minimum_required(VERSION 3.22)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

project(credentialsTool VERSION 0.1)

set(
    TARGET_NAME
    credentialsTool
)
configure_file(configure_template.h ${CMAKE_CURRENT_SOURCE_DIR}/configure.h)
set(
    SOURCES
    configure.h
    main.cpp
)

add_executable(${TARGET_NAME} ${SOURCES})