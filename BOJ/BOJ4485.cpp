//#include<iostream>
//#include<limits.h>
//#include<queue>
//
//using namespace std;
//
//int dc[4] = { -1,0,1,0 };
//int dr[4] = { 0,1,0,-1 };
//int map[125][125];
//int dist[125][125];
//int N;
//void solve() {
//	//우선순위 큐 생성(작은 값부터 꺼내기)
//	priority_queue < pair < int, pair < int, int> > , vector< pair < int, pair < int, int> > >, greater< pair < int, pair < int, int> > > > pq;
//	pq.push(make_pair(map[0][0], make_pair(0, 0)));
//	while (!pq.empty()) {
//		int c = pq.top().second.first;
//		int r = pq.top().second.second;
//		int cost = pq.top().first; //현재 위치까지의 비용
//		pq.pop();
//		//4방 탐색
//		for (int i = 0; i < 4; i++) {
//			int nc = c + dc[i];
//			int nr = r + dr[i];
//			//탐색할 곳이 맵안에 있으면
//			if (nc >= 0 && nr >= 0 && nc < N && nr < N) {
//				//현재 위치의 비용에 다음칸의 비용을 더한값이 탐색칸까지의 비용보다 작으면
//				if (dist[nc][nr] > cost + map[nc][nr]) {
//					dist[nc][nr] = cost + map[nc][nr]; //탐색칸까지의 비용을 현재칸을 거쳐 가는 비용으로 바꿔줌 
//					pq.push(make_pair(dist[nc][nr], make_pair(nc, nr))); //큐에 저장
//				}
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
//	int num = 1;
//
//	while (true) {
//		cin >> N;
//		//입력값이 0이 들어오면 테스트 케이스 종료
//		if (N == 0) {
//			break;
//		}
//		for (int i = 0; i < N; i++) {
//			for (int j = 0; j < N; j++) {
//				cin >> map[i][j];
//				dist[i][j] = INT_MAX; //각칸 까지의 비용을 최대값으로 초기화
//			}
//		}
//		dist[0][0] = map[0][0];
//		solve();
//		cout << "Problem " << num << ": " << dist[N-1][N-1] << "\n";
//		num++;
//	}
//
//	return 0;
//}