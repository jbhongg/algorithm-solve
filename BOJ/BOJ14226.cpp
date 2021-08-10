//#include<iostream>
//#include<queue>
//
//using namespace std;
//
//bool visit[1002][1002]; //[디스플레이에 있는 이모티콘 갯수][클립보드에 있는 이모티콘 갯수]
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
//	
//	int S;
//	queue <pair < pair <int, int>, int> > q; //디스플레이, 클립, 시간
//
//	cin >> S;
//	q.push(make_pair(make_pair(1, 0), 0)); //초기값 push
//	visit[1][0] = true;
//	while (!q.empty()) {
//		int dis = q.front().first.first;
//		int clip = q.front().first.second;
//		int time = q.front().second;
//		q.pop();
//
//		//디스플레이에 있는 이모티콘 갯수가 S와 같으면 시간 출력 후 탈출
//		if (dis == S) {
//			cout << time << "\n";
//			break;
//		}
//
//		//디스플레이에 있는 이모티콘 갯수가 1이상이고 최댓값 이하라면
//		if (dis > 0 && dis < 1002) {
//			//아직 방문하지 않았다면(1번 연산)
//			if (!visit[dis][dis]) {
//				visit[dis][dis] = true; //방문 체크
//				q.push(make_pair(make_pair(dis, dis), time + 1)); //큐에 추가
//			}
//
//			//아직 방문하지 않았다면(3번 연산)
//			if (!visit[dis - 1][clip]) {
//				visit[dis - 1][clip] = true; //방문 체크
//				q.push(make_pair(make_pair(dis-1, clip), time + 1));//큐에 추가
//			}
//		}
//
//		//클립보드의 이모티콘 갯수가 1개 이상이고 디스플레이에 있는 이모티콘 갯수와의 합이 최대값 이하이면
//		if (clip > 0 && dis + clip < 1002) {
//			//아직 방문하지 않았다면(2번 연산)
//			if (!visit[dis + clip][clip]) {
//				visit[dis + clip][clip] = true; //방문 체크
//				q.push(make_pair(make_pair(dis + clip, clip), time + 1));//큐에 추가
//			}
//		}
//	}
//	
//	return 0;
//}