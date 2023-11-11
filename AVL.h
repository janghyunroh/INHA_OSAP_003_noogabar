#ifndef AVL_H
#define AVL_H

struct Node {
  int data;
  Node *left;
  Node *right;
};

class AVLTree {
public:
  Node *root;
  AVLTree();
  int Height(Node *node) {}
  int HeightDiff(Node *node) {}
  Node *RR(Node *parent) {}
  Node *LL(Node *parent) {}
  Node *RL(Node *parent) {}
  Node *LR(Node *parent) {}
  Node *Balancing(Node *node) {}
  int Insert(int arg) {}
  int Erase(int arg) {}
  Node *Search(int arg) {}
  // int Depth(int arg) {}
};

#endif // !AVL_H