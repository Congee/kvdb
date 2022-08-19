#include <optional>
#include <string>

using Key = std::string;
using Value = std::string;

class Skiplist {
 public:
  void put(const Key& key, const Value& value) noexcept;
  std::optional<Value> get(const Key& key) const noexcept;
  void del(const Key& key) noexcept;
};
