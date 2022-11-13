set(
	TARGET_NAME
	MathFunctions
)
set(
    HEADERS
    include/MathFunctions.h
)
set(
	SOURCES
	src/mysqrt.cpp
)

add_library(${TARGET_NAME} SHARED ${SOURCES})

target_link_libraries(${TARGET_NAME} compiler_flags)

target_include_directories(${TARGET_NAME}
	INTERFACE
		include
)

# does this system provide the log and exp functions?
include(CheckCXXSourceCompiles)
check_cxx_source_compiles("
  #include <cmath>
  int main() {
    std::log(1.0);
    return 0;
  }
" HAVE_LOG)
check_cxx_source_compiles("
  #include <cmath>
  int main() {
    std::exp(1.0);
    return 0;
  }
" HAVE_EXP)

if(HAVE_LOG AND HAVE_EXP)
  target_compile_definitions(MathFunctions
                             PRIVATE "HAVE_LOG" "HAVE_EXP")
endif()

set(INSTALLABLE_LIBS MathFunctions)
install(TARGETS ${INSTALLABLE_LIBS} DESTINATION lib)
install(FILES ${HEADERS} DESTINATION include)