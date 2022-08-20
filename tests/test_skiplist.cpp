#include <gtest/gtest.h>

#include "skiplist.hpp"

TEST(Skiplist, skiplist_get_from_empty) {
  Skiplist sl;
  EXPECT_FALSE(sl.get("foo").has_value());
}

TEST(Skiplist, skiplist) {
  Skiplist sl;
  EXPECT_FALSE(sl.get("nonexistent").has_value());

  sl.put("foo", "foo");
  sl.put("bar", "bar");
  sl.put("qux", "qux");

  EXPECT_EQ(sl.get("foo").value(), "foo");
  EXPECT_FALSE(sl.get("nonexistent").has_value());

  sl.put("foo", "foo0");
  EXPECT_EQ(sl.get("foo").value(), "foo0");

  // clang-format off
  sl.del("foo"); EXPECT_EQ(sl.size(), 2);
  sl.del("bar"); EXPECT_EQ(sl.size(), 1);
  sl.del("qux"); EXPECT_EQ(sl.size(), 0);
  // clang-format on

  EXPECT_FALSE(sl.del("foo"));
  EXPECT_EQ(sl.size(), 0);
}
