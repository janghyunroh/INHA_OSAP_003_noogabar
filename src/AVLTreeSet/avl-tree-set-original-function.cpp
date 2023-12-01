
#include "INHA_OSAP_003_noogabar/header/AVLTreeSet/avl-tree-set.h"
#include <algorithm>

using namespace std;

/**
 * @brief tree의 높이를 반환하는 함수
 *
 * @tparam T
 * @param node : 높이를 잴 sub-tree의 루트 노드
 * @return int : 높이 h
 */
template <typename T> int AVLTreeSet<T>::Height(Node<T> *node) {
  int height = 0;
  if (node != nullptr) {
    int left = Height(node->get_left());
    int right = Height(node->get_right());
    int height = max(left, right) + 1;
  }
  return height;
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
  return new_parent;
}

/**
 * @brief RL 연산
 *
 * @tparam T
 * @param parent
 * @return Node<T>*
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
 */
template <typename T> Node<T> *AVLTreeSet<T>::Balancing(Node<T> *node) {
  int height_difference = HeightDiff(node);

  if (height_difference > 1) {            // LL or LR
    if (HeightDiff(node->get_left()) > 0) // LL
      return LL(node);
    else
      return LR(node);
  } else if (height_difference < -1) {     // RR or LR
    if (HeightDiff(node->get_right()) > 0) // RL
      return RL(node);
    else
      return RR(node);
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
 * 전임하면서 확장성을 확보합니다. 이번 채점 서버에선 int 형에 대한 set 사용만
 * 다루므로 별도의 오버라이딩이 필요 없을 것입니다.
 */
template <typename T> Node<T> *AVLTreeSet<T>::Search(T arg) {
  Node<T> *curN = this->get_root();
  while (curN != nullptr) { // tree의 맨 하단까지 내려가며 있는지 확인
    if (arg == curN->get_key())
      return curN;
    curN = (arg > curN->get_key()) ? curN->get_right() : curN->get_left();
  }
  return nullptr;
}

// // tree에 삽입하는 함수
// int AVLTree::Insert(int arg) {
//   Node *node = new Node();
//   node->key_ = arg;
//   if (this->root_ == nullptr) {
//     this->root_ = node;
//     return;
//   }

//   Node *grand_parent_node = nullptr;
//   Node *parent_node = nullptr;
//   Node *current_node = this->root_;

//   while (current_node != nullptr) {
//     // 현재 노드의 값보다 크면 오른쪽으로 내려가고 작으면 왼쪽으로 내려간다.
//     if (arg > current_node->key_) {
//       grand_parent_node = parent_node;
//       parent_node = current_node;
//       current_node = current_node->right_;
//     } else {
//       grand_parent_node = parent_node;
//       parent_node = current_node;
//       current_node = current_node->right_;
//     }
//   }

//   if (arg > parent_node->key_) {
//     parent_node->right_ = node;
//   } else {
//     parent_node->left_ = node;
//   }

//   Balancing(grand_parent_node);
// }

// int AVLTree::Erase(int arg) {}
