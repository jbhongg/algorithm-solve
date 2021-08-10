//#include<iostream>
//#include<queue>
//
//using namespace std;
//char map[12][6];
//int dc[4] = {-1,0,1,0};
//int dr[4] = {0,1,0,-1};
//queue <pair<int, int>> q;
//bool visit[12][6], temp[12][6];
//int answer;
//
//bool check() {
//	int count = 0; //터트릴 뿌요의 갯수를 셀 변수
//	for (int i = 0; i < 12; i++) {
//		for (int j = 0; j < 6; j++) {
//			//터트릴 뿌요가 있으면 갯수 증가
//			if (visit[i][j]) {
//				count++;
//			}
//		}
//	}
//	//갯수가 0개라면 true 반환
//	if (count == 0) {
//		return true;
//	}
//	//터트릴 뿌요가 있다면 false 반환
//	else {
//		return false;
//	}
//}
//
//void move() {
//	//아래서부터 열 탐색
//	for (int i = 0; i < 6; i++) {
//		for (int j = 11; j > 0; j--) {
//			//빈칸을 만나면
//			if (map[j][i] == '.') {
//				int k = j-1; //현재의 행 위치보다 한칸 위칸부터 탐색
//				//빈칸이 아닐때까지 진행
//				while (map[k][i] == '.') {
//					k--; //행 한칸 위로 이동
//					//탐색할 행이 맵을 벗어나면 종료
//					if (k < 0) {
//						break;
//					}
//				}
//				//탐색한 행이 맵안에 있으면
//				if (k >= 0) {
//					//현재의 위치에 탐색한 행의 값을 넣어주고 탐색한 행을 빈칸으로 바꾸어줌
//					map[j][i] = map[k][i];
//					map[k][i] = '.';
//				}
//				//탐색할 행이 맵을 벗어았으면 종료
//				else {
//					break;
//				}
//			}
//		}
//	}
//}
//
//void bomb() {
//	for (int i = 0; i < 12; i++) {
//		for (int j = 0; j < 6; j++) {
//			//터트릴 뿌요를 만나면
//			if (visit[i][j]) {
//				//그 위치를 빈칸으로 만들어주고 visit와 temp 배열 false로 변환
//				map[i][j] = '.';
//				visit[i][j] = false;
//				temp[i][j] = false;
//			}
//		}
//	}
//	//모두 터트린 후 남은 뿌요들을 아래로 이동시킴
//	move();
//}
//
//void back() {
//	//visit 배열을 이전 상태로 되돌림
//	for (int i = 0; i < 12; i++) {
//		for (int j = 0; j < 6; j++) {
//			visit[i][j] = temp[i][j];
//		}
//	}
//}
//
//void solve(char color) {
//	int count = 1;
//	while (!q.empty()) {
//		int c = q.front().first;
//		int r = q.front().second;
//		//사방 탐색
//		for (int i=0; i < 4; i++) {
//			int nc = c + dc[i];
//			int nr = r + dr[i];
//			//다음 위치가 맵안에 있고 다음 위치의 값이 인자로 넘어온 값과 같다면
//			if (nc >= 0 && nc < 12 && nr >= 0 && nr < 6 && visit[nc][nr] == false && map[nc][nr] == color) {
//				q.push(make_pair(nc, nr)); //큐에 다음 위치 저장
//				visit[nc][nr] = true; //visit 배열 true로 변환
//				count++; //뿌요 갯수 세기
//			}
//		}
//		q.pop(); //큐에서 제거
//	}
//	//만약 뿌요의 갯수가 4이상이면 터트림
//	if (count >= 4) {
//		//temp배열을 visit배열과 동기화 시켜줌
//		for (int i = 0; i < 12; i++) {
//			for (int j = 0; j < 6; j++) {
//				temp[i][j] = visit[i][j];
//			}
//		}
//	}
//	//만약 뿌요의 갯수가 3이하라면 터트리지 않음
//	else {
//		back();
//	}
//}
//
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
//
//	for (int i = 0; i < 12; i++) {
//		string s;
//		cin >> s;
//		for (int j = 0; j < 6; j++) {
//			map[i][j] = s[j];
//		}
//	}
//	while (true) {
//		for (int i = 0; i < 12; i++) {
//			for (int j = 0; j < 6; j++) {
//				//빈칸이 아니고 visit 배열이 false라면
//				if (map[i][j] != '.' && visit[i][j] == false) {
//					q.push(make_pair(i, j)); //큐에 현재 위치 저장
//					visit[i][j] = true; //visit 배열 true로 변환
//					solve(map[i][j]); //인자로 현재위치의 값을 가지고 감
//				}
//			}
//		}
//		//터트릴 뿌요가 없으면 종료
//		if (check()) {
//			break;
//		}
//		//터트릴 뿌요가 있다면 터트리기
//		bomb();
//		answer++; //몇번 터트렸는지 세기
//	}
//
//	cout << answer << "\n";
//	return 0;
//}