#include "Set.h"

// 해당 set의 원소의 개수를 return하는 함수
int Set::Size() { return size_; }

// 노드의 rank를 return하는 함수
int Set::Rank(int arg) {
  Node *node = Set::Search(arg);
  // tree에 노드가 없다면 0 return
  if (node == nullptr)
    return 0;
  int rank = CalculateRank(root_, arg) + 1;
  return rank;
}

// rank를 return하는 함수
// rank는 x보다 작은 수로 정의
int CalculateRank(Node *node, int x) {
  // 존재하지 않는 노드는 0 return
  if (!node)
    return 0;

  // preorder traversal로 구현
  int cnt = 0;
  if (node->key_ < x)
    cnt++;
  cnt += CalculateRank(node->left_, x);
  cnt += CalculateRank(node->right_, x);
  return cnt;
}