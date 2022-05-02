#include<iostream>
#include<queue>

using namespace std;
char map[12][6];
int dc[4] = {-1,0,1,0};
int dr[4] = {0,1,0,-1};
queue <pair<int, int>> q;
bool visit[12][6], temp[12][6];
int answer;

bool check() {
	int count = 0;
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 6; j++) {
			if (visit[i][j]) {
				count++;
			}
		}
	}
	if (count == 0) {
		return true;
	}
	else {
		return false;
	}
}

void move() {
	for (int i = 0; i < 6; i++) {
		for (int j = 11; j > 0; j--) {
			if (map[j][i] == '.') {
				int k = j-1;
				while (map[k][i] == '.') {
					k--;
					if (k < 0) {
						break;
					}
				}
				if (k >= 0) {
					map[j][i] = map[k][i];
					map[k][i] = '.';
				}
				else {
					break;
				}
			}
		}
	}
}

void bomb() {
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 6; j++) {
			if (visit[i][j]) {
				map[i][j] = '.';
				visit[i][j] = false;
				temp[i][j] = false;
			}
		}
	}
	move();
}

void back() {
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 6; j++) {
			visit[i][j] = temp[i][j];
		}
	}
}

void solve(char color) {
	int count = 1;
	while (!q.empty()) {
		int c = q.front().first;
		int r = q.front().second;
		for (int i=0; i < 4; i++) {
			int nc = c + dc[i];
			int nr = r + dr[i];
			if (nc >= 0 && nc < 12 && nr >= 0 && nr < 6 && visit[nc][nr] == false && map[nc][nr] == color) {
				q.push(make_pair(nc, nr));
				visit[nc][nr] = true;
				count++;
			}
		}
		q.pop();
	}
	if (count >= 4) {
		for (int i = 0; i < 12; i++) {
			for (int j = 0; j < 6; j++) {
				temp[i][j] = visit[i][j];
			}
		}
	}
	else {
		back();
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	for (int i = 0; i < 12; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < 6; j++) {
			map[i][j] = s[j];
		}
	}
	while (true) {
		for (int i = 0; i < 12; i++) {
			for (int j = 0; j < 6; j++) {
				if (map[i][j] != '.' && visit[i][j] == false) {
					q.push(make_pair(i, j));
					visit[i][j] = true;
					solve(map[i][j]);
				}
			}
		}
		if (check()) {
			break;
		}
		bomb();
		answer++;
	}

	cout << answer << "\n";
	return 0;
}