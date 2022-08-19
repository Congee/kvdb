#include <unordered_map>

#include <fmt/format.h>

#include "common.hpp"
#include "kv.hpp"

int main(int argc, char* argv[]) {
  auto x = fmt::format("{} {}!", "Hello", "kv", "db");
  using Hashmap = std::unordered_map<Key, Value>;
  KV<Hashmap> kv;
  // auto got = kv.get("hello");
  // if (got) got.value();
  fmt::println(x);
  return 0;
}
