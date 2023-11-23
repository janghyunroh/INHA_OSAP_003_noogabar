#ifndef NODE_H
#define NODE_H

/**
 * @brief
 *
 * 유의사항
 *
 * 교수님께서 말씀하신 확장성을 위해
 * 노드 클래스 내부에 data 변수를 추가하였습니다.
 *
 */

template <typename T1, typename T2> class Node {
public:
  Node(T1 key) : key_(key), data_(NULL), left_(NULL), right_(NULL) {}
  T1 getkey() {}
  T2 getdata() {}
  Node *getleft() {}
  void setleft() {}
  Node *getright() {}
  void setright() {}

private:
  T1 key_;
  T2 data_;
  Node *left_;
  Node *right_;
};

#endif