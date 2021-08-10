//#include<iostream>
//#include<vector>
//#include<queue>
//#include<algorithm>
//
//using namespace std;
//
//int map[20][20];
//vector <pair <int, int>> v;
//vector <pair <int, int>> answer;
//int dc[4] = { -1,0,1,0 };
//int dr[4] = {0,1,0,-1};
//int N, M, result;
//bool visit[20][20];
//
//void init() {
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < M; j++) {
//			visit[i][j] = false;
//		}
//	}
//}
//
//int bfs(int i, int j) {
//	bool flag = false;
//	int cnt = 1;
//	queue <pair <int, int>> q;
//	q.push(make_pair(i, j));
//	visit[i][j] = true;
//	while (!q.empty()) {
//		int c = q.front().first;
//		int r = q.front().second;
//		q.pop();
//		//4��Ž��
//		for (int k = 0; k < 4; k++) {
//			int nc = c + dc[k];
//			int nr = r + dr[k];
//			//�ʾȿ� �ְ� �湮���� ���� ���̸�
//			if (nc >= 0 && nc < N && nr >= 0 && nr < M && visit[nc][nr] == false) {
//				//Ž���� ���� ���� ���� ������
//				if (map[nc][nr] == 2) {
//					visit[nc][nr] = true; //�湮�ߴٰ� ǥ��
//					q.push(make_pair(nc, nr)); //ť�� �߰�
//					cnt++; //���� ���� ����
//				}
//				//Ž���� ���� ��ĭ�̶�� 
//				else if (map[nc][nr] == 0) {
//					flag = true;
//				}
//			}
//		}
//	}
//	//�ֺ��� ��ĭ�� �ϳ��� ������ ���� ���� �ʱ�ȭ
//	if (flag) {
//		cnt = 0;
//	}
//	return cnt;
//}
//
//int cal() {
//	int count = 0;
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < M; j++) {
//			//���浹�� �ְ� �湮���� ���� ���̶��
//			if (map[i][j] == 2 && visit[i][j] == false) {
//				count = count + bfs(i, j); //���� ������ ����
//			}
//		}
//	}
//	return count;
//}
//
//bool check(int c, int r) {
//	//4�� Ž��
//	for (int i = 0; i < 4; i++) {
//		int nc = c + dc[i];
//		int nr = r + dr[i];
//		//�ʾȿ� �ְ� �ֺ��� ����� ���� ������ true ��ȯ
//		if (nc >= 0 && nc < N && nr >= 0 && nr < M && map[nc][nr] == 2) {
//			return true;
//		}
//	}
//	//�ֺ��� ����� ���� ������ false ��ȯ
//	return false;
//}
//
//
//void solve(int n, int idx) {
//	//���� 2�� ������
//	if (n == 2) {
//		//���� ���� ĭ�� ���� ���Ҵٰ� ó��
//		map[answer.at(0).first][answer.at(0).second] = 1;
//		map[answer.at(1).first][answer.at(1).second] = 1;
//		result = max(result, cal()); //���� ���� ���� �ִ� ���� ����
//		init(); //visit �迭 �ʱ�ȭ
//		//���� ����
//		map[answer.at(0).first][answer.at(0).second] = 0;
//		map[answer.at(1).first][answer.at(1).second] = 0;
//		return;
//	}
//
//	//����(��ĭ���� �����س��� ���͸� Ž��)
//	for (int i = idx; i < v.size(); i++) {
//		int c = v.at(i).first;
//		int r = v.at(i).second;
//		if (check(c, r)) {
//			answer.push_back(make_pair(c, r)); //���� ���� ĭ�� ����
//			solve(n + 1, i + 1); //���
//			answer.pop_back(); //���󺹱�
//		}
//	}
//}
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
//	
//	cin >> N >> M;
//
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < M; j++) {
//			cin >> map[i][j];
//			if (map[i][j] == 0) {
//				v.push_back(make_pair(i, j)); //��ĭ�� ��� ����
//			}
//		}
//	}
//
//	solve(0,0);
//
//	cout << result << "\n";
//	
//	return 0;
//}