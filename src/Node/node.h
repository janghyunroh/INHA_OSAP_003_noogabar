// Valid-License-Identifier: Apache-2.0

// SPDX-URL: https://spdx.org/licenses/Apache-2.0.html
// Version 2.0, January 2004
// http://www.apache.org/licenses/LICENSE-2.0

// Copyright November 2023 Inha Univ. Open Source Project Team noogabar

#ifndef INHA_OSAP_003_NOOGABAR_NODE_NODE_H
#define INHA_OSAP_003_NOOGABAR_NODE_NODE_H

/**
 * @brief TreeSet 내부에서 사용할 Node class
 */
template <typename T> class Node {
public:
  Node(T key)
      : key_(key), left_(nullptr), right_(nullptr), height_(1), sub_size_(1) {}

  // key의 getter / setter
  T get_key() const { return key_; }
  void set_key(int key) { key_ = key; } // *delete 외엔 사용 금지*

  // left child의 getter / setter
  Node<T> *get_left() const { return left_; }
  void set_left(Node<T> *node) { left_ = node; }

  // right child의 getter / setter
  Node<T> *get_right() const { return right_; }
  void set_right(Node<T> *node) { right_ = node; }

  // Node의 Height 갱신용 함수
  int get_height() const { return height_; }
  void set_height(int height) { height_ = height; }

  // sub tree size 갱신용 함수
  int get_sub_size() const { return sub_size_; }
  void set_sub_size(int size) { sub_size_ = size; }

private:
  T key_;
  Node<T> *left_;
  Node<T> *right_;
  int height_;
  int sub_size_;
};

#endif