#include <unordered_map>

#include <fmt/format.h>

#include "kv.hpp"

int main(int argc, char* argv[]) {
  using Hashmap = std::unordered_map<Key, Value>;
  KV<Hashmap> kv;
  auto got = kv.get("hello");
  if (got) got.value();
  auto x = fmt::format("{} {}!", "Hello", "kv", "db");
  fmt::print(x, "\n");
  return 0;
}
