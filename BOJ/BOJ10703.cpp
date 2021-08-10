//#include<iostream>
//#include<algorithm>
//#include<vector>
//
//using namespace std;
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
//
//	int R, S, air = 0;
//	int meteor = -1;
//	int minn = 1000000;
//	string s;
//
//	cin >> R >> S;
//
//	vector<string> map; //���� �Է¹ޱ����� ����
//
//	// ���� �Է¹���
//	for (int i = 0; i < R; i++) {
//		string s;
//		cin >> s;
//		map.push_back(s);
//	}
//
//	//���� ���η� Ž�� 
//	for (int i = 0; i < S; i++) {
//		for (int j = 0; j < R; j++) {
//			//���� �Ʒ��ִ� ������ ��ġ�� Ž�� �� ����
//			if (map[j][i] == 'X' && map[j + 1][i] == '.') {
//				meteor = j;
//			}
//			// �� �ٷ� ���� �ִ� ������ ��ġ ����(���� ���� ��� ������ �ε����� ��ġ ����)
//			else if (map[j][i] == '.' && j == R - 1 || (map[j][i] == '.' && map[j + 1][i] == '#')) {
//				air = j;
//				break;
//			}
//		}
//		// ������ ���� �Ÿ� �ּڰ��� ���� �� ������ ��ġ �ʱ�ȭ
//		if (meteor != -1) {
//			minn = min(minn, (air - meteor));
//			meteor = -1;
//		}
//	}
//
//	// �������� ��ġ�� �̵�(�̵��� ������ Ž������ �ʵ��� �Ʒ������� Ž��)
//	for (int i = R - 1; i >= 0; i--) {
//		for (int j = 0; j < S; j++) {
//			if (map[i][j] == 'X') {
//				map[i][j] = '.';
//				map[i + minn][j] = 'X';
//			}
//		}
//	}
//
//	for (int i = 0; i < R; i++) {
//		for (int j = 0; j < S; j++) {
//			cout << map[i][j];
//		}
//		cout << endl;
//	}
//	return 0;
//}