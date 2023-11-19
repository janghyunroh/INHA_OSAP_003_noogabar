#include "Set.h"

int Set::Size() { return size_; }

// 노드의 depth와 rank를 pair로 return하는 함수
std::pair<int, int> Set::Rank(int arg) {
  Node *node = Search(arg);
  // tree에 노드가 없다면 0 return
  if (node == nullptr)
    return {0, 0};
  int depth = Height(root_) - Height(node);
  // int depth = Depth(arg);
  int rank = Rank(root_, arg) + 1;
  return {depth, rank};
}

// rank를 return하는 함수
// rank는 x보다 작은 수로 정의
int Rank(Node *node, int x) {
  if (!node)
    return 0;
  int cnt = 0;
  if (node->data < x) {
    cnt++;
  }
  cnt += Rank(node->left, x);
  cnt += Rank(node->right, x);
  return cnt;
}