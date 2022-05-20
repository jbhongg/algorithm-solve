#include<iostream>
#include<cstring>

using namespace std;

int N;
long long mod = 1000000000;
long long answer;
long long dp[101][10][1024]; //자릿수 , 현재 숫자, 1~9 사용 현황
int dc[2] = { 1,-1 };

long long solve(int idx, int num, int type) {
	if (idx == N - 1) {
		//0부터 9까지 다들어있으면
		if (type == 1023) {
			return 1;
		}
		return 0;
	}

	//이미 방문했던 곳이면
	if (dp[idx][num][type] != -1) {
		return dp[idx][num][type];
	}
	dp[idx][num][type] = 0;

	for (int i = 0; i < 2; i++) {
		int next = num + dc[i];
		if (next == 10 || next == -1) {
			continue;
		}
		dp[idx][num][type] += solve(idx + 1, next, type | 1 << next);
	}
	dp[idx][num][type] = dp[idx][num][type] % mod;
	return dp[idx][num][type];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	memset(dp, -1, sizeof(dp));
	cin >> N;
	answer = 0;
	for (int i = 1; i < 10; i++) {
		answer += solve(0, i, 1 << i);
	}
	answer = answer % mod;
	cout << answer << "\n";

	return 0;
}