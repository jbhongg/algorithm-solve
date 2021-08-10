//#include<iostream>
//
//using namespace std;
//
//bool change = false; //�ٵϵ��� �ٲ��� ���� ���ϴ� ����
//int map[8][8];
//int N;
//int dc[8] = { -1,-1,0,1,1,1,0,-1 };
//int dr[8] = { 0,1,1,1,0,-1,-1,-1 };
//
//void go(int nc, int nr, int d, int type, int c) {
//	nc = nc + dc[d];
//	nr = nr + dr[d];
//
//	//���� ĭ�� ���� ����� �ʰ� ���� ���� �ٵϵ��̶�� ��ĭ �� ����
//	if (nc >= 0 && nc < N && nr >= 0 && nr < N && map[nc][nr] == type) {
//		go(nc, nr, d, type, c);
//		//���ݱ��� Ž���ߴ� �ٵϵ� �ٲٱ�
//		if (change == true) {
//			map[nc][nr] = c;
//		}
//	}
//	//���� ĭ�� ���� ����� �ʰ� ó���� ���� ���� �ٵϵ��̶�� Ž�� ����
//	else if (nc >= 0 && nc < N && nr >= 0 && nr < N && map[nc][nr] == c) {
//		change = true;
//		return;
//	}
//	//���� ĭ�� ���� ����ų� ��ĭ�� ��� ����
//	else
//		return;
//
//}
//
//// ���� �ٵϵ� �ֺ� 8�濡 �ٸ��� �ٵϵ��� �ִ��� üũ
//void check(int column, int row, int type) {
//	//������� �ȹ� Ž��
//	for (int i = 0; i < 8; i++) {
//		int nc = column + dc[i];
//		int nr = row + dr[i];
//		//�ٸ����� �ٵϵ��� �ִٸ� �� �������� ��� Ž���ϱ� ���� �Լ��� ��
//		if (type == 1 && map[nc][nr] == 2) {
//			go(nc, nr, i, 2, 1);
//			if (change == true) {
//				map[nc][nr] = 1;
//			}
//			change = false;
//		}
//		else if (type == 2 && map[nc][nr] == 1) {
//			go(nc, nr, i, 1, 2);
//			if (change == true) {
//				map[nc][nr] = 2;
//			}
//			change = false;
//		}
//	}
//}
//
//void init() {
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < N; j++) {
//			map[i][j] = 0;
//		}
//	}
//}
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
//
//	int test_case, T;
//	cin >> T;
//
//	for (test_case = 1; test_case <= T; ++test_case)
//	{
//		int M, row, column, type, black = 0, white = 0;
//		cin >> N >> M;
//
//		init(); //�� �ʱ�ȭ
//		map[N / 2 - 1][N / 2 - 1] = 2;
//		map[N / 2 - 1][N / 2] = 1;
//		map[N / 2][N / 2 - 1] = 1;
//		map[N / 2][N / 2] = 2;
//
//		for (int i = 0; i < M; i++) {
//			cin >> row >> column >> type;
//			map[column - 1][row - 1] = type;
//			check(column - 1, row - 1, type);
//		}
//
//		//�ٵϵ� ����
//		for (int i = 0; i < N; i++) {
//			for (int j = 0; j < N; j++) {
//				if (map[i][j] == 1) {
//					black++;
//				}
//				else if (map[i][j] == 2) {
//					white++;
//				}
//			}
//		}
//		cout << "#" << test_case << " " << black << " " << white << "\n";
//	}
//
//	return 0;
//}