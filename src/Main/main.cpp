#include "INHA_OSAP_003_noogabar/header/AVLTreeSet/avl-tree-set.h"
#include <iostream>

/**
 * @brief 채점 서버용 main.cpp
 *
 * 돔저지 채점 서버 제출용 main 함수입니다.
 * 최종 제출시 기타 헤더 파일 및 cpp 파일과 병합하여 제출하도록 합니다.
 *
 */

using namespace std;

int T, Q, arg;
string cmd;

int main() {

  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> T;
  while (T--) {

    //채점 서버에선 int형 자료만을 다룹니다.
    // data는 아예 다루지 않지만 일단 int형으로 넣어주었습니다.
    AVLTreeSet<int, int> avl_tree_set;

    cin >> Q;
    while (Q--) {
      cin >> cmd;

      //====================일반 기능====================

      /**
       * @brief 최소 노드의 key 얻은 후 search
       * 찾은 노드의 key와 depth를 차례대로 출력
       */
      if (cmd == "minumum") {
        cin >> arg;

        //찾는 노드가 존재하지 않는 경우 - 교수님께 문의한 결과 채점 서버 테스트
        //케이스로는 들어올리 없는 input이라고 합니다.
        if (!avl_tree_set.Exists(arg))
          cout << "해당 노드가 없습니다.\n";
        else {
          int key = avl_tree_set.Minimum(arg);
          int depth = avl_tree_set.Find(key);
          cout << key << " " << depth << '\n';
        }
      }

      /**
       * @brief 최대 노드의 key 얻은 후 search
       * 찾은 노드의 key와 depth를 차례대로 출력
       */
      else if (cmd == "maximum") {
        cin >> arg;

        //찾는 노드가 존재하지 않는 경우 - 교수님께 문의한 결과 채점 서버 테스트
        //케이스로는 들어올리 없는 input이라고 합니다.
        if (!avl_tree_set.Exists(arg))
          cout << "해당 노드가 없습니다.\n";
        else {
          int key = avl_tree_set.Maximum(arg);
          int depth = avl_tree_set.Find(key);
          cout << key << " " << depth << '\n';
        }
      }

      else if (cmd == "empty") {
        cout << avl_tree_set.Empty() << '\n';
      }

      else if (cmd == "size") {
        cout << avl_tree_set.Size() << "\n";
      }

      else if (cmd == "find") {
        cin >> arg;
        cout << avl_tree_set.Find(arg) << '\n';
      }

      else if (cmd == "insert") {
        cin >> arg;
        cout << avl_tree_set.Insert(arg) << '\n';
      }

      //====================고급 기능====================

      /**
       * @brief 노드 X의 depth와 rank를 공백으로 구분하여 출력
       */
      else if (cmd == "rank") {
        cin >> arg;
        int depth = avl_tree_set.Find(arg);
        int rank = avl_tree_set.Rank(arg);
        cout << depth << " " << rank << '\n';
      }

      /**
       * @brief 노드 X의 depth 출력 후 삭제
       */
      else if (cmd == "erase") {
        cin >> arg;
        cout << avl_tree_set.Erase(arg) << '\n';
      }

      /**
       * @brief 예기치 못한 기타 이상 입력에 대한 처리
       *
       * 실제 채점 서버에선 입력될 일이 없는 케이스입니다.
       *
       */
      else {
        cout << "Error: Wrong input" << '\n';
      }
    }
  }
  return 0;
}