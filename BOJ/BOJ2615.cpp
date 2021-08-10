//#include<iostream>
//
//using namespace std;
//
//int map[19][19];
//
//int dc[4] = {0,1,1,1};
//int dr[4] = {1,1,0,-1};
//
//bool solve(int c, int r, int color, int dir) {
//	int count = 1; //���� ������ ���� ���� ����
//	int nc = c + dc[dir];
//	int nr = r + dr[dir];
//	//Ž���� ������ �ݴ���⿡ ���� ���� ���� ������ �̹� �غ� ���̹Ǹ� false ��ȯ
//	if (map[c - dc[dir]][r - dr[dir]] == color) {
//		return false;
//	}
//	while (true) {
//		//���� ������ 5�� �̻��̸� ����
//		if (count > 5) {
//			break;
//		}
//		//Ž���� ��ġ�� �ʾȿ� ���ų� ���� ���� ���� �ƴϸ� ����
//		if (nc < 0 || nc >= 19 || nr < 0 || nr >= 19 || map[nc][nr] != color) {
//			break;
//		}
//		//�ʾȿ� �ְ� ���� ���� ���̸� ���� ���� �� ���� ��ġ ���
//		count++;
//		nc = nc + dc[dir];
//		nr = nr + dr[dir];
//	}
//
//	//���� ������ 5���� true ��ȯ
//	if (count == 5) {
//		return true;
//	}
//	//�ƴϸ� false ��ȯ
//	else {
//		return false;
//	}
//}
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
//
//	bool flag = false;
//	int win = 0;
//	pair <int, int> p;
//
//	for (int i = 0; i < 19; i++) {
//		for (int j = 0; j < 19; j++) {
//			cin >> map[i][j];
//		}
//	}
//
//	for (int i = 0; i < 19; i++) {
//		for (int j = 0; j < 19; j++) {
//			//���� ������
//			if (map[i][j] != 0) {
//				//4�� Ž��
//				for (int k = 0; k < 4; k++) {
//					//��ȯ���� true�̸�
//					if (solve(i, j, map[i][j], k)) {
//						flag = true;     //���а� ���� ���ٰ� ǥ��
//						win = map[i][j]; //�̱� ���� ����
//						//Ž�� ������ ���� �밢�� �Ʒ��̸� ������ �ϼ��� ������ ���� ���� ���ʵ��̹Ƿ� ��� �� ��� �� ����
//						if (k == 3) {
//							p.first = i + 4;
//							p.second = j - 4;
//						}
//						//������ ������� ���� ���� ��ġ�� ���� ���� ���̹Ƿ� ��� �� �ٷ� ����
//						else {
//							p.first = i;
//							p.second = j;
//						}
//						break;
//					}
//				}
//				if (flag) {
//					break;
//				}
//			}
//		}
//		if (flag) {
//			break;
//		}
//	}
//	//���а� �������� ��
//	if (flag) {
//		cout << win << "\n" << p.first + 1 << " " << p.second + 1 << "\n";
//	}
//	//���º��� ��
//	else {
//		cout << win << "\n";
//	}
//	
//	return 0;
//}