enable_testing()

set(
    TEST_TARGET_NAME
    test_hello
)

set(
    TEST_SOURCES
    test.cpp
)

find_package(GTest REQUIRED)

add_executable(${TEST_TARGET_NAME} ${TEST_SOURCES})
target_link_libraries(${TEST_TARGET_NAME} GTest::gtest GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(${TEST_TARGET_NAME})