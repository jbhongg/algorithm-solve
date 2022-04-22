#include<iostream>
#include<cstring>
#include <algorithm>

using namespace std;

int N, answer;
int p[51][10];
int sel[10];
bool visit[10];

void baseball() {
	int idx = 1;
	int base[4];
	int score = 0;

	for (int i = 1; i <= N; i++) {
		memset(base, 0, sizeof(base));
		int outCount = 0;
		bool flag = false;
		while (true) {
			for (int j = idx; j <= 9; j++) {
				int k = p[i][sel[j]];

				if (k == 0) {
					outCount++;
				}
				else if (k == 1) {
					for (int r = 3; r >= 1; r--) {
						if (base[r] == 1) {
							if (r == 3) {
								base[r] = 0;
								score++;
							}
							else {
								base[r] = 0;
								base[r + 1] = 1;
							}
						}
					}
					base[1] = 1;
				}
				else if (k == 2) {
					for (int r = 3; r >= 1; r--) {
						if (base[r] == 1) {
							if (r == 3 || r==2) {
								base[r] = 0;
								score++;
							}
							else {
								base[r] = 0;
								base[r + 2] = 1;
							}
						}
					}
					base[2] = 1;
				}
				else if (k == 3) {
					for (int r = 3; r >= 1; r--) {
						if (base[r] == 1) {
							base[r] = 0;
							score++;
						}
					}
					base[3] = 1;
				}
				else if (k == 4) {
					for (int r = 3; r >= 1; r--) {
						if (base[r] == 1) {
							base[r] = 0;
							score++;
						}
					}
					score++;
				}

				if (outCount == 3) {
					flag = true;
					idx = j + 1;
					if (idx == 10) {
						idx = 1;
					}
					break;
				}
			}
			if (flag) {
				break;
			}
			idx = 1;
		}
	}
	answer = max(answer, score);
}

void solve(int cnt) {
	if (cnt == 10) {
		baseball();
		return;
	}
	for (int i = 1; i <= 9; i++) {
		if (visit[i]) {
			continue;
		}
		visit[i] = true;
		sel[i] = cnt;
		solve(cnt + 1);
		visit[i] = false;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= 9; j++) {
			cin >> p[i][j];
		}
	}

	visit[4] = true;
	sel[4] = 1;
	solve(2);

	cout << answer << "\n";

	return 0;
}