// // Valid-License-Identifier: Apache-2.0

// // SPDX-URL: https://spdx.org/licenses/Apache-2.0.html
// // Version 2.0, January 2004
// // http://www.apache.org/licenses/LICENSE-2.0

// // Copyright November 2023 Inha Univ. Open Source Project Team noogabar
// // 담당자: 류지훈

// #include "AVLTreeSet/avl-tree-set.h"

// /**
//  * @brief arg를 key 값으로 가진 노드를 root로 하는 서브 트리 내에서 최소 key를
//  * 반환하는 함수
//  *
//  * @param arg
//  * @return int
//  *
//  * arg 값을 key로 받아 해당 노드를 검색한 뒤
//  * 해당 서브 트리에서 최소 노드를 찾아 key 반환
//  *
//  * 만약 해당 노드가 존재하지 않는 경우 NULL 반환
//  */
// template <typename T> T AVLTreeSet<T>::Minimum(T arg) {
//   Node<T> *node = Search(arg);
//   while (node->get_left()) {
//     node = node->get_left();
//   }
//   T minKey = node->get_key();
//   return minKey;
// }

// /**
//  * @brief arg를 key 값으로 가진 노드를 root로 하는 서브 트리 내에서 최대 key를
//  * 반환하는 함수
//  *
//  * @param arg
//  * @return int
//  *
//  * arg 값을 key로 받아 해당 노드를 검색한 뒤
//  * 해당 서브 트리에서 최대 노드를 찾아 key 반환
//  *
//  * 만약 해당 노드가 존재하지 않는 경우 NULL 반환
//  */
// template <typename T> T AVLTreeSet<T>::Maximum(T arg) {
//   Node<T> *node = Search(arg);
//   while (node->get_right()) {
//     node = node->get_right();
//   }
//   T maxKey = node->get_key();
//   return maxKey;
// }