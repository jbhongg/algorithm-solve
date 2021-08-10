//#include<iostream>
//#include<queue>
//#include<limits.h>
//
//using namespace std;
//
//int N, M;
//char map[50][50];
//int dc[4] = {-1,0,1,0};
//int dr[4] = {0,1,0,-1};
//priority_queue<pair<pair<int, int>, pair<int, int>>, vector<pair<pair<int, int>, pair<int, int>>>, greater<pair<pair<int, int>, pair<int, int>>> > pq;
//pair <int, int> p[50][50];
//
//void solve() {
//	while (!pq.empty()) {
//		int g = pq.top().first.first;
//		int x = pq.top().first.second;
//		int c = pq.top().second.first;
//		int r = pq.top().second.second;
//		pq.pop();
//		//4�� Ž��
//		for (int i = 0; i < 4; i++) {
//			int nc = c + dc[i];
//			int nr = r + dr[i];
//			//Ž�� ��ġ�� �ʾȿ� ������
//			if (nc >= 0 && nr >= 0 && nc < N && nr < M) {
//				//Ž�� ��ġ�� ��������
//				if (map[nc][nr] == 'g') {
//					//Ž����ġ�� �����Ⱚ���� ���� ��ġ�� ���� �� ������ ���� ������ 
//					if (p[nc][nr].first > g + 1) {
//						p[nc][nr].first = g + 1; //Ž����ġ�� �����Ⱚ��  ���� ��ġ�� ���� �� ������ ������ �ٲ㼭 ����
//						p[nc][nr].second = x; //Ž����ġ�� ������ �ֺ� ���� ���� ��ġ�� ���� �� ������ �ֺ� ������ �ٲ㼭 ����
//						pq.push(make_pair(make_pair(g+1, x), make_pair(nc, nr))); //ť�� ����
//					}
//					//Ž����ġ�� �����Ⱚ�� ���� ��ġ�� ���� �� ������ ���� ������
//					else if (p[nc][nr].first == g + 1) {
//						//Ž����ġ�� ������ �ֺ������� ���� ��ġ�� ���� �� ������ �ֺ����� ������
//						if (p[nc][nr].second > x) {
//							p[nc][nr].first = g + 1; //Ž����ġ�� �����Ⱚ��  ���� ��ġ�� ���� �� ������ ������ �ٲ㼭 ����
//							p[nc][nr].second = x; //Ž����ġ�� ������ �ֺ� ���� ���� ��ġ�� ���� �� ������ �ֺ� ������ �ٲ㼭 ����
//							pq.push(make_pair(make_pair(g + 1, x), make_pair(nc, nr))); //ť�� ����
//						}
//					}
//				}
//				//Ž�� ��ġ�� ������ �ֺ��̶��
//				else if (map[nc][nr] == 'X') {
//					//Ž����ġ�� �����Ⱚ���� ���� ��ġ�� ���� �� ������ ���� ������ 
//					if (p[nc][nr].first > g) {
//						p[nc][nr].first = g; //Ž����ġ�� �����Ⱚ��  ���� ��ġ�� ���� �� ������ ������ �ٲ㼭 ����
//						p[nc][nr].second = x+1; //Ž����ġ�� ������ �ֺ� ���� ���� ��ġ�� ���� �� ������ �ֺ� ������ �ٲ㼭 ����
//						pq.push(make_pair(make_pair(g, x+1), make_pair(nc, nr))); //ť�� ����
//					}
//					//Ž����ġ�� �����Ⱚ�� ���� ��ġ�� ���� �� ������ ���� ������
//					else if (p[nc][nr].first == g) {
//						//Ž����ġ�� ������ �ֺ������� ���� ��ġ�� ���� �� ������ �ֺ����� ������
//						if (p[nc][nr].second > x+1) {
//							p[nc][nr].first = g; //Ž����ġ�� �����Ⱚ��  ���� ��ġ�� ���� �� ������ ������ �ٲ㼭 ����
//							p[nc][nr].second = x+1; //Ž����ġ�� ������ �ֺ� ���� ���� ��ġ�� ���� �� ������ �ֺ� ������ �ٲ㼭 ����
//							pq.push(make_pair(make_pair(g, x+1), make_pair(nc, nr))); //ť�� ����
//						}
//					}
//				}
//				//Ž�� ��ġ�� �����⵵ �ƴϰ� ������ �ֺ��� �ƴ϶��
//				else{
//					//Ž����ġ�� �����Ⱚ���� ���� ��ġ�� ���� �� ������ ���� ������ 
//					if (p[nc][nr].first > g) {
//						p[nc][nr].first = g; //Ž����ġ�� �����Ⱚ��  ���� ��ġ�� ���� �� ������ ������ �ٲ㼭 ����
//						p[nc][nr].second = x; //Ž����ġ�� ������ �ֺ� ���� ���� ��ġ�� ���� �� ������ �ֺ� ������ �ٲ㼭 ����
//						pq.push(make_pair(make_pair(g, x), make_pair(nc, nr))); //ť�� ����
//					}
//					//Ž����ġ�� �����Ⱚ�� ���� ��ġ�� ���� �� ������ ���� ������
//					else if (p[nc][nr].first == g) {
//						//Ž����ġ�� ������ �ֺ������� ���� ��ġ�� ���� �� ������ �ֺ����� ������
//						if (p[nc][nr].second > x) {
//							p[nc][nr].first = g; //Ž����ġ�� �����Ⱚ��  ���� ��ġ�� ���� �� ������ ������ �ٲ㼭 ����
//							p[nc][nr].second = x; //Ž����ġ�� ������ �ֺ� ���� ���� ��ġ�� ���� �� ������ �ֺ� ������ �ٲ㼭 ����
//							pq.push(make_pair(make_pair(g, x), make_pair(nc, nr))); // ť�� ����
//						}
//					}
//				}
//			}
//		}
//
//	}
//}
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
//	
//	cin >> N >> M;
//	int e1 = 0, e2 = 0;
//
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < M; j++) {
//			cin >> map[i][j];
//		}
//	}
//
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < M; j++) {
//			//���� ���� �������̸�
//			if (map[i][j] == 'g') {
//				//4�� Ž��
//				for (int k = 0; k < 4; k++) {
//					//Ž���� ��ġ�� �ʾȿ� �ְ� ��ĭ�̶��
//					if (i + dc[k] >= 0 && i + dc[k] < N && j + dr[k] >= 0 && j + dr[k] < M && map[i + dc[k]][j + dr[k]] == '.') {
//						map[i + dc[k]][j + dr[k]] = 'X'; //Xǥ��(������ ���� ǥ��)
//					}
//				}
//			}
//			//���� ��ġ���
//			else if (map[i][j] == 'S') {
//				pq.push(make_pair(make_pair(0, 0), make_pair(i, j))); //ť�� ����
//				//����ģ �������� ������ ����ģ ������ �ֺ��� ������ 0���� ����
//				p[i][j].first = 0; 
//				p[i][j].second = 0;
//			}
//			//���� ���� ����
//			else if (map[i][j] == 'F') {
//				e1 = i;
//				e2 = j;
//			}
//			//������ġ�� �ƴϸ�
//			if (map[i][j] != 'S') {
//				//����ģ �������� ������ ����ģ ������ �ֺ��� ������ �ִ����� ����
//				p[i][j].first = INT_MAX;
//				p[i][j].second = INT_MAX;
//			}
//		}
//	}
//
//	solve();
//
//	cout << p[e1][e2].first << " " << p[e1][e2].second << "\n";
//	
//	return 0;
//}