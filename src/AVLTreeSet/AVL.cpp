#include "AVL.h"
#include <algorithm>
using namespace std;

// 생성자함수
AVLTree::AVLTree() { this->root_ = nullptr; }

// tree의 높이를 반환하는 함수
int AVLTree::Height(Node *node) {
  int height = 0;
  if (node != nullptr) {
    int left = Height(node->left_);
    int right = Height(node->right_);
    int height = max(left, right) + 1;
  }
  return height;
}

// 왼쪽 자식과 오른쪽 자식의 높이차를 반환하는 함수
// 음수이면 오른쪽 자식, 양수이면 왼쪽 자식의 높이가 큰 것
int AVLTree::HeightDiff(Node *node) {
  return Height(node->left_) - Height(node->right_);
}

// 오른쪽으로 길어졌을 때의 rotation
Node *AVLTree::RR(Node *parent) {
  Node *new_parent = parent->right_; // right가 parent의 위로 올라간다
  parent->right_ = new_parent->left_;
  new_parent->left_ = parent;
  return new_parent;
}

// 왼쪽으로 길어졌을 때의 rotation
Node *AVLTree::LL(Node *parent) {
  Node *new_parent = parent->left_;
  parent->left_ = new_parent->right_;
  new_parent->right_ = parent;
  return new_parent;
}

//
Node *AVLTree::RL(Node *parent) {
  parent->right_ = LL(parent->right_);
  return RR(parent);
}

//
Node *AVLTree::LR(Node *parent) {
  parent->left_ = RR(parent->left_);
  return LL(parent);
}

// 균형이 깨진 경우 균형을 잡는 함수
Node *AVLTree::Balancing(Node *node) {
  int height_difference = HeightDiff(node);

  if (height_difference > 1) {      // LL or LR
    if (HeightDiff(node->left_) > 0) // LL
      return LL(node);
    else
      return LR(node);
  } else if (height_difference < -1) { // RR or LR
    if (HeightDiff(node->right_) > 0)   // RL
      return RL(node);
    else
      return RR(node);
  }
  return node;
}

// tree에 삽입하는 함수
int AVLTree::Insert(int arg) {
  Node *node = new Node();
  node->key_ = arg;
  if (this->root_ == nullptr) {
    this->root_ = node;
    return;
  }

  Node *grand_parent_node = nullptr;
  Node *parent_node = nullptr;
  Node *current_node = this->root_;

  while (current_node != nullptr) {
    // 현재 노드의 값보다 크면 오른쪽으로 내려가고 작으면 왼쪽으로 내려간다.
    if (arg > current_node->key_) {
      grand_parent_node = parent_node;
      parent_node = current_node;
      current_node = current_node->right_;
    } else {
      grand_parent_node = parent_node;
      parent_node = current_node;
      current_node = current_node->right_;
    }
  }

  if (arg > parent_node->key_) {
    parent_node->right_ = node;
  } else {
    parent_node->left_ = node;
  }

  Balancing(grand_parent_node);
}

int AVLTree::Erase(int arg) {}

Node *AVLTree::Search(int data) {
  Node *curN = this->root_;
  while (curN != nullptr) { // tree의 맨 하단까지 내려가며 있는지 확인
    if (data == curN->key_)
      return curN;
    curN = (data > curN->key_) ? curN->right_ : curN->left_;
  }
  return nullptr;
}
