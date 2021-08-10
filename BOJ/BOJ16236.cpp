//#include<iostream>
//#include<vector>
//#include<queue>
//#include<algorithm>
//#include<limits.h>
//
//using namespace std;
//
//bool flag;
//int map[21][21];
//int cnt, answer, eat, N, w = 2;
//vector < pair <int, int> > v; // 아기상어
//int visit[21][21];
//int dc[4] = {-1,0,1,0};
//int dr[4] = { 0,1,0,-1 };
//vector <pair <int, int> > f; //먹이
//vector <pair <pair <int, int>, int > >  e; //먹을거
//
//void init() {
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < N; j++) {
//			visit[i][j] = -1;
//		}
//	}
//}
//
//void bfs() {
//	queue < pair < pair <int, int>, int > > q;
//	q.push(make_pair(make_pair(v.front().first, v.front().second), 0)); //큐에 아기상어 위치와 거리값을 저장
//	visit[v.front().first][v.front().second] = 0; //visit 배열에 거리를 저장
//	while (!q.empty()) {
//		int c = q.front().first.first;
//		int r = q.front().first.second;
//		int count = q.front().second; //거리값
//		q.pop();
//		//4방 탐색
//		for (int i = 0; i < 4; i++) {
//			int nc = c + dc[i];
//			int nr = r + dr[i];
//			//탐색한 위치가 맵안에 있고 방문하지 않았다면
//			if (nc >= 0 && nc < N && nr >= 0 && nr < N && visit[nc][nr] == -1) {
//				//탐색 위치가 빈칸이거나 아기 상어와 같은 크기라면
//				if (map[nc][nr] == 0 || map[nc][nr] == w) {
//					visit[nc][nr] = count+1; //해당 위치의 visit 배열에 현재 거리 + 1을 한 값을 저장
//					q.push(make_pair(make_pair(nc, nr), count + 1)); //큐에 탐색 위치와 현재 거리 + 1 한 값을 추가 
//				}
//				////탐색 위치가 빈칸이 아니고 아기상어가 먹을수 있는 크기라면
//				else if (map[nc][nr] != 0 && map[nc][nr] < w) {
//					visit[nc][nr] = count + 1; //해당 위치의 visit 배열에 현재 거리 + 1을 한 값을 저장
//				}
//			}
//		}
//	}
//}
//
//void solve() {
//	e.push_back(make_pair(make_pair(INT_MAX, INT_MAX), INT_MAX)); //먹을 먹이를 나타내는 벡터를 최댓값으로 초기화
//	//먹이가 저장되어 있는 벡터의 크기만큼 탐색
//	for (int i = 0; i < f.size(); i++) {
//		//먹을 먹이까지의 거리와 현재 탐색하고 있는 먹이까지의 거리가 같다면
//		if (e.front().second == visit[f.at(i).first][f.at(i).second]) {
//			//먹을 먹이와 현재 탐색하고 있는 먹이의 행이 같다면
//			if (e.front().first.first == f.at(i).first) {
//				//먹을 먹이보다 현재 탐색하고 있는 먹이가 더 왼쪽에 있다면
//				if (e.front().first.second > f.at(i).second) {
//					e.pop_back(); //현재 값을 제거하고
//					//먹을 먹이를 저장하는 벡터에 현재 탐색하고 있는 먹이의 위치와 먹이까지의 거리 저장
//					e.push_back(make_pair(make_pair(f.at(i).first, f.at(i).second), visit[f.at(i).first][f.at(i).second]));
//				}
//			}
//			//먹을 먹이보다 현재 탐색하고 있는 먹이가 더 위에 있다면
//			else if(e.front().first.first > f.at(i).first){
//				e.pop_back(); //현재 값을 제거하고
//				//먹을 먹이를 저장하는 벡터에 현재 탐색하고 있는 먹이의 위치와 먹이까지의 거리 저장
//				e.push_back(make_pair(make_pair(f.at(i).first, f.at(i).second), visit[f.at(i).first][f.at(i).second]));
//			}
//		}
//		//현재 탐색하고 있는 먹이까지 갈 수 있고 먹을 먹이까지의 거리보다 현재 탐색하고 있는 먹이까지의 거리가 더 작다면
//		else if(visit[f.at(i).first][f.at(i).second] != -1 && e.front().second > visit[f.at(i).first][f.at(i).second])
//		{
//			e.pop_back(); //현재 값을 제거하고
//			//먹을 먹이를 저장하는 벡터에 현재 탐색하고 있는 먹이의 위치와 먹이까지의 거리 저장
//			e.push_back(make_pair(make_pair(f.at(i).first, f.at(i).second), visit[f.at(i).first][f.at(i).second]));
//		}
//		
//	}
//	//먹을 먹이의 값이 그대로 최댓값이라면 먹을 먹이가 있지만 갈수 없다는 의미이므로 종료
//	if (e.front().first.first == INT_MAX) {
//		flag = true;
//		return;
//	}
//	//맵에 먹을 먹이가 있는 위치의 값을 0으로 바꿔줌
//	map[e.front().first.first][e.front().first.second] = 0;
//	eat++; //아기상어가 먹은 먹이의 수 증가
//	//먹은 먹이의 수와 아기상어의 크기가 같다면
//	if (eat == w) {
//		w++; //아기상어의 크기 1 증가
//		eat = 0; //먹은 먹이의 수 0으로 초기화
//	}
//	//아기상어의 위치를 먹은 먹이의 위치로 바꿔줌
//	v.front().first = e.front().first.first;
//	v.front().second = e.front().first.second;
//	answer = answer + e.front().second; //먹이까지 움직일때 든 시간을 더해줌
//}
//
//bool check() {
//	//먹이가 있지만 갈수 없어도 false 반환
//	if (flag) {
//		return false;
//	}
//	cnt = 0;
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < N; j++) {
//			//먹이가 있으면 먹이 갯수 증가
//			if (map[i][j] != 0 && map[i][j] < w) {
//				f.push_back(make_pair(i, j));
//				cnt++;
//			}
//		}
//	}
//	//먹이 갯수가 0이면 false 반환
//	if (cnt == 0) {
//		return false;
//	}
//	//먹이 갯수가 0이 아니면 true 반환
//	else {
//		return true;
//	}
//}
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
//
//	cin >> N;
//
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < N; j++) {
//			cin >> map[i][j];
//			//아기 상어라면
//			if (map[i][j] == 9) {
//				v.push_back(make_pair(i, j)); //아기 상어 위치 저장
//				map[i][j] = 0; //초기 아기상어 위치를 0으로 초기화
//			}
//		}
//	}
//
//	//먹을 먹이가 없으면 종료
//	while (check()) {
//		init(); //visit 배열 초기화
//		bfs();
//		solve();
//		f.clear(); //먹이를 저장한 벡터 초기화
//		e.clear(); //먹을 먹이를 저장한 벡터 초기화
//	}
//	
//	cout << answer << "\n";
//
//	return 0;
//}