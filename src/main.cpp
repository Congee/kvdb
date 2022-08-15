#include <fmt/format.h>
#include <iostream>

int main(int argc, char *argv[]) {
  auto x = fmt::format("{} {}!", "Hello", "kv", "db");
  std::cout << x << std::endl;
  return 0;
}
