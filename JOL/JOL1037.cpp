//#include<iostream>
//
//using namespace std;
//
//int map[100][100];
//int sum_row[100];
//int sum_col[100];
//int n,c,r;
//
//void solve_col(int idx) {
//	for (int i = 0; i < n; i++) {
//		//���� �࿡ �ش��ϴ� ���� �� 1�� ������ Ȧ�� �� ���� ������ ���� ���� ���� ���� �ٲٸ� �ȴٴ� �ǹ�
//		if (sum_row[i] % 2 == 1) {
//			c = idx;
//			r = i;
//			break;
//		}
//	}
//}
//
//void solve_row(int idx) {
//	for (int i = 0; i < n; i++) {
//		//���� ���� �ش��ϴ� ��� �� 1�� ������ Ȧ�� �� ���� ������ ���� ���� ���� ���� �ٲٸ� �ȴٴ� �ǹ�
//		if (sum_col[i] % 2 == 1) {
//			c = i;
//			r = idx;
//		}
//	}
//}
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
//
//	int count_col = 0, count_row = 0;
//
//	cin >> n;
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < n; j++) {
//			cin >> map[i][j];
//		}
//	}
//	//�� ��� ���� 1�� ���� ����
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < n; j++) {
//			sum_col[i] = sum_col[i] + map[i][j];
//			sum_row[i] = sum_row[i] + map[j][i];
//		}
//	}
//
//	for (int i = 0; i < n; i++) {
//		//�� ���̳� ���� 1�� ������ Ȧ���� ���� 2�� �̻��̸� ����
//		if (count_col > 1 || count_row > 1) {
//			break;
//		}
//		//���� ���� 1�� ������ Ȧ�����
//		if (sum_col[i] % 2 == 1) {
//			count_col++;  //���� Ȧ�� ������ ��Ÿ���� ���� ����
//			solve_col(i); //���� ������ ���ڷ� �Ѱܼ� �Լ� �̵�
//		}
//		//���� ���� 1�� ������ Ȧ�����
//		if (sum_row[i] % 2 == 1) {
//			count_row++;  //���� Ȧ�� ������ ��Ÿ���� ���� ����
//			solve_row(i); //���� ������ ���ڷ� �Ѱܼ� �Լ� �̵�
//		}
//	}
//
//	//�� ���̳� ���� 1�� ������ Ȧ���� ���� 2�� �̻��̸� �Ұ� ���
//	if (count_col > 1 || count_row > 1) {
//		cout << "Corrupt" << "\n";
//	}
//	//�� ��� ���� 1�� ������ ��� ¦���̸� ���� ���
//	else if (count_col == 0 && count_row == 0) {
//		cout << "OK" << "\n";
//	}
//	//�Ѵ� �ƴϸ� �ϳ��� ���� �ٲٸ� �ǹǷ� ���� Ž������ ã�� ��� ���� ������ ���
//	else {
//		cout << "Change bit (" << c+1 << "," << r+1 << ")" << "\n";
//	}
//	
//	return 0;
//}