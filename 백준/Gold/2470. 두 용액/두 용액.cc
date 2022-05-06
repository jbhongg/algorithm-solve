#include<iostream>
#include<vector>
#include<algorithm>
#include<limits.h>
#include<math.h>

using namespace std;

int N, answer1, answer2;
int diff = INT_MAX;;
vector <int> v;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		v.push_back(num);
	}

	sort(v.begin(), v.end());

	int left = 0;
	int right = v.size() - 1;

	while (left < right) {
		int cal = v[left] + v[right];
		if (diff > abs(cal)) {
			diff = abs(cal);
			answer1 = right;
			answer2 = left;
			if (cal == 0) {
				break;
			}
		}

		if (cal < 0) {
			left++;
		}
		else {
			right--;
		}
	}

	cout << v[answer2] << " " << v[answer1] << "\n";
	return 0;
}