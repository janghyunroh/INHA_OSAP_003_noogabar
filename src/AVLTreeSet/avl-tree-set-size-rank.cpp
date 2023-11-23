#include "/INHA_OSAP_003_NOOGABAR/header/AVLTreeSet/avl-tree-set.h"

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
  if (node == nullptr)
    return {0, 0};
  int rank = CalculateRank(getroot(), arg) + 1;
  return rank;
}

//====================기타 구현 함수====================

// rank를 return하는 함수
// rank는 x보다 작은 수로 정의
template <typename T1, typename T2>
int AVLTreeSet<T1, T2>::CalculateRank(Node<T1, T2> *node, int x) {
  if (!node)
    return 0;
  int cnt = 0;
  if (node->key < x) {
    cnt++;
  }
  cnt += CalculateRank(node->left, x);
  cnt += CalculateRank(node->right, x);
  return cnt;
}