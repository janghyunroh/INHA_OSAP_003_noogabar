
// Valid-License-Identifier: Apache-2.0

// SPDX-URL: https://spdx.org/licenses/Apache-2.0.html
// Version 2.0, January 2004
// http://www.apache.org/licenses/LICENSE-2.0

// Copyright November 2023 Inha Univ. Open Source Project Team noogabar

#ifndef INHA_OSAP_003_NOOGABAR_AVLTREESET_AVL_H
#define INHA_OSAP_003_NOOGABAR_AVLTREESET_AVL_H

#include "TreeSet/tree-set.h"

/**
 * @brief AVLTreeSet class
 * AVLTree를 이용한 Set class 구현
 *
 *
 */
template <typename T> class AVLTreeSet : public TreeSet<T> {
public:
  // Overriding fuinctions
  T Maximum(T arg) override;
  T Minimum(T arg) override;

  int Find(T arg) override;
  int Insert(T arg) override;

  int Size() override;
  int Rank(T arg) override;

  bool Empty() override;
  int Erase(T arg) override;

  // Original functions
  int Height(Node<T> *node);
  int HeightDiff(Node<T> *node);
  Node<T> *RR(Node<T> *node);
  Node<T> *LL(Node<T> *parent);
  Node<T> *RL(Node<T> *parent);
  Node<T> *LR(Node<T> *parent);
  Node<T> *Balancing(Node<T> *node);
  Node<T> *Search(T arg);

  // Height 갱신 함수
  int UpdateHeight(Node<T> *node) {
    return 1 + (Height(node->get_left()) > Height(node->get_right())
                    ? Height(node->get_left())
                    : Height(node->get_right()));
  }

  // Sub Tree Size 갱신 함수
  int UpdateSubSize(Node<T> *node) {
    int left_size = node->get_left() ? node->get_left()->get_sub_size() : 0;
    int right_size = node->get_right() ? node->get_right()->get_sub_size() : 0;
    return 1 + left_size + right_size;
  }

  // 기타 추가 구현 함수
  Node<T> *InsertRecursive(Node<T> *node, T arg);
  Node<T> *Delete(Node<T> *node, T key);
};

#endif // !AVL_H
