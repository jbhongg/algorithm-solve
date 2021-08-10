//#include<iostream>
//
//using namespace std;
//
//char map[100][100];
//char temp[100][100];
//int N, M, R;
//int answer = 0;
//
//void attack(int c, int r, int d) {
//	int count; //넘어뜨릴 도미노의 수
//	//현재 위치의 도미노가 넘어져있으면 count는 1
//	if (map[c][r] == 'F') {
//		count = 1;
//	}
//	//현재 위치의 도미노가 있으면 count는 현재 위치의 도미노의 높이
//	else {
//		count = map[c][r] - '0';
//	}
//	int temp = 0;
//	switch (d)
//	{
//	//남쪽
//	case 'S':
//	{
//		//
//		for (int i = 0; i < count; i++) {
//			//다음 행의 위치가 맵을 벗어나면 탈출
//			if (c + i >= N) {
//				break;
//			}
//			//다음 맵의 위치에 도미노가 있으면
//			if (map[c + i][r] != 'F') {
//				temp = (map[c + i][r] - '0') + i; //현재 위치에서 쓰러뜨릴 도미노의 수 계산
//			}
//			//다음 맵의 위치에 도미노가 쓰러져 있으면
//			else if (map[c + i][r] == 'F') {
//				answer--; //쓰러뜨린 도미노 갯수 감소(이미 쓰러져 있으니까)
//			}
//			//쓰러뜨릴 도미노의 수가 증가하면
//			if (temp > count) {
//				count = temp; //넘어뜨릴 도미노의 수를 바꿔줌
//			}
//			map[c + i][r] = 'F'; //도미노를 쓰러뜨림
//			answer++; //쓰러뜨린 도미노 갯수 증가
//		}
//	}
//	break;
//	//북쪽
//	case 'N':
//	{
//		for (int i = 0; i < count; i++) {
//			//다음 행의 위치가 맵을 벗어나면 탈출
//			if (c - i < 0) {
//				break;
//			}
//			//다음 맵의 위치에 도미노가 있으면
//			if (map[c - i][r] != 'F') {
//				temp = (map[c - i][r] - '0') + i; //현재 위치에서 쓰러뜨릴 도미노의 수 계산
//			}
//			//다음 맵의 위치에 도미노가 쓰러져 있으면
//			else if (map[c - i][r] == 'F') {
//				answer--; //쓰러뜨린 도미노 갯수 감소(이미 쓰러져 있으니까)
//			}
//			//쓰러뜨릴 도미노의 수가 증가하면
//			if (temp > count) {
//				count = temp; //넘어뜨릴 도미노의 수를 바꿔줌
//			}
//			map[c - i][r] = 'F'; //도미노를 쓰러뜨림
//			answer++; //쓰러뜨린 도미노 갯수 증가
//		}
//	}
//	break;
//	//서쪽
//	case 'W':
//	{
//		for (int i = 0; i < count; i++) {
//			//다음 열의 위치가 맵을 벗어나면 탈출
//			if (r - i < 0) {
//				break;
//			}
//			//다음 맵의 위치에 도미노가 있으면
//			if (map[c][r-i] != 'F') {
//				temp = (map[c][r-i] - '0') + i; //현재 위치에서 쓰러뜨릴 도미노의 수 계산
//			}
//			//다음 맵의 위치에 도미노가 쓰러져 있으면
//			else if (map[c][r-i] == 'F') {
//				answer--; //쓰러뜨린 도미노 갯수 감소(이미 쓰러져 있으니까)
//			}
//			//쓰러뜨릴 도미노의 수가 증가하면
//			if (temp > count) {
//				count = temp;  //넘어뜨릴 도미노의 수를 바꿔줌
//			}
//			map[c][r-i] = 'F'; //도미노를 쓰러뜨림
//			answer++; //쓰러뜨린 도미노 갯수 증가
//		}
//	}
//	break;
//	//동쪽
//	case 'E':
//	{
//		for (int i = 0; i < count; i++) {
//			//다음 열의 위치가 맵을 벗어나면 탈출
//			if (r + i >= M) {
//				break;
//			}
//			//다음 맵의 위치에 도미노가 있으면
//			if (map[c][r+i] != 'F') {
//				temp = (map[c][r+i] - '0') + i; //현재 위치에서 쓰러뜨릴 도미노의 수 계산
//			}
//			//다음 맵의 위치에 도미노가 쓰러져 있으면
//			else if (map[c][r + i] == 'F') {
//				answer--; //쓰러뜨린 도미노 갯수 감소(이미 쓰러져 있으니까)
//			}
//			//쓰러뜨릴 도미노의 수가 증가하면
//			if (temp > count) {
//				count = temp; //넘어뜨릴 도미노의 수를 바꿔줌
//			}
//			map[c][r+i] = 'F'; //도미노를 쓰러뜨림
//			answer++; //쓰러뜨린 도미노 갯수 증가
//		}
//	}
//	break;
//	}
//}
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
//
//	cin >> N >> M >> R;
//
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < M; j++) {
//			cin >> map[i][j];
//			temp[i][j] = map[i][j];
//		}
//	}
//
//	for (int i = 0; i < R; i++) {
//		int X, Y;
//		char D;
//		cin >> X >> Y >> D;
//		attack(X-1, Y-1, D); //공격
//		cin >> X >> Y;
//		map[X-1][Y-1] = temp[X-1][Y-1]; //방어(현재 위치 도미노 원상복귀)
//	}
//
//	cout << answer << "\n";
//
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < M; j++) {
//			//현재 위치에 도미노가 있으면 'S'로 바꿈
//			if (map[i][j] != 'F') {
//				map[i][j] = 'S';
//			}
//			cout << map[i][j] << " ";
//		}
//		cout << "\n";
//	}
//	
//	return 0;
//}