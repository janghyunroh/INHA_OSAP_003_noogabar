#ifndef SET_H
#define SET_H

#include "AVL.h"
#include <utility>

class Set : AVLTree {

public:
  Set(AVLTree * tree) : tree_(tree), size_(0) {}
  std::pair<int, int> Minimum(int arg) {}
  std::pair<int, int> Maximum(int arg) {}
  bool Empty() {}
  int Size() {}
  int Find(int arg) {}
  int Insert(int arg) {}
  int Rank(int arg) {}
  int Erase(int arg) {}

private:
  AVLTree *tree_;
  int size_;
};

#endif // !SET_H
