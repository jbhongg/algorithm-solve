//#include<iostream>
//#include<vector>
//#include<algorithm>
//
//using namespace std;
//
//vector <pair <int, int>> v;
//
//bool cmp(pair <int, int> p1, pair <int, int> p2) {
//	return p1.second < p2.second;
//}
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
//	
//	int N, x, y;
//
//	cin >> N;
//
//	for (int i = 0; i < N; i++) {
//		cin >> x >> y;
//		v.push_back(make_pair(x, y));
//	}
//
//	sort(v.begin(), v.end(), cmp); //최고보관온도를 기준으로 오름차순 정렬
//
//	int idx = 0, count = 1; //기준, 냉장고의 갯수
//	for (int i = 1; i < N; i++) {
//		//현재 화학 물질의 최저온가 기준이 되는 화학물질의 최고 온도보다 크면
//		if (v.at(i).first > v.at(idx).second) {
//			idx = i; //기준을 현재 화학물질로 바꿔줌
//			count++; //냉장고 갯수 하나 증가
//		}
//	}
//
//	cout << count << "\n";
//	
//	return 0;
//}