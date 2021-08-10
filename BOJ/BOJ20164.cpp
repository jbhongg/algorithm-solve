//#include<iostream>
//#include<limits.h>
//#include<string>
//#include<algorithm>
//
//using namespace std;
//
//int answer[2];
//
//int odd_count(string s) {
//	int odd = 0;
//	for (int i = 0; i < s.length(); i++) {
//		if ((s[i]-'0')% 2 == 1) {
//			odd++;
//		}
//	}
//
//	return odd;
//}
//
//void solve(string s, int odd) {
//	if (s.length() == 1) {
//		int nodd = odd_count(s);
//		answer[0] = min(answer[0], odd);
//		answer[1] = max(answer[1], odd);
//	}
//	else if (s.length() == 2) {
//		int a = s[0]-'0';
//		int b = s[1] - '0';
//		string ns = to_string(a+b);
//		int nodd = odd_count(ns);
//		solve(ns, odd + nodd);
//	}
//	else if (s.length() >= 3) {
//		for (int i = 1; i < s.length()-1; i++) {
//			for (int j = 1; j < s.length()-i; j++) {
//				int a = stoi(s.substr(0, i));
//				int b = stoi(s.substr(i, j));
//				int c = stoi(s.substr(i+j));
//				string ns = to_string(a + b + c);
//				int nodd = odd_count(ns);
//				solve(ns, odd + nodd);
//			}
//		}
//	}
//}
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
//	
//	answer[0] = INT_MAX;
//	answer[1] = INT_MIN;
//	string s;
//
//	cin >> s;
//
//	int odd = odd_count(s);
//	solve(s,odd);
//
//	cout << answer[0] << " " << answer[1] << "\n";
//	return 0;
//}