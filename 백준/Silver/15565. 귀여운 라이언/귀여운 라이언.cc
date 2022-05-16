#include<iostream>
#include<vector>
#include<algorithm>
#include<limits.h>

using namespace std;

int N, K;
int doll[1000001];
vector <int>  v;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> K;

	for (int i = 1; i <= N; i++) {
		cin >> doll[i];
		if (doll[i] == 1) {
			v.push_back(i);
		}
	}

	int answer = INT_MAX;
	int idx = v.size() - K + 1;
	for (int i = 0; i < idx; i++) {
		int cnt = v[i + K-1] - v[i] + 1;
		answer = min(answer, cnt);
	}

	if (answer == INT_MAX) {
		answer = -1;
	}

	cout << answer << "\n";

	return 0;
}