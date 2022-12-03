if(TARGET compiler_flags)
else()
    set(
        COMPILER_FLAGS_TARGET_NAME
        compiler_flags
    )
    #compiler flags
    add_library(${COMPILER_FLAGS_TARGET_NAME} INTERFACE)
    target_compile_features(${COMPILER_FLAGS_TARGET_NAME} INTERFACE cxx_std_20)
    set(gcc_like_cxx "$<COMPILE_LANG_AND_ID:CXX,ARMClang,AppleClang,Clang,GNU,LCC>")
    set(msvc_cxx "$<COMPILE_LANG_AND_ID:CXX,MSVC>")
    target_compile_options(${COMPILER_FLAGS_TARGET_NAME} INTERFACE
    "$<${gcc_like_cxx}:-Wall;-Wextra;-Wshadow;-Wformat=2;-Wunused;-Werror;-Wfloat-equal;-Wundef;-Wpointer-arith;-Wcast-align;>"
    "$<${msvc_cxx}:-W3>"
    )
endif()
