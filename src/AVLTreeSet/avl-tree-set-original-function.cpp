// Valid-License-Identifier: Apache-2.0

// SPDX-URL: https://spdx.org/licenses/Apache-2.0.html
// Version 2.0, January 2004
// http://www.apache.org/licenses/LICENSE-2.0

// Copyright November 2023 Inha Univ. Open Source Project Team noogabar

#include "header/AVLTreeSet/avl-tree-set.h"

using namespace std;

/**
 * @brief tree의 높이를 반환하는 함수
 *
 * @tparam T
 * @param node : 높이를 잴 sub-tree의 루트 노드
 * @return int : 높이 h
 */
template <typename T> int AVLTreeSet<T>::Height(Node<T> *node) {
  return node ? node->get_height() : 0;
}

/**
 * @brief 왼쪽 자식 높이 -  오른쪽 자식의 높이 반환
 *
 * @tparam T
 * @param node : 비교할 두 노드의 부모 노드
 * @return int : leftH - rightH
 *
 * 음수이면 오른쪽 자식, 양수이면 왼쪽 자식의 높이가 큰 것
 */
template <typename T> int AVLTreeSet<T>::HeightDiff(Node<T> *node) {
  if (node == nullptr)
    return 0;
  return Height(node->get_left()) - Height(node->get_right());
}

/**
 * @brief 오른쪽으로 길어졌을 때의 rotation
 *
 * @tparam T
 * @param parent
 * @return Node<T>*
 */
template <typename T> Node<T> *AVLTreeSet<T>::RR(Node<T> *parent) {
  Node<T> *new_parent = parent->get_right(); // right가 parent의 위로 올라간다
  parent->set_right(new_parent->get_left());
  new_parent->set_left(parent);

  // rotation 후 높이 갱신
  parent->set_height(UpdateHeight(parent));
  new_parent->set_height(UpdateHeight(new_parent));

  // rotation 후 sub_size 갱신
  parent->set_sub_size(UpdateSubSize(parent));
  new_parent->set_sub_size(UpdateSubSize(new_parent));

  return new_parent;
}

/**
 * @brief 왼쪽으로 길어졌을 때의 rotation
 *
 * @tparam T
 * @param parent
 * @return Node<T>*
 */
template <typename T> Node<T> *AVLTreeSet<T>::LL(Node<T> *parent) {
  Node<T> *new_parent = parent->get_left();
  parent->set_left(new_parent->get_right());
  new_parent->set_right(parent);

  // rotation 후 높이 갱신
  parent->set_height(UpdateHeight(parent));
  new_parent->set_height(UpdateHeight(new_parent));

  // rotation 후 sub_size 갱신
  parent->set_sub_size(UpdateSubSize(parent));
  new_parent->set_sub_size(UpdateSubSize(new_parent));

  return new_parent;
}

/**
 * @brief RL 연산
 *
 * @tparam T
 * @param parent
 * @return Node<T>*
 *
 * 아래 두 노드 y, x에 대한 LL 연산 후
 * z와 y에 대한 RR 연산을 수행
 */
template <typename T> Node<T> *AVLTreeSet<T>::RL(Node<T> *parent) {
  parent->set_right(LL(parent->get_right()));
  return RR(parent);
}

/**
 * @brief LR 연산
 *
 * @tparam T
 * @param parent
 * @return Node<T>*
 *
 * 아래 두 노드 y, x에 대한 RR 연산 후
 * z와 y에 대한 LL 연산을 수행
 */
template <typename T> Node<T> *AVLTreeSet<T>::LR(Node<T> *parent) {
  parent->set_left(RR(parent->get_left()));
  return LL(parent);
}

/**
 * @brief 균형이 깨진 경우 균형을 잡는 함수
 *
 * @tparam T
 * @param node
 * @return Node<T>*
 *
 * 채점 서버에서 제시한 조건에 따라
 * y노드의 두 자식 노드의 높이가 같은 경우
 * single rotation을 수행하도록 하였습니다.
 */
template <typename T> Node<T> *AVLTreeSet<T>::Balancing(Node<T> *node) {
  int height_difference = HeightDiff(node);

  if (height_difference > 1) { // LL or LR
    if (HeightDiff(node->get_left()) >= 0)
      return LL(node); // LL
    else
      return LR(node); // LR
  }

  else if (height_difference < -1) { // RR or LR
    if (HeightDiff(node->get_right()) > 0)
      return RL(node); // RL
    else
      return RR(node); // RR
  }

  // rotation 후 height와 sub tree size 갱신
  if (node != nullptr) {
    node->set_height(UpdateHeight(node));
    node->set_sub_size(UpdateSubSize(node));
  }
  return node;
}

/**
 * @brief key 값에 해당하는 "노드"를 반환
 *
 * @tparam T
 * @param arg key 값
 * @return Node<T>* 해당 노드 반환, 없을 시 NULL 반환
 *
 * type T에 대한 비교 연산자 '==' 과 '>' 의 오버라이딩을 해당 클래스에게
 * 전임하면서 확장성을 확보합니다.
 */
template <typename T> Node<T> *AVLTreeSet<T>::Search(T arg) {
  Node<T> *cur_node = this->get_root();
  while (cur_node != nullptr) { // tree의 맨 하단까지 내려가며 있는지 확인
    if (arg == cur_node->get_key())
      return cur_node;
    cur_node = (arg > cur_node->get_key()) ? cur_node->get_right()
                                           : cur_node->get_left();
  }
  return nullptr;
}