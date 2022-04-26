#include<iostream>
#include<vector>

using namespace std;

vector <char> v;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string s;
	int answer = 0;

	cin >> s;

	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '(') {
			v.push_back(s[i]);
		}
		else {
			if (s[i - 1] == '(') {
				v.pop_back();
				answer += v.size();
			}
			else {
				answer += 1;
				v.pop_back();
			}
		}
	}

	cout << answer << "\n";

	return 0;
}