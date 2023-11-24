#ifndef AVL_H
#define AVL_H

#include "INHA_OSAP_003_noogabar/header/TreeSet/tree-set.h"

/**
 * 사용자 정의 소멸자 / 사용자 정의 복사 생성자 / 사용자 정의 대입 연산자
 * 는 필요 없을 것으로 예상되므로 구현할 필요 없을 것 같습니다.
 */
template <typename T1, typename T2> class AVLTreeSet : public TreeSet {
public:
  //생성자
  AVLTreeSet() : root_(NULL), size_(0) {}

  // Overriding fuinctions
  virtual T1 Maximum(T1 arg) override {}
  virtual T1 Minimum(T1 arg) override {}

  virtual int Find(T1 arg) override {}
  virtual int Insert(T1 arg) override {}

  virtual int Size() override {}
  virtual int Rank(T1 arg) override {}

  virtual bool Empty() override {}
  virtual int Erase(T1 arg) override {}

  // Original functions
  int Height(Node<T1, T2> *node) {}
  int HeightDiff(Node<T1, T2> *node) {}
  Node<T1, T2> *RR(Node<T1, T2> *node) {}
  Node<T1, T2> *LL(Node<T1, T2> *parent) {}
  Node<T1, T2> *LL(Node<T1, T2> *parent) {}
  Node<T1, T2> *RL(Node<T1, T2> *parent) {}
  Node<T1, T2> *LR(Node<T1, T2> *parent) {}
  Node<T1, T2> *Balancing(Node<T1, T2> *node) {}
  Node<T1, T2> *Search(T1 arg) {}

  //각 기능 구현에 필요한 추가적인 함수는 이곳 아래에 사용처와 함께 적어준 다음,
  //각자 담당 cpp 파일에서 구현해주세요.

  // Rank 함수 구현 중 key값이 존재하지 않는 경우를 걸러내기 위해 한 단계 걸쳐
  // 구현
  int GetTreeSize(Node<T1, T2> *node) {}

  // Min/Max 함수 구현 중 key값이 존재하지 않는 경우를 걸러내기 위해 main에서 한
  // 단계 걸쳐 사용(내부에서 Search 사용)
  bool Exists(T1 arg) {}
};

#endif // !AVL_H

//변경 전 기존 코드는 이렇게 주석으로 남겨놓겠습니다.

// struct Node {
//   int key_;
//   Node *left_;
//   Node *right_;
// };

// class AVLTree {
// public:
//   Node *root_;
//   AVLTree();
//   int Height(Node *node) {}
//   int HeightDiff(Node *node) {}
//   Node *RR(Node *parent) {}
//   Node *LL(Node *parent) {}
//   Node *RL(Node *parent) {}
//   Node *LR(Node *parent) {}
//   Node *Balancing(Node *node) {}
//   int Insert(int arg) {}
//   int Erase(int arg) {}
//   Node *Search(int arg) {}
//   // int Depth(int arg) {}
// };
