#include <optional>

#include <fmt/format.h>
#include <fmt/os.h>
#include <tl/expected.hpp>
#include "gtest/gtest.h"


#define Some std::make_optional
#define None std::nullopt

#define Ok(x) (x)
#define Err tl::make_unexpected


namespace fmt {

// println is missing https://github.com/fmtlib/fmt/issues/428
template <typename... Args> void println(const Args &...args) {
  fmt::print(args...);
  std::putc('\n', stdout);
}

} // namespace fmt
