set(
	TARGET_NAME
	MathFunctions
)

#custom command
set(
    MAKE_TABLE_TARGET_NAME
    MakeTable
)
set(
    MAKE_TABLE_SOURCES
    src/MakeTable.cpp
)

add_executable(${MAKE_TABLE_TARGET_NAME} ${MAKE_TABLE_SOURCES})
set(
    TABLE_FILE
    ${CMAKE_CURRENT_BINARY_DIR}/Table.h
)
add_custom_command(
    OUTPUT ${TABLE_FILE}
    COMMAND MakeTable ${TABLE_FILE}
    DEPENDS ${MAKE_TABLE_TARGET_NAME}
)

set(
    HEADERS
    include/MathFunctions.h
)
set(
	SOURCES
	src/mysqrt.cpp
        ${TABLE_FILE}
)

add_library(${TARGET_NAME} SHARED ${SOURCES})

set_property(TARGET ${TARGET_NAME} PROPERTY VERSION "1.0.0")
set_property(TARGET ${TARGET_NAME} PROPERTY SOVERSION "1")

target_link_libraries(${TARGET_NAME} compiler_flags)

target_include_directories(${TARGET_NAME}
	INTERFACE
                $<INSTALL_INTERFACE:include>
                $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        PRIVATE
                ${CMAKE_CURRENT_BINARY_DIR}
)

#check system
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

#install
list(APPEND INSTALLABLE_LIBS MathFunctions compiler_flags)
install(TARGETS ${INSTALLABLE_LIBS}
                EXPORT MathFunctionsTargets
                DESTINATION lib
)
install(FILES ${HEADERS} DESTINATION include)

