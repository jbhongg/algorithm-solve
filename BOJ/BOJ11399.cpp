//#include<iostream>
//#include<vector>
//#include<algorithm>
//
//using namespace std;
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
//
//	int N, P, sum = 0, temp = 0;
//	vector <int> v;
//
//	cin >> N;
//
//	for (int i = 0; i < N; i++) {
//		cin >> P;
//		v.push_back(P);
//	}
//
//	sort(v.begin(), v.end());
//
//	for (int i = 0; i < v.size(); i++) {
//		temp = temp + v.at(i);
//		sum = sum + temp;
//	}
//	cout << sum << '\n';
//
//	return 0;
//}