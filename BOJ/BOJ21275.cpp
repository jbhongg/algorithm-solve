//#include<iostream>
//#include<vector>
//#include<math.h>
//
//using namespace std;
//
//long long solve(string s, int n) {
//	long long answer = 0;
//	int idx = 0;
//	for (int i = s.length()-1; i >= 0; i--) {
//		int num = 0;
//		if (s[idx] >= '0' && s[idx] <= '9') {
//			num = s[idx] - '0';
//			if (num >= n) {
//				return -1;
//			}
//			answer += num * pow(n, i);
//			idx++;
//		}
//		else if (s[idx] >= 'a' && s[idx] <= 'z') {
//			num = s[idx] - 'a' + 10;
//			if (num >= n) {
//				return -1;
//			}
//			answer += num * pow(n, i);
//			idx++;
//		}
//	}
//	return answer;
//}
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
//	
//	string A, B;
//
//	cin >> A >> B;
//
//	vector <long long> v1;
//	vector <long long> v2;
//
//	for (int i = 2; i <= 36; i++) {
//		v1.push_back(solve(A,i));
//		v2.push_back(solve(B, i));
//	}
//	int a,b,answer = 0;
//	long long x = 0;
//	for (int i = 0; i < v1.size(); ++i) {
//		if (v1[i] == -1) {
//			continue;
//		}
//		for (int j = 0; j < v2.size(); ++j) {
//			if (v1[i] == v2[j] && i != j) {
//				answer++;
//				x = v1[i];
//				a = i;
//				b = j;
//			}
//		}
//	}
//	if (answer == 0) {
//		cout << "Impossible" << '\n';
//	}
//	else if (answer > 1) {
//		cout << "Multiple" << '\n';
//	}
//	else cout << x << " " << a + 2 << " " << b + 2 << "\n";
//	
//	return 0;
//}