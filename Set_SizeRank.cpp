#include "Set.h"

int Set::Size() { return size_; }

// 노드의 depth와 rank를 pair로 return하는 함수
int Set::Rank(int arg) {
  Node *node = Search(arg);
  // tree에 노드가 없다면 0 return
  if (node == nullptr)
    return {0, 0};
  int rank = CalculateRank(root_, arg) + 1;
  return rank;
}

// rank를 return하는 함수
// rank는 x보다 작은 수로 정의
int CalculateRank(Node *node, int x) {
  if (!node)
    return 0;
  int cnt = 0;
  if (node->data < x) {
    cnt++;
  }
  cnt += CalculateRank(node->left, x);
  cnt += CalculateRank(node->right, x);
  return cnt;
}