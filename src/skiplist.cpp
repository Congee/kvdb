#include <cstdlib>
#include <stack>

#include <stdlib.h>

#include "common.hpp"
#include "skiplist.hpp"

static unsigned int seed = 42;

int rand_level() {
  int level;
  for (level = 0; rand_r(&seed) & 1; level++)
    ;
  return level;
}

/// This Skiplist implementation is not thread-safe. Range query and random
/// access will be available in the future. Duplicates are not allowed.
///
/// References:
/// https://opendsa-server.cs.vt.edu/OpenDSA/Books/CS3/html/SkipList.html
Skiplist::Skiplist() noexcept
  : head(new Node("", "", 0)), level(-1), __size(0) {
  std::srand(seed);
}

/// find the previous node
Node *Skiplist::find(const Key &key) const noexcept {
  auto curr = head;
  for (int i = level; i >= 0; --i) {
    while (curr->forward[i] && curr->forward[i]->key < key)
      curr = curr->forward[i];
  }

  return curr;
}

std::optional<Value> Skiplist::get(const Key &key) const noexcept {
  auto it = find(key);
  // 3 5 8 -> null
  // 1 -> 3
  // 4 -> 3
  // 8 -> 8
  // 9 -> null
  auto x = it->forward[0];
  return (x && x->key == key) ? Some(x->value) : None;
}

void Skiplist::put(const Key &key, const Value &value) noexcept {
  int new_level = rand_level();
  if (level < new_level) {
    while (head->forward.size() < (size_t)new_level + 1)
      head->forward.push_back(nullptr);
    level = new_level;
  }

  std::vector<Node *> vec(level + 1);
  auto curr = head;
  for (int i = level; i >= 0; --i) {
    // existing
    if (curr->forward[i] && curr->forward[i]->key == key) {
      curr->forward[i]->value = value;
      return;
    };

    while (curr->forward[i] && curr->forward[i]->key < key)
      curr = curr->forward[i];
    vec[i] = curr;
  }

  auto node = new Node(key, value, new_level);
  for (int i = 0; i <= new_level; ++i) {
    node->forward[i] = vec[i]->forward[i];
    vec[i]->forward[i] = node;
  }

  __size++;
}

std::optional<Value> Skiplist::pop(const Key &key) noexcept {
  std::vector<Node *> vec(level + 1);  // actually unnecessary
  auto curr = head;
  for (int i = level; i >= 0; --i) {
    while (curr->forward[i] && curr->forward[i]->key < key)
      curr = curr->forward[i];
    vec[i] = curr;
  }

  auto to_delete = curr->forward[0];
  if (to_delete == nullptr || to_delete->key != key) return None;

  for (size_t i = 0; i < to_delete->forward.size(); ++i) {
    vec[i]->forward[i] = to_delete->forward[i];
  }

  auto value = to_delete->value;
  delete to_delete;
  __size--;
  return value;
}

bool Skiplist::del(const Key &key) noexcept { return pop(key).has_value(); }
