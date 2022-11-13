cmake_minimum_required(VERSION 3.22)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

project(credentialsTool VERSION 0.1)

option(USE_MYMATH "use custom math library" ON)

set(
    TARGET_NAME
    credentialsTool
)
configure_file(include/configure_template.h configure.h)
set(
    SOURCES
    src/main.cpp
)

add_executable(${TARGET_NAME} ${SOURCES})

if(USE_MYMATH)
  add_subdirectory(library)
  list(APPEND EXTRA_LIBS MathFunctions)
  list(APPEND EXTRA_INCLUDES ${PROJECT_SOURCE_DIR}/library)
endif()

target_link_libraries(${TARGET_NAME} PUBLIC ${EXTRA_LIBS})

target_include_directories(${TARGET_NAME} PRIVATE
                                          include
                                          ${CMAKE_CURRENT_BINARY_DIR}
                                          ${EXTRA_INCLUDES}
)