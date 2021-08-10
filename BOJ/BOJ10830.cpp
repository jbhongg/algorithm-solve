//#include<iostream>
//
//using namespace std;
//
//long long map[5][5], answer[5][5], temp[5][5];
//long long N, B;
//
//void print() {
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < N; j++) {
//			cout << answer[i][j] << " ";
//		}
//		cout << "\n";
//	}
//}
//
//void cal(long long x[5][5], long long y[5][5]) {
//	//��� ����
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < N; j++) {
//			temp[i][j] = 0;
//			for (int k = 0; k < N; k++) {
//				temp[i][j] += (x[i][k] * y[k][j]);
//			}
//			temp[i][j] %= 1000;
//		}
//	}
//
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < N; j++) {
//			x[i][j] = temp[i][j];
//		}	
//	}
//}
//
//void solve(long long b) {
//	//������ 2�� ���� ���� 0�̸� ���
//	if (b == 0) {
//		print();
//		return;
//	}
//	//������ Ȧ���̸�  ex) (A^2)^2*A -> (A)^2 -> E * A
//	if (b % 2 == 1) {
//		cal(answer, map); //��� ���
//		//������ 2�� ���� ���� 1�̸� ����(�������̹Ƿ� A^2�� ���� �ʿ䰡 ����)
//		if (b != 1) {
//			cal(map, map); //��� ���
//		}
//		solve(b / 2); //������ 2�� ���� ���� ���ڷ� ���
//	}
//	//������ ¦���̸� ex) (A^2)^2 -> A^2 -> E * A
//	else {
//		cal(map, map); //��� ���
//		solve(b / 2); //������ 2�� ���� ���� ���ڷ� ���
//	}
//}
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
//
//	cin >> N >> B;
//
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < N; j++) {
//			cin >> map[i][j];
//		}
//		answer[i][i] = 1; //���� ��� �����
//	}
//
//	solve(B);
//	return 0;
//}