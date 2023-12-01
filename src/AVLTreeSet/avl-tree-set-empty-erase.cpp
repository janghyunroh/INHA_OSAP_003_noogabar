#include "INHA_OSAP_003_noogabar/header/AVLTreeSet/avl-tree-set.h"

//담당자: 노장현

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
 *
 * @tparam T
 * @param arg
 * @return int
 */
template <typename T> int AVLTreeSet<T>::Erase(T arg) {}

//====================기타 구현 함수====================