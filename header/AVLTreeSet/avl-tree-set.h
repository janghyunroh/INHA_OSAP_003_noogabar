
// Valid-License-Identifier: Apache-2.0

// SPDX-URL: https://spdx.org/licenses/Apache-2.0.html
// Version 2.0, January 2004
// http://www.apache.org/licenses/LICENSE-2.0

// Copyright November 2023 Inha Univ. Open Source Project Team noogabar

#ifndef AVL_H
#define AVL_H

#include "INHA_OSAP_003_noogabar/header/TreeSet/tree-set.h"

/**
 * 사용자 정의 소멸자 / 사용자 정의 복사 생성자 / 사용자 정의 대입 연산자
 * 는 필요 없을 것으로 예상되므로 구현할 필요 없을 것 같습니다.
 */
template <typename T> class AVLTreeSet : public TreeSet<T> {
public:
  // 생성자는 기본 생성자만으로 충분할 것 같아 제거하였습니다.

  // Overriding fuinctions
  T Maximum(T arg) override;
  T Minimum(T arg) override;

  int Find(T arg) override;
  int Insert(T arg) override;

  int Size() override;
  int Rank(T arg) override;

  bool Empty() override;
  int Erase(T arg) override;

  //디버깅
  void debug() override;
  void debugBFS() override;

  // Original functions
  int Height(Node<T> *node);
  int HeightDiff(Node<T> *node);
  Node<T> *RR(Node<T> *node);
  Node<T> *LL(Node<T> *parent);
  Node<T> *RL(Node<T> *parent);
  Node<T> *LR(Node<T> *parent);
  Node<T> *Balancing(Node<T> *node);
  Node<T> *Search(T arg);
  int UpdateHeight(Node<T> *node) {
    return 1 + max(Height(node->get_left()), Height(node->get_right()));
  }

  int UpdateSubSize(Node<T> *node) {
    int left_size = node->get_left() ? node->get_left()->get_sub_size() : 0;
    int right_size = node->get_right() ? node->get_right()->get_sub_size() : 0;
    return 1 + left_size + right_size;
  }

  // 기타 추가 구현 함수
  Node<T> *InsertN(Node<T> *node, T arg);
  int GetTreeSize(Node<T> *node);
  Node<T> *Delete(Node<T> *node, T key);
  void Inorder(Node<T> *node);
};

#endif // !AVL_H
