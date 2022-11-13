cmake_minimum_required(VERSION 3.22)

add_library(compiler_flags INTERFACE)
target_compile_features(compiler_flags INTERFACE cxx_std_20)
set(gcc_like_cxx "$<COMPILE_LANG_AND_ID:CXX,ARMClang,AppleClang,Clang,GNU,LCC>")
set(msvc_cxx "$<COMPILE_LANG_AND_ID:CXX,MSVC>")
target_compile_options(compiler_flags INTERFACE
  "$<${gcc_like_cxx}:-Wall;-Wextra;-Wshadow;-Wformat=2;-Wunused;-Werror;-Wfloat-equal;-Wundef;-Wpointer-arith;-Wcast-align;>"
  "$<${msvc_cxx}:-W3>"
)

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
endif()

list(APPEND EXTRA_LIBS compiler_flags)

target_link_libraries(${TARGET_NAME} PUBLIC ${EXTRA_LIBS})

target_include_directories(${TARGET_NAME} PRIVATE
                                          include
                                          ${CMAKE_CURRENT_BINARY_DIR}
)