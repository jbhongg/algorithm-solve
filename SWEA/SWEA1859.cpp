//#include<iostream>
//#include<vector>
//
//using namespace std;
//
//vector <long long> v;
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
//
//	int test_case, T;
//	cin >> T;
//	for (test_case = 1; test_case <= T; ++test_case)
//	{
//		int N, p;
//		long long sum = 0, answer = 0, buy = 0;
//		v.clear();
//		cin >> N;
//		for (int i = 0; i < N; i++) {
//			cin >> p;
//			v.push_back(p);
//		}
//		
//		for (int i = 0; i < N - 1; i++) {
//			int j = i+1;
//			int temp = -1;
//			sum = 0;
//			while (true) {
//				if (v[i] <= v[j]) {
//					if (temp < v[j]) {
//						temp = v[j];
//						for (int k = i; k < j; k++) {
//							sum = sum + v[k];
//							buy++;
//						}
//						i = j;
//					}	
//				}
//				j++;
//				if (j >= N) {
//					break;
//				}
//			}
//			answer = answer + ((buy * v[i]) - sum);
//			buy = 0;
//		}
//
//		cout << "#" << test_case << " " << answer << "\n";
//	}
//	
//	return 0;
//}