//#include<iostream>
//#include<algorithm>
//#include<queue>
//
//using namespace std;
//
//int N, M;
//int answer, safe, cnt;
//int map[8][8];
//int temp[8][8];
//int dc[4] = { -1,0,1,0 };
//int dr[4] = { 0,1,0,-1 };
//bool flag;
//
//void init() {
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < M; j++) {
//			temp[i][j] = map[i][j];
//		}
//	}
//}
//
//void solve() {
//	safe = 0;
//	queue <pair<int, int>> q;
//
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < M; j++) {
//			//���̷����� ť�� ����
//			if (temp[i][j] == 2) {
//				q.push(make_pair(i, j));
//			}
//			//��ĭ�� �� ����
//			if (temp[i][j] == 0) {
//				safe++;
//			}
//		}
//	}
//
//	while (!q.empty())
//	{
//		int c = q.front().first;
//		int r = q.front().second;
//		q.pop();
//		//4�� Ž��
//		for (int k = 0; k < 4; k++) {
//			int nc = c + dc[k];
//			int nr = r + dr[k];
//			//Ž���� ��ġ�� �� �ȿ� �ְ� ��ĭ�̶��
//			if (nc >= 0 && nc < N && nr >= 0 && nr < M && temp[nc][nr] == 0) {
//				temp[nc][nr] = 2;  //Ž�� ��ġ�� ���̷��� Ȯ��
//				q.push(make_pair(nc, nr)); //ť�� ���� ��ġ �߰�
//				safe--; //0�� ���� �ϳ� ����
//			}
//		}
//	}
//}
//
//void wall(int cnt) {
//	//���� �� ��������
//	if (cnt == 3) {
//		init(); //temp�迭 �ʱ�ȭ
//		solve();
//		answer = max(safe, answer); //�ִ� ����
//		return;
//	}
//
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < M; j++) {
//			//��ĭ�̸�
//			if (map[i][j] == 0) {
//				//���� ����
//				map[i][j] = 1;
//				wall(cnt+1); //���
//				//���� ����
//				map[i][j] = 0;
//			}
//		}
//	}
//}
//
//int main() {
//
//	cin >> N >> M;
//
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < M; j++) {
//			cin >> map[i][j];
//		}
//	}
//
//	wall(0);
//	cout << answer << "\n";
//	return 0;
//}