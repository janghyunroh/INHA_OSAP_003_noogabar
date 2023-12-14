// Valid-License-Identifier: Apache-2.0

// SPDX-URL: https://spdx.org/licenses/Apache-2.0.html
// Version 2.0, January 2004
// http://www.apache.org/licenses/LICENSE-2.0

// Copyright November 2023 Inha Univ. Open Source Project Team noogabar

#ifndef NODE_H
#define NODE_H

/**
 * @brief Tree 내부에서 사용할 Node class
 */
template <typename T> class Node {
public:
  Node(T key)
      : key_(key), left_(nullptr), right_(nullptr), height_(1), sub_size_(1) {}
  T get_key() { return key_; }
  Node<T> *get_left() { return left_; }
  void set_left(Node<T> *node) { left_ = node; }
  Node<T> *get_right() { return right_; }
  void set_right(Node<T> *node) { right_ = node; }
  int get_height() { return height_; }
  void set_height(int height) { height_ = height; }

  // delete Node용
  //이외엔 절대 사용하지 말 것
  void set_key(int key) { key_ = key; }

  //
  int get_sub_size() { return sub_size_; }
  void set_sub_size(int size) { sub_size_ = size; }

private:
  T key_;
  Node<T> *left_;
  Node<T> *right_;
  int height_;
  int sub_size_;
};

#endif