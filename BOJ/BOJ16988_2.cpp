//#include <cstdio>
//#include<map>
//#include<vector>
//#include<algorithm>
//
//using namespace std;
//
//int N, M, die, answer;
//int board[1000][1000];
//bool visit[1000][1000];
//vector <pair <int, int> > emp; //��ĭ�� ��� �� ������ ������ ���� 
//map <pair <int, int>, int> m1; //���� �ϳ��� ���Ƶ� ���� ���� ���� �� �ִ� ��츦 ������ map(key: ���� ���� ��ġ, value : �״� ���� ����)
//map <pair <pair <int, int >, pair <int, int> >, int > m2; //���� 2�� ���Ƽ� ���� ���� ���� �� �ִ� ��츦 ������ map(key: ���� ���� ��ġ 2��, value : �״� ���� ����)
//
//void init() {
//	for (int i = 0; i < emp.size(); i++) {
//		visit[emp.at(i).first][emp.at(i).second] = false;
//	}
//}
//
//void cal() {
//	//m2�� ������ ������� Ž��(m2�� ( key : ((c, r), (c, r)), vlaue : ���� ����) ) �������� �̷���� �ֱ� ������ temp���� ���� �� ���Ŀ� �°� �������
//	for (auto & temp : m2) {
//		pair <int, int> p1 = temp.first.first;  //key�� ù��° ��� ���� ����
//		pair <int, int> p2 = temp.first.second; //key�� �ι�° ��� ���� ����
//		//�� �ΰ��� ������ �� �״� ���� -> ���� 2�� ������ �� �״� ���� ���� + �� �� �ϳ��� ������ �� �״� ���� ���� + �� �� �ٸ� �ϳ��� ������ �� �״� ���� ����
//		answer = max(answer, temp.second + m1[p1] + m1[p2]); 
//	}
//	//m1�� ũ�Ⱑ 1�̻��̸�(���� �ϳ��� �ٸ� ���� ������ ���� �� ���� ���� ���� �ֱ� ������ ���������)
//	if (m1.size() >= 1) {
//		vector <int> v;
//		//m1�� ������ ������� Ž��(m1�� ( key : (c, r), vlaue : ���� ����) ) �������� �̷���� �ֱ� ������ temp���� ���� �� ���Ŀ� �°� �������
//		for (auto& temp : m1) {
//			v.push_back(temp.second); //���Ϳ� ������ ���� ������ �־���
//		}
//		//������ ũ�Ⱑ 1�̸�
//		if (v.size() == 1) {
//			//�� ���� �ٷ� ��
//			answer = max(answer, v.at(0));
//		}
//		//������ ũ�Ⱑ 2 �̻��̸�
//		else {
//			sort(v.rbegin(), v.rend()); //�������� ����(������ ���� ���� ������ ��츸 ���� �ǹǷ� �����ؼ� ù��°�� �ι�° ���� ���ؼ� ���ϸ� ��)
//			answer = max(answer, v.at(0) + v.at(1));
//		}
//	}
//}
//
//void dfs(int c, int r) {
//	int dc[4] = { -1,0,1,0 };
//	int dr[4] = { 0,1,0,-1 };
//	//4�� Ž��
//	for (int i = 0; i < 4; i++) {
//		int nc = c + dc[i];
//		int nr = r + dr[i];
//		//Ž���� ��ġ�� �ʾȿ� �ְ� ���� ���� �ƴϰ� �湮���� �ʾҴٸ�
//		if (nc >= 0 && nc < N && nr >= 0 && nr < M && board[nc][nr] != 1 && visit[nc][nr] == false) {
//			//���� ��ĭ�̶��
//			if (board[nc][nr] == 0) {
//				visit[nc][nr] = true; //�湮 ǥ��
//				emp.push_back(make_pair(nc, nr)); //��ĭ�� ���� ����
//			}
//			//���� ���� ���̶��
//			else if (board[nc][nr] == 2) {
//				visit[nc][nr] = true; //�湮 ǥ��
//				die++; //�״� ���� ���� ����
//				dfs(nc, nr);
//			}
//		}
//	}
//}
//
//void solve() {
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < M; j++) {
//			//���浹�� �߰��߰� �湮���� �ʾҴٸ�
//			if (board[i][j] == 2 && visit[i][j] == false) {
//				emp.clear(); //��ĭ ���� ���� ���� �ʱ�ȭ
//				die = 1; //�״� ���� ���� 1�� �ʱ�ȭ
//				visit[i][j] = true; //���� ��ġ �湮 ǥ��
//				dfs(i,j);
//				//��ĭ�� ������ 1���̸�(���� �ϳ��� ���Ƶ� �״´ٴ� �ǹ�) 
//				if (emp.size() == 1) {
//					m1[emp.at(0)] += die; //���� �ϳ��� ���Ƶ� ���� ���� ���� �� �ִ� ����̹Ƿ� m1�� ����(key: ��ĭ�� ��ġ value : �״� ���� ����)
//				}
//				//��ĭ�� ������ 2���̸�(���� 2�� ���ƾ� �״´ٴ� �ǹ�) 
//				else if (emp.size() == 2) {
//					//������ ���Ͻ�Ű�� ���� ó��
//					if (emp.at(0) > emp.at(1)) {
//						swap(emp.at(0), emp.at(1));
//					}
//					m2[{emp.at(0), emp.at(1)}] += die; //���� 2�� ���Ƽ� ���� ���� ���� �� �ִ� ����̹Ƿ� m2�� ����(key: ((��ĭ�� ��ġ), (��ĭ�� ��ġ)) value : �״� ���� ����)
//				}
//				init(); //visit �ʱ�ȭ(��ĭ�� �湮�ߴٴ� ǥ�ø� �ʱ�ȭ)
//			}
//		}
//	}
//
//	cal();
//}
//int main() {
//	scanf("%d%d", &N, &M);
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < M; j++) {
//			scanf("%d", &board[i][j]);
//		}
//	}
//	solve();
//
//	printf("%d", answer);
//	return 0;
//}