set(
	TARGET_NAME
	MathFunctions
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
