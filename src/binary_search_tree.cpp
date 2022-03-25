#include "assignment/binary_search_tree.hpp"

namespace assignment {

  BinarySearchTree::~BinarySearchTree() {
    BinarySearchTree::Clear();
  }

  void BinarySearchTree::Insert(int key, int value) {
    insert(key, value, root_);
  }

  bool BinarySearchTree::Remove(int key) {
    return remove(key, root_);
  }

  void BinarySearchTree::Clear() {
    clear(root_);
    root_ = nullptr;
  }

  std::optional<int> BinarySearchTree::Find(int key) const {
    Node* found_node = find(key, root_);

    if (found_node == nullptr) {
      return std::nullopt;
    }

    return found_node->value;
  }

  bool BinarySearchTree::Contains(int key) const {
    Node* found_node = find(key, root_);
    if (found_node == nullptr) {
      return false;
    }
    return true;
  }

  bool BinarySearchTree::IsEmpty() const {
    return root_ == nullptr;
  }

  std::optional<int> BinarySearchTree::FindMin() const {
    if (root_ == nullptr) {
      return std::nullopt;
    }
    Node* answer = find_min(root_);
    return answer->value;
  }

  std::optional<int> BinarySearchTree::FindMax() const {
    if (root_ == nullptr) {
      return std::nullopt;
    }

    Node* curr_node = root_;
    while (curr_node->right != nullptr) {
      curr_node = curr_node->right;
    }

    return curr_node->value;
  }

  Node* BinarySearchTree::root() const {
    return root_;
  }

  // вспомогательные методы

  void BinarySearchTree::insert(int key, int value, Node*& node) {
    if (node == nullptr) {
      Node* new_node = new Node(key, value);
      node = new_node;
    }
    if (key < node->key) {
      insert(key, value, node->left);
    } else if (key > node->key) {
      insert(key, value, node->right);
    } else {
      node->value = value;
    }
  }

  bool BinarySearchTree::remove(int key, Node*& node) {
    if (node == nullptr) {
      return false;
    }
    if (key == node->key) {
      if (node->left != nullptr && node->right != nullptr) {
        Node* min = find_min(node->right);

        node->key = min->key;
        node->value = min->value;

        return remove(min->key, node->right);
      }
      if (node->left != nullptr && node->right == nullptr) {
        Node* left_child = node->left;
        delete node;
        node = left_child;
        return true;
      }

      Node* right_child = node->right;
      delete node;
      node = right_child;
      return true;
    }

    if (key < node->key) {
      return remove(key, node->left);
    }

    return remove(key, node->right);
  }

  void BinarySearchTree::clear(Node* node) {
    if (node != nullptr) {
      clear(node->left);
      clear(node->right);
      delete node;
    }
  }

  Node* BinarySearchTree::find(int key, Node* node) const {
    if (node == nullptr) {
      return nullptr;
    }

    if (key == node->key) {
      return node;
    }

    if (key < node->key) {
      return find(key, node->left);
    }

    if (key > node->key) {
      return find(key, node->right);
    }
  }

  Node* BinarySearchTree::find_min(Node* node) const {
    while (node->left != nullptr) {
      node = node->left;
    }
    return node;
  }

  Node* BinarySearchTree::find_max(Node* node) const {
    // Write your code here...
    return nullptr;
  }

}  // namespace assignment