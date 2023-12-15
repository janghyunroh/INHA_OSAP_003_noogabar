// Valid-License-Identifier: Apache-2.0

// SPDX-URL: https://spdx.org/licenses/Apache-2.0.html
// Version 2.0, January 2004
// http://www.apache.org/licenses/LICENSE-2.0

// Copyright November 2023 Inha Univ. Open Source Project Team noogabar

#include "../../header/AVLTreeSet/avl-tree-set.h"

// 담당자: 노장현

/**
 * @brief 해당 Set이 비어있는지 여부를 반환
 *
 * @tparam T
 * @return true
 * @return false
 */
template <typename T> bool AVLTreeSet<T>::Empty() {
  return (this->get_size() == 0);
}

/**
 * @brief 해당 Set에서 arg값을 key로 갖는 노드를 삭제
 * 삭제 전 해당 노드의 depth를 저장했다가 재배치 이후 반환
 * 해당 노드가 없을 경우 0 반환
 * @tparam T
 * @param arg
 * @return int
 */
template <typename T> int AVLTreeSet<T>::Erase(T arg) {

  // 존재하지 않는 노드에 대한 삭제 연산
  Node<T> *node = this->Search(arg);
  if (node == nullptr) {
    return 0;
  }

  // 반환할 depth 값 저장
  int depth = this->Find(arg);

  // delete 수행(별도 함수)
  this->set_root(Delete(this->get_root(), arg));
  this->set_root(Balancing(this->get_root()));

  // size 감소
  this->DecreaseSize();

  // depth 반환
  return depth;
}

//====================기타 구현 함수====================
/**
 * @brief 해당 노드를 루트로 하는 서브트리에서 arg값을 key로 갖는 노드를 삭제
 * 실질적인 삭제는 이 함수에서 이루어짐
 * 구조 재구성을 위해 find처럼 재귀적으로 호출
 * @tparam T
 * @param node
 * @param arg
 * @return int
 */
template <typename T> Node<T> *AVLTreeSet<T>::Delete(Node<T> *node, T key) {

  // 종단 도달 처리용
  if (node == nullptr) {
    return node;
  }

  // 삭제할 노드가 왼쪽에 존재하는 경우
  if (node->get_key() > key) {
    node->set_left(Delete(node->get_left(), key));
  }

  // 삭제할 노드가 오른쪽에 존재하는 경우
  else if (node->get_key() < key) {
    node->set_right(Delete(node->get_right(), key));
  }

  //찾은 경우
  else {

    // 1. 삭제할 노드의 양쪽 자식 노드가 모두 외부 노드인 경우
    if ((node->get_left() == nullptr) && (node->get_right() == nullptr)) {
      node = nullptr;
    }

    // 2. 오른쪽만 외부 노드인 경우
    else if (node->get_right() == nullptr) {
      node = node->get_left();
    }

    // 3. 왼쪽만 외부 노드인 경우
    else if (node->get_left() == nullptr) {
      node = node->get_right();
    }

    // 4. 양쪽 다 내부 노드인 경우 - 후임자 찾기
    else {

      Node<T> *successor = node->get_right();
      while (successor->get_left() != nullptr) {
        successor = successor->get_left();
      }

      //후임자 복사 및 기존 후임자 제거
      node->set_key(successor->get_key());
      node->set_right(Delete(node->get_right(), successor->get_key()));
    }
  }

  //삭제 후 재구성
  node = Balancing(node);
  return node;
}