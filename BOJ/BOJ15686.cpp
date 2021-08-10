//#include<iostream>
//#include<vector>
//#include<algorithm>
//#include<limits.h>
//
//using namespace std;
//
//int M, min_dis = INT_MAX;
//int dis[100][13];
//vector <pair<int, int>> c, h;
//vector <int> sel;
//
//int cal() {
//	int dist = 0;
//	int sum = 0;
//	for (int i = 0; i < h.size(); i++) {
//		int minn = INT_MAX;
//		//M개의 치킨집을 모두 탐색
//		for (int j = 0; j < sel.size(); j++) {
//			minn = min(minn, dis[i][sel[j]]); //가장 작은 치킨 거리 저장;
//		}
//		sum = sum + minn; //집마다의 치킨거리를 더해줌(도시의 치킨 거리 계산)
//	}
//
//	return sum;
//}
//
//void solve(int idx) {
//	//M개를 뽑았으면
//	if (sel.size() == M) {
//		min_dis = min(min_dis, cal()); //가장 작은 도시의 치킨 거리 저장
//		return;
//	}
//
//	//치킨집 조합
//	for (int i = idx; i < c.size(); i++) {
//		sel.push_back(i); //벡터에 현재 치킨집 추가
//		solve(i+1); //재귀
//		sel.pop_back(); //조합 벡터 원상복귀
//	}
//}
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
//
//	int N;
//
//	cin >> N >> M;
//
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < N; j++) {
//			int num;
//			cin >> num;
//			if (num == 2) {
//				c.push_back(make_pair(i, j)); //모든 치킨집 저장
//			}
//			else if (num == 1) {
//				h.push_back(make_pair(i, j)); //모든 집 저장
//			}
//		}
//	}
//
//	//각 집마다 치킨 집과의 거리를 계산하고 저장
//	for (int i = 0; i < h.size(); i++) {
//		for (int j = 0; j < c.size(); j++) {
//			dis[i][j] = abs(h[i].first - c[j].first) + abs(h[i].second - c[j].second);
//		}
//	}
//
//	solve(0);
//
//	cout << min_dis  << "\n";
//
//	return 0;
//}