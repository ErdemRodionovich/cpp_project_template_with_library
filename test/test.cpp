#include <gtest/gtest.h>

TEST(HelloTest, Hello){
  ASSERT_NE("hello", "world");
  EXPECT_EQ(7*6, 42);
}