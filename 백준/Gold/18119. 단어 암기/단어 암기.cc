#include<iostream>
#include<vector>

using namespace std;

int N, M;
vector <int> v(10001, 0);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < s.size(); j++) {
			v[i] |= (1 << (s[j] - 'a'));
		}
	}

	int cmp = 0;
	for (int i = 0; i < M; i++) {
		int command, cnt = 0;
		char c;

		cin >> command >> c;

		if (command == 1) {
			cmp |= (1 << (c - 'a'));
		}
		else {
			cmp &= ~(1 << (c - 'a'));
		}
		for (int j = 0; j < N; j++) {
			if (v[j] & cmp) {
				continue;
			}
			cnt++;
		}
		cout << cnt << "\n";
	}

	return 0;
}