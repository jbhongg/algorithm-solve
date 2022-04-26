#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	vector < pair < int, string> > v;
	int arr[100001];
	int N, M;

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		string s;
		cin >> s >> arr[i];
		v.push_back(make_pair(arr[i], s));
	}

	for (int i = 0; i < M; i++) {
		int num;
		cin >> num;
		int idx = lower_bound(arr, arr + N, num)-arr;
		cout << v[idx].second << "\n";

	}

	return 0;
}