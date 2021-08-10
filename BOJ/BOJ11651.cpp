//#include<iostream>
//#include<vector>
//#include<algorithm>
//
//using namespace std;
//
//bool cmp(pair <int, int> p1, pair <int, int> p2) {
//	if (p1.second == p2.second) {    //y값이 같다면
//		return p1.first < p2.first;  //x의 값으로 오름차순 정렬
//	}
//
//	return p1.second < p2.second;   //y값으로 오름차순 정렬
//}
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
//
//	vector <pair <int, int>> v;  //좌표값을 한번에 받기위한 변수
//	int N, x, y;
//	 
//	cin >> N;
//
//	//좌표 입력값 받기
//	for (int i = 0; i < N; i++) {
//		cin >> x >> y;
//		v.push_back(make_pair(x, y));
//	}
//	
//	//정렬
//	sort(v.begin(), v.end(), cmp);
//
//	//출력
//	for (int i = 0; i < N; i++) {
//		cout << v[i].first << " " << v[i].second << '\n';
//	}
//	return 0;
//}