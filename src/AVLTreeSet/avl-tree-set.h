
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

/**
 * 이하는 AVLTreeSet class의 함수를 구현한 부분입니다.
 * 템플릿을 사용했기 때문에 어쩔 수 없이 헤더파일에 구현을 다 넣었습니다.
 * 이는 템플릿의 특성상, 불가피한 일입니다. 
 * 
 * 컴파일 타임의 축소보다 클래스의 확장성이 우선시되어야 한다고 판단했고,
 * 이에 따라 헤더의 크기가 커지는 것을 감수하고 정의를 헤더에 추가하였습니다. 
 * 
 * 위 모든 함수의 정의부를 포함하기에 헤더가 상당히 클 것입니다. 
 */

//====================Original 함수====================

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

//====================Overriding 함수====================

//1. Minimum, Maximum

/**
 * @brief arg를 key 값으로 가진 노드를 root로 하는 서브 트리 내에서 최소 key를
 * 반환하는 함수
 *
 * @param arg
 * @return int
 *
 * arg 값을 key로 받아 해당 노드를 검색한 뒤
 * 해당 서브 트리에서 최소 노드를 찾아 key 반환
 *
 * 만약 해당 노드가 존재하지 않는 경우 NULL 반환
 */
template <typename T> T AVLTreeSet<T>::Minimum(T arg) {
  Node<T> *node = Search(arg);
  while (node->get_left()) {
    node = node->get_left();
  }
  T minKey = node->get_key();
  return minKey;
}

/**
 * @brief arg를 key 값으로 가진 노드를 root로 하는 서브 트리 내에서 최대 key를
 * 반환하는 함수
 *
 * @param arg
 * @return int
 *
 * arg 값을 key로 받아 해당 노드를 검색한 뒤
 * 해당 서브 트리에서 최대 노드를 찾아 key 반환
 *
 * 만약 해당 노드가 존재하지 않는 경우 NULL 반환
 */
template <typename T> T AVLTreeSet<T>::Maximum(T arg) {
  Node<T> *node = Search(arg);
  while (node->get_right()) {
    node = node->get_right();
  }
  T maxKey = node->get_key();
  return maxKey;
}

//2. Find, Insert, InsertRecursive

/**
 * @brief
 *
 * @tparam T
 * @param arg key 값
 * @return int
 * @tparam T
 * @param arg
 * @return int
 * depth 반환, 없을 시 0 반환
 */
template <typename T> int AVLTreeSet<T>::Find(T arg) {
  Node<T> *cur_node = this->get_root();
  int depth = 0;
  while (cur_node != nullptr) { // tree의 맨 하단까지 내려가며 있는지 확인
    if (arg == cur_node->get_key())
      return depth;
    cur_node = ((arg > cur_node->get_key()) ? cur_node->get_right()
                                            : cur_node->get_left());
    depth++;
  }

  //없는 경우 0 반환
  return 0;
}

/**
 * @brief
 *
 * @param arg
 * @return int
 * 삽입 성공 시 depth 반환, 이미 존재하는 경우 -1 반환
 */
template <typename T> int AVLTreeSet<T>::Insert(T arg) {
  // 비어있는 tree인지 확인 후, 비어있으면 root로 삽입
  if (Size() == 0) {
    Node<T> *new_node = new Node<T>(arg);
    this->set_root(new_node);
    this->IncreaseSize();
    return 0;
  }

  Node<T> *insert_position = this->get_root();
  // arg의 값을 갖는 노드가 이미 존재하는지 확인
  if (Search(arg) != nullptr) {
    return -1;
  }

  // root에서부터 타고 내려가며 삽입할 위치 찾기
  this->set_root(InsertRecursive(insert_position, arg));
  this->IncreaseSize();
  return Find(arg);
}

/**
 * @brief 이미 존재하는 키 혹은 루트로 삽입하는 경우 외의 삽입을 재귀적으로 처리하는 함수
 * 
 * @param node 
 * @param arg 
 * @return template <typename T>* 
 */

template <typename T>
Node<T> *AVLTreeSet<T>::InsertRecursive(Node<T> *node, T arg) {

  //종단 노드에 도달한 경우
  if (node == nullptr) {
    node = new Node<T>(arg);
    return node;
  }

  //왼쪽으로 탐색 / 들어가게 되는 경우
  else if (node->get_key() > arg) {
    node->set_left(InsertRecursive(node->get_left(), arg));
    node = Balancing(node);
  }

  //오른쪽으로 탐색 / 들어가게 되는 경우
  else {
    node->set_right(InsertRecursive(node->get_right(), arg));
    node = Balancing(node);
  }
  return node;
}

//3. Size, Rank

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
  Node<T> *cur_node = this->get_root();
  int cnt = 0;
  while (cur_node != nullptr) {
    if (cur_node->get_key() == arg) {
      cnt +=
          (cur_node->get_left() ? cur_node->get_left()->get_sub_size() : 0) + 1;
      break;
    } else if (cur_node->get_key() < arg) {
      cnt +=
          (cur_node->get_left() ? cur_node->get_left()->get_sub_size() : 0) + 1;
      cur_node = cur_node->get_right();
    } else {
      cur_node = cur_node->get_left();
    }
  }
  return cnt;
}

//4. Empty, Erase, Delete

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

#endif // !AVL_H
