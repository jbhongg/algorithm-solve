//#include<iostream>
//#include<queue>
//
//using namespace std;
//int mov[101];
//queue <int> q;
//int visit[101];
//
//void solve() {
//	while (!q.empty()) {
//		int k = q.front();
//		//주사위
//		for (int i = 1; i <= 6; i++) {
//			//다음 위치 설정
//			int nk = k + i;
//			//다음 위치가 100이 넘으면 탈출(이 상황에서 주사위의 수가 더 큰 것을 할 필요 없음)
//			if (nk > 100) {
//				break;
//			}
//
//			//다음 위치에 뱀이나 사다리가 있으면 위치를 그에 해당하는 곳으로 변경
//			if (mov[nk] != 0) {
//				nk = mov[nk];
//			}
//
//			//방문하지 않은 위치라면 큐에 추가하고 visit 배열에 거리 입력
//			if (visit[nk] == -1) {
//				q.push(nk);
//				visit[nk] = visit[k]+1;
//			}
//		}
//		q.pop();
//		
//	}
//}
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
//
//	int N, M;
//
//	cin >> N >> M;
//
//	//사다리 저장
//	for (int i = 0; i < N; i++) {
//		int go, to;
//		cin >> go >> to;
//		mov[go] = to;
//	}
//
//	//뱀 저장
//	for (int i = 0; i < M; i++) {
//		int go, to;
//		cin >> go >> to;
//		mov[go] = to;
//	}
//
//	//visit 배열 초기화
//	fill(visit, visit+101, -1);
//	//1에 시작하므로 큐에 추가
//	q.push(1);
//	//1번에서 시작하므로 1번은 횟수가 0번
//	visit[1] = 0;
//	solve();
//
//	cout << visit[100] << "\n";
//
//  return 0;
//}