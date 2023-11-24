#include "INHA_OSAP_003_noogabar/header/Node/node.h"

template <typename T1, typename T2> T1 getkey() { return this->key_; }

template <typename T1, typename T2> T1 getdata() { return this->data_; }

template <typename T1, typename T2> T1 getleft() { return this->left_; }

template <typename T1, typename T2> void setleft(Node<T1, T2> *node) {
  this->left = node;
}

template <typename T1, typename T2> T1 getright() { return this->right_; }

template <typename T1, typename T2> void setright(Node<T1, T2> *node) {
  this->right = node;
}
