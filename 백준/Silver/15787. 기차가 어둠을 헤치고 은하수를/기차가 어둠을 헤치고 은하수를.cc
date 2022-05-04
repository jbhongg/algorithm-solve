#include<iostream>
#include<vector>
#include<set>

using namespace std;

int N, M;
vector <int> v(100001, 0);
set <int> s;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;


	for (int j = 0; j < M; j++) {
		int command,i;
		cin >> command;
		if (command == 1 || command == 2) {
			int x;
			cin >> i >> x;
			if (command == 1) {
				v[i] |= (1 << (x-1));
			}
			else {
				v[i] &= ~(1 << (x-1));
			}
		}
		else {
			cin >> i;
			if (command == 3) {
				v[i] <<=  1;
				v[i] &= ~(1 << 20);
			}
			else {
				v[i] >>=  1;
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		s.insert(v[i]);
	}

	cout << s.size() << "\n";

	return 0;
}