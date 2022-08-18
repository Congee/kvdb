#include <optional>
#include <string>

using Key = std::string;
using Value = std::string;

template <typename Store>
class KV {
  Store store;

 public:
  KV<Store>() noexcept;
  std::optional<Key> get(const Key& key) noexcept;
  void put(const Key& key, Value& value) noexcept;
  void del(const Key& key) noexcept;
};
