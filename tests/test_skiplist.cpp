#include <gtest/gtest.h>

#include "skiplist.hpp"

TEST(Skiplist, skiplist) {
  Skiplist sl;
  sl.put("foo", "bar");
  EXPECT_FALSE(sl.get("foo").has_value());
}
