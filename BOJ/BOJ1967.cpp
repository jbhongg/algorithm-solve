//#include<iostream>
//#include<vector>
//
//using namespace std;
//
//int n, node, answer = 0;
//vector < pair <int, int> > v[10001];
//
//void solve(int x, int w, int bx) {
//	//현재 노드에서 갈 수 있는 곳 탐색
//	for (int i = 0; i < v[x].size(); i++) {
//		int nx = v[x][i].first; //다음 값
//		int d = v[x][i].second;
//		//다음 위치가 전 위치와 같지 않으면 재귀
//		if (nx != bx) {
//			solve(nx, w + d, x);
//		}
//		//다음 위치가 전 위치와 같으면
//		else {
//			//현재까지의 거리가 더 크면
//			if (answer < w) {
//				answer = w; //현재까지의 거리 저장
//				node = x; //가장 먼노드를 현재 위치로 저장
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
//	cin >> n;
//
//	for (int i = 0; i < n - 1; i++) {
//		int parent, child, w;
//		cin >> parent >> child >> w;
//		v[parent].push_back(make_pair(child, w));
//		v[child].push_back(make_pair(parent, w));
//	}
//	solve(1, 0, -1); //1에서 가장 먼거리 탐색
//	answer = 0;
//	solve(node, 0, -1); //1에서 가장 먼거리에서 가장 먼 거리 탐색
//
//	cout << answer << "\n";
//
//	return 0;
//}