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

template <typename T> class Node {
public:
  Node(T key) : key_(key), left_(NULL), right_(NULL) {}
  T getkey() { return key_; }
  Node *getleft() { return left_; }
  void setleft(Node *node) { left_ = node; }
  Node *getright() { return right_; }
  void setright(Node *node) { right_ = node; }

private:
  T key_;
  Node *left_;
  Node *right_;
};

#endif