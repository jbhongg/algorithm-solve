//#include<iostream>
//#include<vector>
//#include<limits.h>
//#include<queue>
//#include<algorithm>
//
//using namespace std;
//
//int t[101];
//vector<pair<int, int>> v[111];
//int dist[101];
//int n, m, r, answer;
//
//void solve(int s) {
//	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
//	dist[s] = 0;
//	pq.push(make_pair(0, s));
//	while (!pq.empty()) {
//		int c = pq.top().first;
//		int node = pq.top().second;
//		pq.pop();
//		for (int i = 0; i < v[node].size(); i++) {
//			int nc = v[node][i].first;
//			int nnode = v[node][i].second;
//			//다음 노드까지의 거리가 m보다 크면 못가니까 생략
//			if (dist[node] + nc > m) {
//				continue;
//			}
//			//다음 노드에 저장되어 있는 거리가 이번 노드를 거쳐 가는 거리보다 크면 
//			if (dist[nnode] > dist[node] + nc) {
//				dist[nnode] = dist[node] + nc; // 이번 노드를 거쳐 가는 거리를 저장
//				pq.push(make_pair(dist[nnode], nnode)); //큐에 저장
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
//	cin >> n >> m >> r;
//
//	for (int i = 1; i <= n; i++) {
//		cin >> t[i];
//	}
//
//	//간선리스트 만들기
//	for (int i = 1; i <= r; i++) {
//		int a, b, l;
//		cin >> a >> b >> l;
//		v[a].push_back(make_pair(l, b));
//		v[b].push_back(make_pair(l, a));
//	}
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= n; j++) {
//			dist[j] = INT_MAX;
//		}
//		solve(i);
//		int item = 0;
//		for (int j = 1; j <= n; j++) {
//			//현재 노드까지 가는 거리가 m보다 작거나 같으면
//			if (dist[j] <= m) {
//				item += t[j]; //그 노드에 있는 아이템 수를 더함
//			}
//		}
//		answer = max(answer, item); //아이템 수의 합이 최대인 것을 저장
//	}
//
//	cout << answer << "\n";
//	
//	return 0;
//}