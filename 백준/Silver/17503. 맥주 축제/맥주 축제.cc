#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

long long N, M, K, maxn = 0;
long long answer = -1;
vector < pair < long long, long long> > beer;
vector <long long> temp;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M >> K;

	for (int i = 0; i < K; i++) {
		long long v, c;
		cin >> v >> c;
		beer.push_back(make_pair(c, v));
		maxn = max(maxn, c);
	}

	long long left = 1;
	long long right = maxn;
	sort(beer.begin(), beer.end());

	while (left <= right) {
		long long mid = (left + right) / 2;
		long long sum = 0;
		temp.clear();
		for (int i = 0; i < beer.size(); i++) {
			if (beer[i].first > mid) {
				break;
			}
			temp.push_back(beer[i].second);
		}

		if (temp.size() < N) {
			left = mid + 1;
			continue;
		}

		sort(temp.rbegin(), temp.rend());

		for (int i = 0; i < N; i++) {
			sum += temp[i];
		}
		if (sum < M) {
			left = mid + 1;
		}
		else {
			right = mid - 1;
			answer = mid;
		}
	}

	cout << answer << "\n";

	return 0;
}	