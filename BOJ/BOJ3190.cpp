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
//queue<pair<int, int>> snake; //���� ���� ǥ��
//
//void solve(int X, char C) {
//	int turn; //���� ���� �̵� ������ ���� ����
//	int x, y;
//
//	turn = l - r; //���� ���
//
//	switch (turn) {
//	case 0: //������ ����
//	{
//		while (time != X) {
//			//���� �Ӹ� �κ�
//			x = snake.back().first;
//			y = snake.back().second;
//			board[x][y] = -1; //���� ��ġ�� �ڱ��ڽ��� �ִٰ� ǥ��
//			//���� �ε����� �� ����
//			if (y + 1 >= N) {
//				time++;
//				e = true;
//				return;
//			}
//			//���� �̵��� ĭ�� ����� �ִٸ�
//			if (board[x][y + 1] == 1) {
//				snake.push(make_pair(x, y + 1)); //�� ���� ����
//				time++;
//			}
//			//���� �̵��� ĭ�� �ڱ� �ڽ��� ������ ����
//			else if (board[x][y + 1] == -1) {
//				time++;
//				e = true;
//				return;
//			}
//			//���� �̵��� ĭ�� ��ĭ�̶��
//			else {
//				board[snake.front().first][snake.front().second] = 0; //������ ��ġ�� ��������� ǥ��
//				//���� ��ġ�� ���ϰ� ���̴� ������ ����
//				snake.pop();
//				snake.push(make_pair(x, y + 1));
//				time++;
//			}
//		}
//		break;
//	}
//	//���� ����
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
//	//���� ����
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
//	//�Ʒ��� ����
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
//	//���� ��ȯ ������ L�̸�
//	if (C == 'L') {
//		l++; //�������� ��� �̵��ߴ����� ǥ���ϴ� ���� l ����
//		//�������� 4�� �̵��ϸ� ���� �ڸ��̹Ƿ� 0���� �ʱ�ȭ
//		if (l == 4) {
//			l = 0;
//		}
//	}
//	//���� ��ȯ ������ R�̸�
//	else if(C == 'R'){
//		r++; //������ ����
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
//	//����� ��ġ�� 1�� ǥ��
//	for (int i = 0; i < K; i++) {
//		cin >> col >> row;
//		board[col - 1][row - 1] = 1; //������ ���� 1�� 1������ ����
//	}
//	snake.push(make_pair(0, 0));
//	cin >> L;
//	for (int i = 0; i < L; i++) {
//		cin >> X >> C;
//		solve(X, C);
//		//���� �ε����ų� �ڱ��ڽſ��� �ε����� ��� ����
//		if (e) {
//			break;
//		}
//		//�־��� ������ �� �ߴµ��� ������ �ȳ������ 
//		if ((i + 1) == L && time == X) {
//			solve((-1), 'N'); //������ ���������� ����
//			break;
//		}
//	}
//
//	cout << time << "\n";
//	return 0;
//}