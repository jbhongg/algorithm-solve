#include<iostream>
#include<vector>
#include<set>
#include<algorithm>

using namespace std;

vector <string> v;
set <string> answer;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string s;

	cin >> s;
	reverse(s.begin(), s.end());
	v.push_back(s);

	while (!v[0].empty()) {
		s = v[0];
		reverse(s.begin(), s.end());
		answer.insert(s);
		v[0].pop_back();
	}

	for (auto i : answer) {
		cout << i << "\n";
	}

	return 0;
}