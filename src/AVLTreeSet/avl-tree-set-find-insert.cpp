// // Valid-License-Identifier: Apache-2.0

// // SPDX-URL: https://spdx.org/licenses/Apache-2.0.html
// // Version 2.0, January 2004
// // http://www.apache.org/licenses/LICENSE-2.0

// // Copyright November 2023 Inha Univ. Open Source Project Team noogabar
// // 담당자: 김예진

// #include "AVLTreeSet/avl-tree-set.h"

// /**
//  * @brief
//  *
//  * @tparam T
//  * @param arg key 값
//  * @return int
//  * @tparam T
//  * @param arg
//  * @return int
//  * depth 반환, 없을 시 0 반환
//  */
// template <typename T> int AVLTreeSet<T>::Find(T arg) {
//   Node<T> *cur_node = this->get_root();
//   int depth = 0;
//   while (cur_node != nullptr) { // tree의 맨 하단까지 내려가며 있는지 확인
//     if (arg == cur_node->get_key())
//       return depth;
//     cur_node = ((arg > cur_node->get_key()) ? cur_node->get_right()
//                                             : cur_node->get_left());
//     depth++;
//   }

//   //없는 경우 0 반환
//   return 0;
// }

// /**
//  * @brief
//  *
//  * @param arg
//  * @return int
//  * 삽입 성공 시 depth 반환, 이미 존재하는 경우 -1 반환
//  */
// template <typename T> int AVLTreeSet<T>::Insert(T arg) {
//   // 비어있는 tree인지 확인 후, 비어있으면 root로 삽입
//   if (Size() == 0) {
//     Node<T> *new_node = new Node<T>(arg);
//     this->set_root(new_node);
//     this->IncreaseSize();
//     return 0;
//   }

//   Node<T> *insert_position = this->get_root();
//   // arg의 값을 갖는 노드가 이미 존재하는지 확인
//   if (Search(arg) != nullptr) {
//     return -1;
//   }

//   // root에서부터 타고 내려가며 삽입할 위치 찾기
//   this->set_root(InsertRecursive(insert_position, arg));
//   this->IncreaseSize();
//   return Find(arg);
// }

// //====================기타 구현 함수====================

// /// @brief 이미 존재하는 키 혹은 루트로 삽입하는 경우 외의 삽입을 재귀적으로
// /// 처리하는 함수
// /// @tparam T
// /// @param node
// /// @param arg
// /// @return
// template <typename T>
// Node<T> *AVLTreeSet<T>::InsertRecursive(Node<T> *node, T arg) {

//   //종단 노드에 도달한 경우
//   if (node == nullptr) {
//     node = new Node<T>(arg);
//     return node;
//   }

//   //왼쪽으로 탐색 / 들어가게 되는 경우
//   else if (node->get_key() > arg) {
//     node->set_left(InsertRecursive(node->get_left(), arg));
//     node = Balancing(node);
//   }

//   //오른쪽으로 탐색 / 들어가게 되는 경우
//   else {
//     node->set_right(InsertRecursive(node->get_right(), arg));
//     node = Balancing(node);
//   }
//   return node;
// }