//#include<iostream>
//#include<vector>
//#include<algorithm>
//
//using namespace std;
//
//vector <int> v;
//vector <pair <double, int>> vv;
//int N, M, L;;
//
//void solve(double dist, int cnt) {
//	vv.pop_back();
//	double n = (dist * cnt) / (cnt + 1); //구간의 길이를 현재 나눈갯수 + 1로 나눔 
//	vv.push_back(make_pair(n, cnt + 1)); //새롭게 생긴 구간 정보를 벡터에 추가
//}
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
//
//	cin >> N >> M >> L;
//
//	v.push_back(0); //고속도로의 시작위치 추가
//
//	for (int i = 0; i < N; i++) {
//		int r;
//		cin >> r;
//		v.push_back(r);
//	}
//	v.push_back(L); //고속도로의 마지막 위치 추가
//
//	sort(v.begin(), v.end()); //오름차순 정렬
//
//	//휴게소가 있는 구간의 길이를 벡터에 저장, 두번쨰 값은 나눈 갯수
//	for (int i = 0; i < v.size()-1; i++) {
//		vv.push_back(make_pair(v[i + 1] - v[i], 1));
//	}
//	//구간 길이 오름차순 정렬
//	sort(vv.begin(), vv.end());
//
//
//	for (int i = 0; i < M; i++) {
//		solve(vv.back().first, vv.back().second);
//		sort(vv.begin(), vv.end()); //구간 길이 오름차순 정렬
//	}
//	//가장 긴 구간의 길이의 값이 정수이면 출력
//	if (vv.back().first == (int)vv.back().first) {
//		cout << (int)vv.back().first << "\n";
//	}
//	//가장 긴 구간의 길이의 값이 정수가 아니면 +1해서 출력
//	else {
//		cout << (int)vv.back().first + 1 << "\n";
//	}
//
//	return 0;
//}