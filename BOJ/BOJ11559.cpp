//#include<iostream>
//#include<queue>
//
//using namespace std;
//char map[12][6];
//int dc[4] = {-1,0,1,0};
//int dr[4] = {0,1,0,-1};
//queue <pair<int, int>> q;
//bool visit[12][6], temp[12][6];
//int answer;
//
//bool check() {
//	int count = 0; //��Ʈ�� �ѿ��� ������ �� ����
//	for (int i = 0; i < 12; i++) {
//		for (int j = 0; j < 6; j++) {
//			//��Ʈ�� �ѿ䰡 ������ ���� ����
//			if (visit[i][j]) {
//				count++;
//			}
//		}
//	}
//	//������ 0����� true ��ȯ
//	if (count == 0) {
//		return true;
//	}
//	//��Ʈ�� �ѿ䰡 �ִٸ� false ��ȯ
//	else {
//		return false;
//	}
//}
//
//void move() {
//	//�Ʒ������� �� Ž��
//	for (int i = 0; i < 6; i++) {
//		for (int j = 11; j > 0; j--) {
//			//��ĭ�� ������
//			if (map[j][i] == '.') {
//				int k = j-1; //������ �� ��ġ���� ��ĭ ��ĭ���� Ž��
//				//��ĭ�� �ƴҶ����� ����
//				while (map[k][i] == '.') {
//					k--; //�� ��ĭ ���� �̵�
//					//Ž���� ���� ���� ����� ����
//					if (k < 0) {
//						break;
//					}
//				}
//				//Ž���� ���� �ʾȿ� ������
//				if (k >= 0) {
//					//������ ��ġ�� Ž���� ���� ���� �־��ְ� Ž���� ���� ��ĭ���� �ٲپ���
//					map[j][i] = map[k][i];
//					map[k][i] = '.';
//				}
//				//Ž���� ���� ���� ��������� ����
//				else {
//					break;
//				}
//			}
//		}
//	}
//}
//
//void bomb() {
//	for (int i = 0; i < 12; i++) {
//		for (int j = 0; j < 6; j++) {
//			//��Ʈ�� �ѿ並 ������
//			if (visit[i][j]) {
//				//�� ��ġ�� ��ĭ���� ������ְ� visit�� temp �迭 false�� ��ȯ
//				map[i][j] = '.';
//				visit[i][j] = false;
//				temp[i][j] = false;
//			}
//		}
//	}
//	//��� ��Ʈ�� �� ���� �ѿ���� �Ʒ��� �̵���Ŵ
//	move();
//}
//
//void back() {
//	//visit �迭�� ���� ���·� �ǵ���
//	for (int i = 0; i < 12; i++) {
//		for (int j = 0; j < 6; j++) {
//			visit[i][j] = temp[i][j];
//		}
//	}
//}
//
//void solve(char color) {
//	int count = 1;
//	while (!q.empty()) {
//		int c = q.front().first;
//		int r = q.front().second;
//		//��� Ž��
//		for (int i=0; i < 4; i++) {
//			int nc = c + dc[i];
//			int nr = r + dr[i];
//			//���� ��ġ�� �ʾȿ� �ְ� ���� ��ġ�� ���� ���ڷ� �Ѿ�� ���� ���ٸ�
//			if (nc >= 0 && nc < 12 && nr >= 0 && nr < 6 && visit[nc][nr] == false && map[nc][nr] == color) {
//				q.push(make_pair(nc, nr)); //ť�� ���� ��ġ ����
//				visit[nc][nr] = true; //visit �迭 true�� ��ȯ
//				count++; //�ѿ� ���� ����
//			}
//		}
//		q.pop(); //ť���� ����
//	}
//	//���� �ѿ��� ������ 4�̻��̸� ��Ʈ��
//	if (count >= 4) {
//		//temp�迭�� visit�迭�� ����ȭ ������
//		for (int i = 0; i < 12; i++) {
//			for (int j = 0; j < 6; j++) {
//				temp[i][j] = visit[i][j];
//			}
//		}
//	}
//	//���� �ѿ��� ������ 3���϶�� ��Ʈ���� ����
//	else {
//		back();
//	}
//}
//
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
//
//	for (int i = 0; i < 12; i++) {
//		string s;
//		cin >> s;
//		for (int j = 0; j < 6; j++) {
//			map[i][j] = s[j];
//		}
//	}
//	while (true) {
//		for (int i = 0; i < 12; i++) {
//			for (int j = 0; j < 6; j++) {
//				//��ĭ�� �ƴϰ� visit �迭�� false���
//				if (map[i][j] != '.' && visit[i][j] == false) {
//					q.push(make_pair(i, j)); //ť�� ���� ��ġ ����
//					visit[i][j] = true; //visit �迭 true�� ��ȯ
//					solve(map[i][j]); //���ڷ� ������ġ�� ���� ������ ��
//				}
//			}
//		}
//		//��Ʈ�� �ѿ䰡 ������ ����
//		if (check()) {
//			break;
//		}
//		//��Ʈ�� �ѿ䰡 �ִٸ� ��Ʈ����
//		bomb();
//		answer++; //��� ��Ʈ�ȴ��� ����
//	}
//
//	cout << answer << "\n";
//	return 0;
//}