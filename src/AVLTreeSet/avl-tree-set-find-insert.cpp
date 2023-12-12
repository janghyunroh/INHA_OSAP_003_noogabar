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

  /*
  avl-tree-set original 함수에 search 함수 있으니까 해당 함수 활용하시면 될 것
  같습니다.
  */
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

  InsertN(parN, arg);
  this->IncreaseSize();
  return Find(arg);
}

//====================기타 구현 함수====================

template <typename T> void AVLTreeSet<T>::InsertN(Node<T> *parN, T arg) {
  if (parN->get_key() > arg) {
    if (parN->get_left() == nullptr) {
      Node<T> *newN = new Node<T>(arg);
      parN->set_left(newN);
      return;
    } else {
      InsertN(parN->get_left(), arg);
      Balancing(parN);
    }
  } else {
    if (parN->get_right() == nullptr) {
      Node<T> *newN = new Node<T>(arg);
      parN->set_right(newN);
      return;
    } else {
      InsertN(parN->get_right(), arg);
      Balancing(parN);
    }
  }
  return;
}