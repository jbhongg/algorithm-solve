//#include<iostream>
//
//using namespace std;
//
//char map[64][64];
//
//void solve(int c, int r, int size) {
//	int zero = 0;
//	int one = 0;
//	//0�� 1�� ���� ����
//	for (int i = c; i < c+size; i++) {
//		for (int j = r; j < r+size; j++) {
//			if (map[i][j] == '0') {
//				zero++;
//			}
//			else if (map[i][j] == '1') {
//				one++;
//			}
//			//0�� 1�� ��� ������ Ż��
//			if (zero > 0 && one > 0) {
//				break;
//			}
//		}
//	}
//
//	//0�� 1�� ��� ������ ���� ����
//	if (zero > 0 && one > 0) {
//		cout << "("; //���������� "(" ���
//		solve(c, r,  size / 2); //1��и�
//		solve(c, r + (size / 2), size / 2); //2��и�
//		solve(c + (size / 2), r, size / 2); //4��и�
//		solve(c + (size / 2), r + (size / 2), size / 2); //3��и�
//		cout << ")"; //���ҳ������� ")" ���
//	}
//	//0�� ������ 0 ���
//	else if (zero > 0 && one == 0) {
//		cout << "0";
//		return;
//	}
//	//1�� ������ 1���
//	else if (zero == 0 && one > 0) {
//		cout << "1";
//		return;
//	}
//}
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
//
//	int N;
//
//	cin >> N;
//
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < N; j++) {
//			cin >> map[i][j];
//		}
//	}
//
//	solve(0, 0, N);
//
//	return 0;
//}