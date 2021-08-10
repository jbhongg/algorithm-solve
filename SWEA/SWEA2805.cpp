//#include<iostream>
//
//using namespace std;
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
//
//	int test_case, T;
//	cin >> T;
//
//	for (test_case = 1; test_case <= T; ++test_case)
//	{
//		string s;
//		int N, sum = 0, w = 0;
//		cin >> N;
//		for (int i = 0; i < N; i++) {
//			cin >> s;
//			//한 열의 정가운데 값은 항상 포함
//			sum = sum + s[N / 2] - '0';
//			for (int j = 1; j <= w; j++) {
//				sum = sum + (s[N / 2 - j] - '0') + (s[N / 2 + j] - '0');
//			}
//			//다시 포함되는 열이 양쪽으로 하나씩 줄어드는 부분
//			if (i >= N / 2) {
//				w--;
//			}
//			//포함되는 열이 양쪽으로 하나씩 늘어 나는 부분
//			else {
//				w++;
//			}
//		}
//
//		cout << "#" << test_case << " " << sum << "\n";
//	}
//
//	return 0;
//}