set(
	TARGET_NAME
	MathFunctions
)
set(
	SOURCES
	src/mysqrt.cpp
)

add_library(${TARGET_NAME} SHARED ${SOURCES})

target_include_directories(${TARGET_NAME}
	PUBLIC
		include
)
