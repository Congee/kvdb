#include <unordered_map>

#include "common.hpp"
#include "kv.hpp"

using Hashmap = std::unordered_map<Key, Value>;

template <>
std::optional<Value> KV<Hashmap>::get(const Key &key) noexcept {
  auto x = store.find(key);
  if (x == store.end()) return None;
  return Some(x->second);
}

template <>
void KV<Hashmap>::put(const Key &key, Value &value) noexcept {
  store.emplace(key, value);
}

template <>
void KV<Hashmap>::del(const Key &key) noexcept {
  store.erase(key);
}
