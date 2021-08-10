//#include<iostream>
//#include<queue>
//
//using namespace std;
//
//char map[20][20];
//int dc[8] = {-1,-1,0,1,1,1,0,-1};
//int dr[8] = {0,1,1,1,0,-1,-1,-1};
//bool flag;
//bool visit[8];
//
//queue <pair <pair <int, int>, char> > q;
//
////방향 탐색 완료 표시 배열 초기화
//void init() {
//	for (int i = 0; i < 8; i++) {
//		visit[i] = false;
//	}
//}
//
//void check(int c, int r, int dir, char s) {
//	int cnt = 1; //돌의 갯수를 세기 위한 변수
//	int nc = c + dc[dir]; 
//	int nr = r + dr[dir];
//
//	//인자로 넘어온 탐색 방향으로 탐색 시작
//	while (true) {
//		//탐색할 다음 위치가 바둑판 안에 있고 그 위치에 같은 색의 바둑알이 있으면
//		if (nc >= 1 && nc < 20 && nr >= 1 && nr < 20 && map[nc][nr] == s) {
//			cnt++; //바둑돌 갯수 증가
//		}
//		//아니라면 종료
//		else {
//			break;
//		}
//		nc = nc + dc[dir];
//		nr = nr + dr[dir];
//	}
//
//	//탐색한 방향의 반대방향도 함께 탐색을 해줘야하므로 방향 재설정
//	if (dir > 3) {
//		dir = dir - 4;
//	}
//	else {
//		dir = dir + 4;
//	}
//	nc = c + dc[dir];
//	nr = r + dr[dir];
//
//	//탐색을 하지 않은 방향이라면 탐색 진행
//	while (!visit[dir]) {
//		//탐색할 다음 위치가 바둑판 안에 있고 그 위치에 같은 색의 바둑알이 있으면
//		if (nc >= 1 && nc < 20 && nr >= 1 && nr < 20 && map[nc][nr] == s) {
//			cnt++; //바둑돌 갯수 증가
//		}
//		//아니라면 종료
//		else {
//			break;
//		}
//		nc = nc + dc[dir];
//		nr = nr + dr[dir];
//	}
//	//방향을 탐색했다고 표시
//	visit[dir] = true;
//
//	//갯수가 5개라면 5개라고 표시
//	if (cnt == 5) {
//		flag = true;
//	}
//}
//
//void solve(char s) {
//	int c = q.front().first.first;
//	int r = q.front().first.second;
//	map[c][r] = s; //바둑판에 돌을 입력
//	init();
//	//8방 탐색
//	for (int i = 0; i < 8; i++) {
//		int nc = c + dc[i];
//		int nr = r + dr[i];
//		//탐색할 위치가 바둑판안에 있고 이미 탐색했던 방향이 아니라면
//		if (nc >= 1 && nc < 20 && nr >= 1 && nr < 20 && map[nc][nr] == s && visit[i] == false) {
//			visit[i] = true; //방향을 탐색했다고 표시
//			check(c, r, i, s);
//		}
//	}
//}
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
//
//	int N, count = 0; //몇번째에 게임이 끝나는지 세기위한 변수
//	
//	cin >> N;
//
//	//큐에 돌의 위치와 색 저장
//	for (int i = 1; i <= N; i++) {
//		int c, r;
//		cin >> c >> r;
//		if (i % 2 == 1) {
//			q.push(make_pair(make_pair(c, r), 'B'));
//		}
//		else {
//			q.push(make_pair(make_pair(c, r), 'W'));
//		}
//	}
//
//	while (!q.empty()) {
//		//돌이 5개가 되면 출력
//		if (flag) {
//			cout << count <<"\n";
//			return 0;
//		}
//		count++;
//		solve(q.front().second);
//		q.pop();
//	}
//
//	cout << -1 << "\n";
//
//  return 0;
//}