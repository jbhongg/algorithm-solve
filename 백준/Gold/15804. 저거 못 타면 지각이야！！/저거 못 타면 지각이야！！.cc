#include<iostream>
#include <algorithm>
#include <queue>

using namespace std;

int n, m, idx, cnt, time, cur;
deque< pair <int, int > > dq;
pair < pair <int, int>, int >  p[101];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> p[i].first.first >> p[i].first.second;
	}

	while (true) {
		time++;
		for (int i = cur; i < cur + cnt; i++) {
			p[i].first.second--;
			if (p[i].first.second <= 0 && p[cur].first.second <= 0) {
				cur++;
				cnt--;
			}
		}

		while (true) {
			if (cnt >= n || time < p[idx].first.first) {
				break;
			}
			if (cnt != 0 && p[idx - 1].second == n) {
				break;
			}
			if (cnt == 0) {
				p[idx].second = 1;
			}
			else {
				p[idx].second = p[idx-1].second+1;
			}
			if (idx+1 == m) {
				cout << p[idx].second << "\n";
				goto L;
			}
			idx++;
			cnt++;
		}
	}

	L:
	return 0;
}