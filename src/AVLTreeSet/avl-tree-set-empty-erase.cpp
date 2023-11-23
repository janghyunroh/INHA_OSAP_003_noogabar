#include "/INHA_OSAP_003_NOOGABAR/header/AVLTreeSet/avl-tree-set.h"

//담당자: 노장현

/**
 * @brief
 *
 * @tparam T
 * @return true
 * @return false
 */
template <typename T1, typename T2> bool AVLTreeSet<T1, T2>::Empty() {
  return (this->Size() == 0);
}

/**
 * @brief
 *
 * @tparam T
 * @param arg
 * @return int
 */
template <typename T1, typename T2> int AVLTreeSet<T1, T2>::Erase(T1 arg) {}

//====================기타 구현 함수====================