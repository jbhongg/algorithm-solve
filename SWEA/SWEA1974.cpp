//#include<iostream>
//#include<set>
//
//using namespace std;
//
//int map[9][9];
//set <int> s;
//bool flag;
//
//void check() {
//	//set�� ũ�Ⱑ 9�� �ƴϸ� �ߺ��� ���� ���� ���̹Ƿ� flag true�� ��ȯ
//	if (s.size() != 9) {
//		flag = true;
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
//	for (test_case = 1; test_case <= T; ++test_case)
//	{
//		flag = false; //�Ұ������� �������� Ȯ���ϱ� ���� boolean ����
//		int col = 0;
//		int row = 0;
//		int count = 0;
//		s.clear(); //set �ʱ�ȭ
//		//�� Ž��
//		for (int i = 0; i < 9; i++) {
//			s.clear(); //set �ʱ�ȭ
//			for (int j = 0; j < 9; j++) {
//				cin >> map[i][j];
//				s.insert(map[i][j]);
//			}
//			check();
//		}
//		//������ �Ұ����� �ƴϸ�
//		if (!flag) {
//			//��Ž��
//			for (int i = 0; i < 9; i++) {
//				s.clear(); //set �ʱ�ȭ
//				for (int j = 0; j < 9; j++) {
//					s.insert(map[j][i]);
//				}
//				check();
//				// �Ұ����̸� Ż��
//				if (flag) {
//					break;
//				}
//			}
//		}
//		//������ �Ұ����� �ƴϸ�
//		if (!flag) {
//			//��� ��� ���� Ž�� �Ϸ��Ҷ����� �ݺ� 
//			while (col != 9 && row != 9) {
//				s.clear(); //set �ʱ�ȭ
//				//3*3�� Ž��
//				for (int i = col; i < col + 3; i++) {
//					for (int j = row; j < row+3; j++) {
//						s.insert(map[i][j]);
//					}
//				}
//				check();
//				// �Ұ����̸� Ż��
//				if (flag) {
//					break;
//				}
//				count++; //�� Ž�� ���� ���� ���� ����
//				//3���� ��� Ž���� ���� ������ �̵�
//				col = col + 3;
//				//3���� ��� Ž�� �Ϸ��ϸ� ���� ���� �̵� ���� ó������
//				if ((count % 3) == 0) {
//					row = row + 3;
//					col = 0;
//				}
//			}
//		}
//		//�Ұ����̸� 0 ��� �ƴϸ� 1���
//		if (flag) {
//			cout << "#" << test_case << " " << 0 << "\n";
//		}
//		else {
//			cout << "#" << test_case << " " << 1 << "\n";
//		}
//	}
//	
//	return 0;
//}