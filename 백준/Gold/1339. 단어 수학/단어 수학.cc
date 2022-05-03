#include<iostream>
#include<math.h>
#include<algorithm>

using namespace std;

int N, answer;
string s;
int arr[26];
bool desc(int a, int b) {
	return a > b;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	for (int i = 0; i <N; i++) {
		cin >> s;
		for (int j = 0; j < s.size(); j++) {
			arr[s[j] - 'A'] += pow(10, s.size() - 1 - j);
		}
	}

	sort(arr, arr + 26, desc);

	int num = 9;

	for (int i = 0; i < 9; i++) {
		if (arr[i] == 0) {
			break;
		}
		answer += (arr[i] * num);
		num--;
	}

	cout << answer << "\n";

	return 0;
}