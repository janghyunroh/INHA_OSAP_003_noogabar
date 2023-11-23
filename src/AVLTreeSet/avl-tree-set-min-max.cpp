#include "/INHA_OSAP_003_NOOGABAR/header/AVLTreeSet/avl-tree-set.h"

//담당자: 류지훈

/**
 * @brief 최소 노드의 depth
 *
 * @param arg
 * @return int
 *
 * arg 값을 key로 받아 해당 노드를 검색한 뒤
 * 해당 서브 트리에서 최소 노드를 찾아 key 반환
 *
 * 만약 해당 노드가 존재하지 않는 경우 NULL 반환
 */
template <typename T1, typename T2> T1 AVLTreeSet<T1, T2>::Minimum(T1 arg) {}

/**
 * @brief 최대 노드의 depth
 *
 * @param arg
 * @return int
 *
 * arg 값을 key로 받아 해당 노드를 검색한 뒤
 * 해당 서브 트리에서 최대 노드를 찾아 key 반환
 *
 * 만약 해당 노드가 존재하지 않는 경우 NULL 반환
 */
template <typename T1, typename T2> T1 AVLTreeSet<T1, T2>::Maximum(T1 arg) {}

/**
 * @brief 특정 key값의 노드가 Set에 존재하는지 확인
 *
 * @tparam T
 * @param arg
 * @return true
 * @return false
 */
template <typename T1, typename T2> bool AVLTreeSet<T1, T2>::Exists(T1 arg) {
  Node *node = Search(arg);
  if (node == nullptr)
    return false;
  return true;

  //끝까지 못 찾아 nullptr에 도달한 경우
  return false;
}

//====================기타 구현 함수====================