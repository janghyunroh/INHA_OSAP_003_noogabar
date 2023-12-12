// Valid-License-Identifier: Apache-2.0

// SPDX-URL: https://spdx.org/licenses/Apache-2.0.html
// Version 2.0, January 2004
// http://www.apache.org/licenses/LICENSE-2.0

// Copyright November 2023 Inha Univ. Open Source Project Team noogabar
#include "INHA_OSAP_003_noogabar/header/AVLTreeSet/avl-tree-set.h"

// 담당자: 노장현

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
  this->set_root(Delete(this->get_root(), arg, nullptr));

  // size 감소
  this->DecreaseSize();

  // depth 반환
  return depth;
}

//====================기타 구현 함수====================
/**
 * @brief 해당 노드를 루트로 하는 서브트리에서 arg값을 key로 갖는 노드를 삭제
 * 실질적인 삭제는 이 함수에서 이루어짐
 * 구조 재구성을 위해 find처럼 재귀적으로 호출
 *
 * ** parent 데이터를 Node에 추가하는 대신 parent를 인자로 받아서 사용 **
 * @tparam T
 * @param node
 * @param arg
 * @return int
 */
template <typename T> Node<T> Delete(Node<T> *root, T key, Node<T> *parent) {

  // 노드가 존재하지 않을 경우
  /**
   * 재귀 수행 때문에 종단 노드에 도착하는 경우를 처리하기 위한 구문이며,
   * 실제로 없는 노드를 삭제하는 경우는 상위 함수인 Erase에서 걸러지므로
   * Size 문제는 걱정 없을 것으로 보입니다.
   */
  if (root == nullptr) {
    return nullptr;
  }

  // 재귀적 탐색 - 좌측 서브 트리
  if (root->get_key() > key) {
    root->set_left(Delete(root->get_left(), key, root));
    root = Balancing(root);
  }

  // 재귀적 탐색 - 우측 서브 트리
  else if (root->get_key() < key) {
    root->set_right(Delete(root->get_right(), key, root));
    root = Balancing(root);
  }

  // 삭제할 노드를 찾았을 경우
  /**
   * root: 현재 노드(삭제할 노드)
   * parent: 현재 삭제할 노드의 부모 노드(대체할 노드와 연결하기 위해 참조 필요)
   */
  else {

    // 1. 삭제할 노드의 양단이 모두 없는 경우 - 단순 삭제
    if ((root->get_left() == nullptr) && (root->get_right() == nullptr)) {
      root = nullptr;
    }

    // 2. 삭제할 노드의 좌측 서브 트리만 존재하는 경우
    /**
     * AVL Tree의 특성에 의해 삭제 노드의 좌측 서브 트리의 높이는 최대 1이다.
     * 따라서 그냥 삭제 노드의 좌측 노드를 삭제 노드의 위치로 옮기면 된다.
     * (nullptr인 경우도 문제 X)
     */
    else if (root->get_right() == nullptr) {
      Node<T> *temp = root->get_left();
      parent->set_left(temp);

    }

    // 3. 삭제할 노드의 우측 서브 트리만 존재하는 경우
    /**
     * AVL Tree의 특성에 의해 삭제 노드의 우측 서브 트리의 높이는 최대 1이다.
     * 따라서 그냥 삭제 노드의 우측 노드를 삭제 노드의 위치로 옮기면 된다.
     */
    else if (root->get_left() == nullptr) {
      Node<T> *temp = root->get_right();
      parent->set_right(temp);

    }

    // 4. 삭제할 노드의 양쪽 서브 트리가 모두 존재하는 경우 - 우측 서브 트리에서
    // 가장 작은 노드(후임자)를 찾아 대체
    else {
      Node<T> *deleteNode = root;

      // 우측 서브 트리에서 가장 작은 노드(후임자)를 찾아 대체
      Node<T> *successor = root->get_right();
      Node<T> *successorParent = root;
      while (successor->get_left() != nullptr) {
        successorParent = successor;
        successor = successor->get_left();
      }

      // 후임자의 부모 노드와 자식 노드를 연결
      successor->set_left(deleteNode->get_left());
      successor->set_right(deleteNode->get_right());

      // 후임자의 기존 위치를 nullptr로 초기화
      successorParent->set_left(nullptr);

      // 후임자를 삭제 노드의 위치로 옮기기(후임자의 부모 노드가 삭제 노드의
      // 부모 노드가 되도록)
      root = successor;

      delete deleteNode;
    }
  }
  return root;
}