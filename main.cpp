#include <iostream>
#include <utility>
#include "Set.h"

using namespace std;

int T, Q, arg;
string cmd;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> T;
	while (T--) {
		AVLTree *tree = new AVLTree;
		Set *s = new Set(tree);

		cin >> Q;
		while (Q--) {
			cin >> cmd;

			//기본 기능
			if (cmd == "minumum") {
				cin >> arg;
				pair<int, int> node = s->Minimum(arg);
				cout << node.first << " " << node.second << '\n';
			}

			else if (cmd == "maximum") {
				cin >> arg;
				pair<int, int> node = s->Maximum(arg);
				cout << node.first << " " << node.second << '\n';
			}

			else if (cmd == "empty") {
				cout << s->Empty() << '\n';
			} 

			else if (cmd == "size") {
				cout << s->Size() << "\n";
			}
			
			else if (cmd == "find") {
				cin >> arg;
				cout << s->Find(arg) << '\n';
			}

			else if (cmd == "insert") {
				cin >> arg;
				cout << s->Insert(arg) << '\n';
			}
			
			//고급 기능
			else if (cmd == "rank") {
				cin >> arg;
				pair<int, int> ans = s->Rank(arg);
				cout << ans.first << " " << ans.second << '\n';
			}

			else if (cmd == "erase") {
				cin >> arg;
				cout << s->Erase(arg) << '\n';
			}

			//Trash input
			else {
				cout << "Error: Wrong input" << "\n";
			}
		}
	}
	return 0;
}