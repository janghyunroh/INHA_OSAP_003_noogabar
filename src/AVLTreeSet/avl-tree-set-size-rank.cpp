//#include "/INHA_OSAP_003_NOOGABAR/header/AVLTreeSet/avl-tree-set.h"
#include "../../header/AVLTreeSet/avl-tree-set.h"
//담당자: 이정현

/**
 * @brief Set의 크기를 반환하는 함수
 *
 * @tparam T
 * @return int
 */
template <typename T1, typename T2> int AVLTreeSet<T1, T2>::Size() {
  return this->getsize();
}

/**
 * @brief 찾는 노드의 rank를 반환하는 함수
 *
 * @tparam T
 * @param arg
 * @return int
 */
template <typename T1, typename T2> int AVLTreeSet<T1, T2>::Rank(T1 arg) {
  Node *node = Search(arg);
  // tree에 노드가 없다면 0 return
  if (node == nullptr) {
    return 0;
  }
  // left child를 root로 하는 서브크기가 곧 해당 노드보다 작은 원소의 개수
  int rank = GetTreeSize(node->left) + 1;
  return rank;
}

//====================기타 구현 함수====================

/**
 * @brief node를 root로 하는 서브트리의 size를 구하는 함수
 *
 * @tparam T1
 * @tparam T2
 * @param node
 * @param x
 * @return int
 */
template <typename T1, typename T2>
int AVLTreeSet<T1, T2>::GetTreeSize(Node<T1, T2> *node) {
  if (!node) {
    return 0;
  }
  int cnt = 1;
  cnt += GetTreeSize(node->left);
  cnt += GetTreeSize(node->right);
  return cnt;
}
