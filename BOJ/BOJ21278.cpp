//#include<iostream>
//#include<vector>
//#include<queue>
//#include<limits.h>
//#include<algorithm>
//
//using namespace std;
//
//vector <int> v[101];
//vector <int> answer;
//int ans[2];
//int dist[101][101];
//int N, M;
//int dis = INT_MAX;
//
//void bfs(int idx) {
//	queue < pair <int, int> > q;
//	q.push(make_pair(idx,0));
//	while (!q.empty()) {
//		int n = q.front().first;
//		int cnt = q.front().second;
//		q.pop();
//		for (int i = 0; i < v[n].size(); i++) {
//			int nn = v[n][i];
//			if (nn !=idx && dist[idx][nn] == 0) {
//				q.push(make_pair(nn, cnt + 1));
//				dist[idx][nn] = cnt+1; //노드 사이의 거리 저장
//			}
//		}
//	}
//}
//
//void solve(int idx) {
//	//다 뽑았으면
//	if (answer.size() == 2) {
//		int cnt = 0;
//		//현재 노드에서 가까운 치킨집까지의 거리로 모든 노드에서의 거리 계산
//		for (int i = 1; i <= N; i++) {
//			cnt += min(dist[answer[0]][i], dist[answer[1]][i]);
//		}
//		//모든 노드에서의 왕복 거리가 같으면
//		if ((cnt*2) == dis) {
//			//건물 번호 중 작은 게 더 작은 것을 저장
//			if (ans[0] > answer[0]) {
//				ans[0] = answer[0];
//				ans[1] = answer[1];
//			}
//			//건물 번호 중 작은 것도 같으면
//			else if (ans[0] == answer[0]) {
//				//큰 번호가 더 작은 것 저장
//				if (ans[1] > answer[1]) {
//					ans[0] = answer[0];
//					ans[1] = answer[1];
//				}
//			}
//		}
//		//모든 노드에서의 왕복 거리가 더 작은 것 저장
//		else if((cnt * 2) < dis){
//			dis = cnt * 2;
//			ans[0] = answer[0];
//			ans[1] = answer[1];
//		}
//		return;
//	}
//
//	//조합(치킨집을 열 건물 뽑기)
//	for (int i = idx; i <= N; i++) {
//		answer.push_back(i);
//		solve(i + 1);
//		answer.pop_back();
//	}
//}
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
//	
//	cin >> N >> M;
//
//	//인접 리스트 만들기
//	for (int i = 0; i < M; i++) {
//		int A, B;
//		cin >> A >> B;
//		v[A].push_back(B);
//		v[B].push_back(A);
//	}
//	//각 노드에서 다른 노드까지의 거리 구하기
//	for (int i = 1; i <= N; i++) {
//		bfs(i);
//	}
//	solve(1);
//
//	cout << ans[0] << " " << ans[1] << " " << dis << "\n";
//	 
//	return 0;
//}