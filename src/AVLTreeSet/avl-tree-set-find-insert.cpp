// Valid-License-Identifier: Apache-2.0

// SPDX-URL: https://spdx.org/licenses/Apache-2.0.html
// Version 2.0, January 2004
// http://www.apache.org/licenses/LICENSE-2.0

// Copyright November 2023 Inha Univ. Open Source Project Team noogabar
#include "INHA_OSAP_003_noogabar/header/AVLTreeSet/avl-tree-set.h"

// 담당자: 김예진

/**
 * @brief
 *
 * @tparam T
 * @param arg key 값
 * @return int depth 반환, 없을 시 0 반환
 * @tparam T
 * @param arg
 * @return int
 */
template <typename T> int AVLTreeSet<T>::Find(T arg) {
  Node<T> *curN = this->get_root();
  int depth = 0;
  while (curN != nullptr) { // tree의 맨 하단까지 내려가며 있는지 확인
    if (arg == curN->get_key())
      return depth;
    curN = ((arg > curN->get_key()) ? curN->get_right() : curN->get_left());
    depth++;
  }
  return 0;
}

/**
 * @brief
 *
 * @param arg
 * @return int
 */
template <typename T> int AVLTreeSet<T>::Insert(T arg) {
  // 비어있는 tree인지 확인 후, 비어있으면 root로 삽입
  if (Size() == 0) {
    Node<T> *newN = new Node<T>(arg);
    this->set_root(newN);
    this->IncreaseSize();
    return 0;
  }

  Node<T> *parN = this->get_root();
  // arg의 값을 갖는 노드가 이미 존재하는지 확인
  if (Find(arg) > 0 || arg == parN->get_key()) {
    return -1;
  }

  this->set_root(InsertN(parN, arg));
  this->IncreaseSize();
  return Find(arg);
}

//====================기타 구현 함수====================

/// @brief 이미 존재하는 키 혹은 루트로 삽입하는 경우 외의 삽입을 처리하는 함수
/// @tparam T
/// @param node
/// @param arg
/// @return
template <typename T> Node<T> *AVLTreeSet<T>::InsertN(Node<T> *node, T arg) {

  //종단 노드에 도달한 경우
  if (node == nullptr) {
    node = new Node<T>(arg);
    return node;
  }

  //왼쪽으로 탐색 / 들어가게 되는 경우
  else if (node->get_key() > arg) {
    node->set_left(InsertN(node->get_left(), arg));
    node = Balancing(node);
  }

  //오른쪽으로 탐색 / 들어가게 되는 경우
  else {
    node->set_right(InsertN(node->get_right(), arg));
    node = Balancing(node);
  }
  return node;
}