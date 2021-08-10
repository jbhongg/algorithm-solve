//#include<iostream>
//
//using namespace std;
//
//int dp[31];
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
//	
//	int N;
//
//	cin >> N;
//
//	dp[2] = 3;
//	for (int i = 4; i <= N; i += 2) {
//		dp[i] = dp[i - 2] * 3 + 2;
//		if (i > 4) {
//			for (int j = 4; j <= i - 2; j += 2) {
//				dp[i] = dp[i] + dp[i - j] * 2;
//			}
//		}
//	}
//
//	cout << dp[N] << "\n";
//	
//	return 0;
//}