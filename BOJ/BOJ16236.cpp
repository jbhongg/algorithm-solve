//#include<iostream>
//#include<vector>
//#include<queue>
//#include<algorithm>
//#include<limits.h>
//
//using namespace std;
//
//bool flag;
//int map[21][21];
//int cnt, answer, eat, N, w = 2;
//vector < pair <int, int> > v; // �Ʊ���
//int visit[21][21];
//int dc[4] = {-1,0,1,0};
//int dr[4] = { 0,1,0,-1 };
//vector <pair <int, int> > f; //����
//vector <pair <pair <int, int>, int > >  e; //������
//
//void init() {
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < N; j++) {
//			visit[i][j] = -1;
//		}
//	}
//}
//
//void bfs() {
//	queue < pair < pair <int, int>, int > > q;
//	q.push(make_pair(make_pair(v.front().first, v.front().second), 0)); //ť�� �Ʊ��� ��ġ�� �Ÿ����� ����
//	visit[v.front().first][v.front().second] = 0; //visit �迭�� �Ÿ��� ����
//	while (!q.empty()) {
//		int c = q.front().first.first;
//		int r = q.front().first.second;
//		int count = q.front().second; //�Ÿ���
//		q.pop();
//		//4�� Ž��
//		for (int i = 0; i < 4; i++) {
//			int nc = c + dc[i];
//			int nr = r + dr[i];
//			//Ž���� ��ġ�� �ʾȿ� �ְ� �湮���� �ʾҴٸ�
//			if (nc >= 0 && nc < N && nr >= 0 && nr < N && visit[nc][nr] == -1) {
//				//Ž�� ��ġ�� ��ĭ�̰ų� �Ʊ� ���� ���� ũ����
//				if (map[nc][nr] == 0 || map[nc][nr] == w) {
//					visit[nc][nr] = count+1; //�ش� ��ġ�� visit �迭�� ���� �Ÿ� + 1�� �� ���� ����
//					q.push(make_pair(make_pair(nc, nr), count + 1)); //ť�� Ž�� ��ġ�� ���� �Ÿ� + 1 �� ���� �߰� 
//				}
//				////Ž�� ��ġ�� ��ĭ�� �ƴϰ� �Ʊ�� ������ �ִ� ũ����
//				else if (map[nc][nr] != 0 && map[nc][nr] < w) {
//					visit[nc][nr] = count + 1; //�ش� ��ġ�� visit �迭�� ���� �Ÿ� + 1�� �� ���� ����
//				}
//			}
//		}
//	}
//}
//
//void solve() {
//	e.push_back(make_pair(make_pair(INT_MAX, INT_MAX), INT_MAX)); //���� ���̸� ��Ÿ���� ���͸� �ִ����� �ʱ�ȭ
//	//���̰� ����Ǿ� �ִ� ������ ũ�⸸ŭ Ž��
//	for (int i = 0; i < f.size(); i++) {
//		//���� ���̱����� �Ÿ��� ���� Ž���ϰ� �ִ� ���̱����� �Ÿ��� ���ٸ�
//		if (e.front().second == visit[f.at(i).first][f.at(i).second]) {
//			//���� ���̿� ���� Ž���ϰ� �ִ� ������ ���� ���ٸ�
//			if (e.front().first.first == f.at(i).first) {
//				//���� ���̺��� ���� Ž���ϰ� �ִ� ���̰� �� ���ʿ� �ִٸ�
//				if (e.front().first.second > f.at(i).second) {
//					e.pop_back(); //���� ���� �����ϰ�
//					//���� ���̸� �����ϴ� ���Ϳ� ���� Ž���ϰ� �ִ� ������ ��ġ�� ���̱����� �Ÿ� ����
//					e.push_back(make_pair(make_pair(f.at(i).first, f.at(i).second), visit[f.at(i).first][f.at(i).second]));
//				}
//			}
//			//���� ���̺��� ���� Ž���ϰ� �ִ� ���̰� �� ���� �ִٸ�
//			else if(e.front().first.first > f.at(i).first){
//				e.pop_back(); //���� ���� �����ϰ�
//				//���� ���̸� �����ϴ� ���Ϳ� ���� Ž���ϰ� �ִ� ������ ��ġ�� ���̱����� �Ÿ� ����
//				e.push_back(make_pair(make_pair(f.at(i).first, f.at(i).second), visit[f.at(i).first][f.at(i).second]));
//			}
//		}
//		//���� Ž���ϰ� �ִ� ���̱��� �� �� �ְ� ���� ���̱����� �Ÿ����� ���� Ž���ϰ� �ִ� ���̱����� �Ÿ��� �� �۴ٸ�
//		else if(visit[f.at(i).first][f.at(i).second] != -1 && e.front().second > visit[f.at(i).first][f.at(i).second])
//		{
//			e.pop_back(); //���� ���� �����ϰ�
//			//���� ���̸� �����ϴ� ���Ϳ� ���� Ž���ϰ� �ִ� ������ ��ġ�� ���̱����� �Ÿ� ����
//			e.push_back(make_pair(make_pair(f.at(i).first, f.at(i).second), visit[f.at(i).first][f.at(i).second]));
//		}
//		
//	}
//	//���� ������ ���� �״�� �ִ��̶�� ���� ���̰� ������ ���� ���ٴ� �ǹ��̹Ƿ� ����
//	if (e.front().first.first == INT_MAX) {
//		flag = true;
//		return;
//	}
//	//�ʿ� ���� ���̰� �ִ� ��ġ�� ���� 0���� �ٲ���
//	map[e.front().first.first][e.front().first.second] = 0;
//	eat++; //�Ʊ�� ���� ������ �� ����
//	//���� ������ ���� �Ʊ����� ũ�Ⱑ ���ٸ�
//	if (eat == w) {
//		w++; //�Ʊ����� ũ�� 1 ����
//		eat = 0; //���� ������ �� 0���� �ʱ�ȭ
//	}
//	//�Ʊ����� ��ġ�� ���� ������ ��ġ�� �ٲ���
//	v.front().first = e.front().first.first;
//	v.front().second = e.front().first.second;
//	answer = answer + e.front().second; //���̱��� �����϶� �� �ð��� ������
//}
//
//bool check() {
//	//���̰� ������ ���� ��� false ��ȯ
//	if (flag) {
//		return false;
//	}
//	cnt = 0;
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < N; j++) {
//			//���̰� ������ ���� ���� ����
//			if (map[i][j] != 0 && map[i][j] < w) {
//				f.push_back(make_pair(i, j));
//				cnt++;
//			}
//		}
//	}
//	//���� ������ 0�̸� false ��ȯ
//	if (cnt == 0) {
//		return false;
//	}
//	//���� ������ 0�� �ƴϸ� true ��ȯ
//	else {
//		return true;
//	}
//}
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
//
//	cin >> N;
//
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < N; j++) {
//			cin >> map[i][j];
//			//�Ʊ� �����
//			if (map[i][j] == 9) {
//				v.push_back(make_pair(i, j)); //�Ʊ� ��� ��ġ ����
//				map[i][j] = 0; //�ʱ� �Ʊ��� ��ġ�� 0���� �ʱ�ȭ
//			}
//		}
//	}
//
//	//���� ���̰� ������ ����
//	while (check()) {
//		init(); //visit �迭 �ʱ�ȭ
//		bfs();
//		solve();
//		f.clear(); //���̸� ������ ���� �ʱ�ȭ
//		e.clear(); //���� ���̸� ������ ���� �ʱ�ȭ
//	}
//	
//	cout << answer << "\n";
//
//	return 0;
//}