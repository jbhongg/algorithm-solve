#include<iostream>
#include <queue>

using namespace std;

struct Info
{
	int coinC1;
	int coinR1;
	int coinC2;
	int coinR2;
	int cnt;
} info;

int N, M;
char map[21][21];
queue <Info> q;
bool visit[21][21][21][21];
int dc[4] = {-1,0,1,0};
int dr[4] = {0,1,0,-1};

void solve() {
	while (!q.empty()) {
		int c1 = q.front().coinC1;
		int r1 = q.front().coinR1;
		int c2 = q.front().coinC2;
		int r2 = q.front().coinR2;
		int count = q.front().cnt;

		q.pop();

		if (count > 9) {
			cout << -1 << "\n";
			return;
		}

		for (int i = 0; i < 4; i++) {
			int nc1 = c1 + dc[i];
			int nr1 = r1 + dr[i];
			int nc2 = c2 + dc[i];
			int nr2 = r2 + dr[i];
			int out = 0;

			if (map[nc1][nr1] == '#') {
				nc1 = c1;
				nr1 = r1;
			}
			if (map[nc2][nr2] == '#') {
				nc2 = c2;
				nr2 = r2;
			}
			if (nc1 == nc2 && nr1 == nr2) {
				continue;
			}
			if (nc1 < 0 || nr1 < 0 || nc1 >= N || nr1 >= M) {
				out++;
			}
			if (nc2 < 0 || nr2 < 0 || nc2 >= N || nr2 >= M) {
				out++;
			}
			if (out == 1) {
				cout << count + 1 << "\n";
				return;
			}
			else if (out == 2) {
				continue;
			}
			if (visit[nc1][nr1][nc2][nr2]) {
				continue;
			}
			visit[nc1][nr1][nc2][nr2] = true;
			info.coinC1 = nc1;
			info.coinR1 = nr1;
			info.coinC2 = nc2;
			info.coinR2 = nr2;
			info.cnt = count + 1;
			q.push(info);
		}
	}

	cout << -1 << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;

	int count = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			
			if (map[i][j] == 'o' && count ==0) {
				info.coinC1 = i;
				info.coinR1 = j;
				count++;
			}
			else if (map[i][j] == 'o' && count == 1) {
				info.coinC2 = i;
				info.coinR2 = j;
			}
		}
	}

	info.cnt = 0;
	q.push(info);
	visit[info.coinC1][info.coinR1][info.coinC2][info.coinR2] = true;

	solve();

	return 0;
}