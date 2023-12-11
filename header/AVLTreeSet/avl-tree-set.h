#ifndef AVL_H
#define AVL_H

#include "INHA_OSAP_003_noogabar/header/TreeSet/tree-set.h"

/**
 * 사용자 정의 소멸자 / 사용자 정의 복사 생성자 / 사용자 정의 대입 연산자
 * 는 필요 없을 것으로 예상되므로 구현할 필요 없을 것 같습니다.
 */
template <typename T> class AVLTreeSet : public TreeSet<T> {
public:
  //생성자는 기본 생성자만으로 충분할 것 같아 제거하였습니다.

  // Overriding fuinctions
  T Maximum(T arg) override;
  T Minimum(T arg) override;

  int Find(T arg) override;
  int Insert(T arg) override;

  int Size() override;
  int Rank(T arg) override;

  bool Empty() override;
  int Erase(T arg) override;

  // Original functions
  int Height(Node<T> *node);
  int HeightDiff(Node<T> *node);
  Node<T> *RR(Node<T> *node);
  Node<T> *LL(Node<T> *parent);
  Node<T> *RL(Node<T> *parent);
  Node<T> *LR(Node<T> *parent);
  Node<T> *Balancing(Node<T> *node);
  Node<T> *Search(T arg);

  //각 기능 구현에 필요한 추가적인 함수는 이곳 아래에 사용처와 함께 적어준 다음,
  //각자 담당 cpp 파일에서 구현해주세요.

  void Insert_N(Node<T> *node, T arg);


  // Rank 함수 구현 중 key값이 존재하지 않는 경우를 걸러내기 위해 한 단계 걸쳐
  // 구현
  int GetTreeSize(Node<T> *node) {}

  // Min/Max 함수 구현 중 key값이 존재하지 않는 경우를 걸러내기 위해 main에서 한
  // 단계 걸쳐 사용(내부에서 Search 사용)
  // bool Exists(T1 arg) {}
  //이 함수는 Search함수와 역할이 겹치므로 삭제하였습니다. main에서는 search를
  //통해 존재 여부를 확인합니다.
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
