#include <optional>

#include <fmt/format.h>
#include <tl/expected.hpp>

#define Some std::make_optional
#define None std::nullopt

#define Ok(x) (x)
#define Err tl::make_unexpected
