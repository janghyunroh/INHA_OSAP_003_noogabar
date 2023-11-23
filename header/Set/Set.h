#ifndef SET_H
#define SET_H

template <typename T1, typename T2> class Set {
public:
  /**
   * @brief arg값을 key로 갖는 노드를 root로 갖는 sub-tree에서의 최소 key 노드의
   * "key" 반환
   *
   * @param arg : sub-tree의 root 노드의 key
   * @return int : 최소 key 노드의 key
   */
  virtual T1 Maximum(T1 arg) {}

  /**
   * @brief arg값을 key로 갖는 노드를 root로 갖는 sub-tree에서의 최대 key 노드의
   * "key" 반환
   *
   * @param arg : sub-tree의 root 노드의 key
   * @return int : 최대 key 노드의 key
   */
  virtual T1 Minimum(T1 arg) {}

  /**
   * @brief Set이 비어있는지 아닌지 확인
   *
   * @return true : Set의 원소 개수 = 0
   * @return false : Set의 원소 개수 > 0
   */
  virtual bool Empty() {}

  /**
   * @brief Set의 원소 개수 반환
   *
   * @return int : Set의 원소의 개수
   */
  virtual int Size() {}

  /**
   * @brief Set에 존재하는 arg값을 key로 갖는 노드의 depth 반환
   *
   * @param arg : 찾는 노드의 key
   * @return int : 해당 노드의 depth
   */
  virtual int Find(T1 arg) {}

  /**
   * @brief 신규 노드 생성하여 삽입
   *
   * @param arg : 삽입할 노드의 key값
   * @return int : 삽입된 위치에서의 depth
   */
  virtual int Insert(T1 arg) {}

  /**
   * @brief 특정 노드의 rank 계산 함수
   *
   * @param arg : 계산할 노드의 key값
   * @return int : 해당 노드의 rank (없으면 0)
   */
  virtual int Rank(T1 arg) {}

  /**
   * @brief 특정 노드 삭제
   *
   * @param arg : 삭제할 노드의 key값
   * @return int : 삭제하기 전 해당 노드의 depth (없으면 0)
   */
  virtual int Erase(T1 arg) {}

  // size는 set에서 처리하고 getter도 짧은 함수이므로 헤더에서 구현했습니다
  int getsize() { return this->size_; }

private:
  int size_; // Set의 크기
};

#endif

//이전 구현 코드는 주석 형태로 보관하다 이후 삭제하겠습니다

// #include "AVL.h"
// #include <utility>

// class Set {

// public:
//   Set(AVLTree *tree) : tree_(tree), size_(0) {}
//   std::pair<int, int> Minimum(int arg) {}
//   std::pair<int, int> Maximum(int arg) {}
//   bool Empty() {}
//   int Size() {}
//   int Find(int arg) {}
//   int Insert(int arg) {}
//   int Rank(int arg) {}
//   int Erase(int arg) {}

// private:
//   AVLTree *tree_;
//   int size_;
// };