// Valid-License-Identifier: Apache-2.0

// SPDX-URL: https://spdx.org/licenses/Apache-2.0.html
// Version 2.0, January 2004
// http://www.apache.org/licenses/LICENSE-2.0

// Copyright November 2023 Inha Univ. Open Source Project Team noogabar
#include "INHA_OSAP_003_noogabar/header/AVLTreeSet/avl-tree-set.h"

// 담당자: 이정현

/**
 * @brief Set의 크기를 반환하는 함수
 *
 * @tparam T
 * @return int
 */
template <typename T> int AVLTreeSet<T>::Size() { return this->get_size(); }

/**
 * @brief 찾는 노드의 rank를 반환하는 함수
 *
 * @tparam T
 * @param arg
 * @return int
 */
template <typename T> int AVLTreeSet<T>::Rank(T arg) {
  Node<T> *node = Search(arg);
  // tree에 노드가 없다면 0 return
  if (node == nullptr) {
    return 0;
  }
  // left child를 root로 하는 서브크기가 곧 해당 노드보다 작은 원소의 개수
  Node<T> *curN = this->get_root();
  int cnt = 0;
  while (curN != nullptr) {
    if (curN->get_key() == arg) {
      cnt += (curN->get_left() ? curN->get_left()->get_sub_size() : 0) + 1;
      break;
    } else if (curN->get_key() < arg) {
      cnt += (curN->get_left() ? curN->get_left()->get_sub_size() : 0) + 1;
      curN = curN->get_right();
    } else {
      curN = curN->get_left();
    }
  }
  return cnt;
}

//====================기타 구현 함수====================
/**
 * @brief node를 root로 하는 서브트리의 size를 구하는 함수
 *
 * @tparam T
 * @param node
 * @param x
 * @return int
 */
template <typename T> int AVLTreeSet<T>::GetTreeSize(Node<T> *node) {
  if (!node) {
    return 0;
  }
  int cnt = 1;
  cnt += GetTreeSize(node->get_left());
  cnt += GetTreeSize(node->get_right());
  return cnt;
}
