#include <optional>
#include <string>
#include <vector>

using Key = std::string;
using Value = std::string;

struct Node {
  Key key;
  Value value;

  std::vector<Node*> forward;
  Node(const Key& k, const Value& v, int level) noexcept
    : key(k), value(v), forward(std::vector<Node*>(level + 1, nullptr)) {}
};

/// Skiplist is not thread-safe yet
class Skiplist {
  /// A dummy node before the 1st  node. It's always the tallest node;
  Node* head;
  int level;
  size_t __size;

  Node* find(const Key& key) const noexcept;
  std::optional<Value> pop(const Key& key) noexcept;

 public:
  Skiplist() noexcept;

  size_t size() const noexcept { return __size; }

  void put(const Key& key, const Value& value) noexcept;
  std::optional<Value> get(const Key& key) const noexcept;
  bool del(const Key& key) noexcept;
};
