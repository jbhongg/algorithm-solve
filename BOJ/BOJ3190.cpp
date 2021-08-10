//#include<iostream>
//#include<queue>
//#include<utility>
//
//using namespace std;
//
//int N, K, col, row, L, X, r, l, time;
//bool e;
//char C;
//int board[100][100];
//queue<pair<int, int>> snake; //벰의 상태 표시
//
//void solve(int X, char C) {
//	int turn; //뱀의 현재 이동 방향을 위한 변수
//	int x, y;
//
//	turn = l - r; //방향 계산
//
//	switch (turn) {
//	case 0: //오른쪽 방향
//	{
//		while (time != X) {
//			//뱀의 머리 부분
//			x = snake.back().first;
//			y = snake.back().second;
//			board[x][y] = -1; //현재 위치에 자기자신이 있다고 표시
//			//벽에 부딪혔을 때 종료
//			if (y + 1 >= N) {
//				time++;
//				e = true;
//				return;
//			}
//			//다음 이동할 칸에 사과가 있다면
//			if (board[x][y + 1] == 1) {
//				snake.push(make_pair(x, y + 1)); //뱀 길이 증가
//				time++;
//			}
//			//다음 이동할 칸에 자기 자신이 있으면 종료
//			else if (board[x][y + 1] == -1) {
//				time++;
//				e = true;
//				return;
//			}
//			//다음 이동할 칸이 빈칸이라면
//			else {
//				board[snake.front().first][snake.front().second] = 0; //현재의 위치를 빈공간으로 표시
//				//뱀의 위치만 변하고 길이는 변하지 않음
//				snake.pop();
//				snake.push(make_pair(x, y + 1));
//				time++;
//			}
//		}
//		break;
//	}
//	//위쪽 방향
//	case -3:
//	case 1:
//	{
//		while (time != X) {
//			x = snake.back().first;
//			y = snake.back().second;
//			board[x][y] = -1;
//			if (x - 1 < 0) {
//				time++;
//				e = true;
//				return;
//			}
//			if (board[x - 1][y] == 1) {
//				snake.push(make_pair(x - 1, y));
//				time++;
//			}
//			else if (board[x - 1][y] == -1) {
//				time++;
//				e = true;
//				return;
//			}
//			else {
//				board[snake.front().first][snake.front().second] = 0;
//				snake.pop();
//				snake.push(make_pair(x - 1, y));
//				time++;
//			}
//		}
//		break;
//	}
//	//왼쪽 방향
//	case -2:
//	case 2:
//	{
//		while (time != X) {
//			x = snake.back().first;
//			y = snake.back().second;
//			board[x][y] = -1;
//			if (y - 1 < 0) {
//				time++;
//				e = true;
//				return;
//			}
//			if (board[x][y - 1] == 1) {
//				snake.push(make_pair(x, y - 1));
//				time++;
//			}
//			else if (board[x][y - 1] == -1) {
//				time++;
//				e = true;
//				return;
//			}
//			else {
//				board[snake.front().first][snake.front().second] = 0;
//				snake.pop();
//				snake.push(make_pair(x, y - 1));
//				time++;
//			}
//		}
//		break;
//	}
//	//아래쪽 방향
//	case -1:
//	case 3:
//	{
//		while (time != X) {
//			x = snake.back().first;
//			y = snake.back().second;
//			board[x][y] = -1;
//			if (x + 1 >= N) {
//				time++;
//				e = true;
//				return;
//			}
//			if (board[x + 1][y] == 1) {
//				snake.push(make_pair(x + 1, y));
//				time++;
//			}
//			else if (board[x + 1][y] == -1) {
//				time++;
//				e = true;
//				return;
//			}
//			else {
//				board[snake.front().first][snake.front().second] = 0;
//				snake.pop();
//				snake.push(make_pair(x + 1, y));
//				time++;
//			}
//		}
//		break;
//	}
//	}
//
//	//방향 변환 정보가 L이면
//	if (C == 'L') {
//		l++; //왼쪽으로 몇번 이동했는지를 표시하는 변수 l 증가
//		//왼쪽으로 4번 이동하면 원해 자리이므로 0으로 초기화
//		if (l == 4) {
//			l = 0;
//		}
//	}
//	//방향 변환 정보가 R이면
//	else if(C == 'R'){
//		r++; //오른쪽 증가
//		if (r == 4) {
//			r = 0;
//		}
//	}
//}
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
//
//	cin >> N >> K;
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < N; j++) {
//			board[i][j] = 0;
//		}
//	}
//	//사과의 위치를 1로 표시
//	for (int i = 0; i < K; i++) {
//		cin >> col >> row;
//		board[col - 1][row - 1] = 1; //문제의 맵은 1행 1열부터 시작
//	}
//	snake.push(make_pair(0, 0));
//	cin >> L;
//	for (int i = 0; i < L; i++) {
//		cin >> X >> C;
//		solve(X, C);
//		//벽에 부딪혔거나 자기자신에게 부딪혔을 경우 종료
//		if (e) {
//			break;
//		}
//		//주어진 정보를 다 했는데도 게임이 안끝난경우 
//		if ((i + 1) == L && time == X) {
//			solve((-1), 'N'); //게임이 끝날때까지 진행
//			break;
//		}
//	}
//
//	cout << time << "\n";
//	return 0;
//}