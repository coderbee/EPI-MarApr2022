#pragma once

#include <memory>

using std::shared_ptr;

template <typename T>
struct BstNode {
  T data;
  shared_ptr<BstNode<T>> left, right;
  
  explicit BstNode(const T& data) : data(data) {}
  
};

DECLARE_BINARY_TREE_TYPE(KeyT, std::shared_ptr<BstNode<KeyT>>, false)
