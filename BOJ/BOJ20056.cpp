//#include<iostream>
//#include<vector>
//
//using namespace std;
//
//struct fireball
//{
//	int r;
//	int c;
//	int m;
//	int s;
//	int d;
//};
//
//int N, M, K, answer = 0;
//int dc[8] = {-1,-1,0,1,1,1,0,-1};
//int dr[8] = {0,1,1,1,0,-1,-1,-1};
//int dir1[4] = { 0,2,4,6 };
//int dir2[4] = { 1,3,5,7 };
//
//vector <fireball> v; //���̾�� ������ ���� ����
//vector <fireball> temp; //���� ���̾�� ������ ���� ���� ����
//vector <int> map[51][51];
//
//void init() {
//	//�� �ʱ�ȭ
//	for (int i = 1; i <= N; i++) {
//		for (int j = 1; j <= N; j++) {
//			map[i][j].clear();
//		}
//	}
//}
//
//bool dir(int c, int r) {
//	int count = 0;
//	for (int i = 0; i < map[c][r].size(); i++) {
//		//���� �ʿ� �ִ� ���̾���� ������ ¦���̸� count ����
//		if (temp[map[c][r][i]].d % 2 == 0) {
//			count++;
//		}
//	}
//	//count�� 0�̸� ��� Ȧ���̰� count�� ���̾�� ������ ������ ��� ¦����� ���̹Ƿ� true ��ȯ
//	if (count == 0 || count == map[c][r].size()) {
//		return true;
//	}
//	//�ƴϸ� false ��ȯ
//	else {
//		return false;
//	}
//}
//
//int speed(int c, int r) {
//	int s = 0;
//	//���� �ʿ� �ִ� ���̾���� �ӵ��� ��� ���ϱ�
//	for (int i = 0; i < map[c][r].size(); i++) {
//		s = s + temp[map[c][r][i]].s;
//	}
//
//	return (s / map[c][r].size()); //����� �ӵ��� ���� �ʿ� �ִ� ���̾�� ���� ���� ���� ��ȯ
//}
//
//int weight(int c, int r) {
//	int w = 0;
//	//���� �ʿ� �ִ� ���̾���� ������ ��� ���ϱ�
//	for (int i = 0; i < map[c][r].size(); i++) {
//		w = w + temp[map[c][r][i]].m;
//	}
//
//	return (w / 5); //����� ������ 5�� ���� ���� ��ȯ
//} 
//
//void solve() {
//	fireball f; //���̾�� ������ ���� ����ü ����
//	for (int i = 1; i <= N; i++) {
//		for (int j = 1; j <= N; j++) {
//			//�ش� �ʿ� ���̾�� �ϳ��� ������ 
//			if (map[i][j].size() == 1) {
//				f.r = i; //���� �� ����
//				f.c = j; //���� �� ����
//				f.m = temp[map[i][j][0]].m; //���� ���̾�� ���� ���� ����
//				f.s = temp[map[i][j][0]].s; //���� ���̾�� ���� �ӵ� ����
//				f.d = temp[map[i][j][0]].d; //���� ���̾�� ���� ���� ����
//				v.push_back(f); //���Ϳ� ����
//			}
//			//�ش� �ʿ� ���̾�� �ΰ� �̻��̸� 
//			else if (map[i][j].size() >= 2) {
//				f.r = i; //���� �� ����
//				f.c = j; //���� �� ����
//				f.m = weight(i,j); //���� ������ ����(2-3-1�ܰ�)
//				f.s = speed(i,j); //�ӷ� ���� �� ����(2-3-2�ܰ�)
//				//(2-3-3�ܰ�)
//				if (dir(i, j)) {  //���� ���̾���� ������ ��� Ȧ���̰ų� ¦���̸�
//					for (int k = 0; k < 4; k++) {
//						f.d = dir1[k]; //0,2,4,6 ������� ���� ����
//						//������ 0�̸� ����
//						if (f.m == 0) {
//							break;
//						}
//						//������ 0�� �ƴϸ� ���Ϳ� ���̾ ����
//						else {
//							v.push_back(f);
//						}
//					}
//				}
//				else { //�ƴ� ���
//					for (int k = 0; k < 4; k++) {
//						f.d = dir2[k]; //1,3,5,6 ������� ���� ����
//						//������ 0�̸� ����
//						if (f.m == 0) {
//							break;
//						}
//						//������ 0�� �ƴϸ� ���Ϳ� ���̾ ����
//						else {
//							v.push_back(f);
//						}
//					}
//				}
//			}
//		}
//	}
//}
//
//void move() {
//	for (int i = 0; i < v.size(); i++) {
//		//�ӷ� ��ŭ ����
//		for (int j = 0; j < v[i].s; j++) {
//			//�� �������� ��� �� ��ĭ�� �̵�
//			v[i].r = v[i].r + dc[v[i].d];
//			v[i].c = v[i].c + dr[v[i].d];
//			//�̵��� ��ġ�� ���� ����� ��� �̾��������� �̵�
//			if (v[i].r == N+1) {
//				v[i].r = 1;
//			}
//			else if (v[i].r == 0) {
//				v[i].r = N;
//			}
//			if (v[i].c == N+1) {
//				v[i].c = 1;
//			}
//			else if (v[i].c == 0) {
//				v[i].c = N;
//			}
//		}
//		//�̵��� �� �ش� ��ġ�� ���� ���̾�� �ε����� ����
//		map[v[i].r][v[i].c].push_back(i);
//	}
//	v.clear(); //���̾ ���� ����
//}
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
//
//	cin >> N >> M >> K;
//	
//	for (int i = 0; i < M; i++) {
//		fireball f;
//		cin >> f.r >> f.c >> f.m >> f.s >> f.d;
//		v.push_back(f);
//		temp.push_back(f);
//	}
//	//����
//	for (int i = 0; i < K; i++) {
//		move(); //1�ܰ�
//		solve(); //2�ܰ�
//		temp.clear(); //���� ���̾�� ������ �ʿ� ������ temp ���� clear
//		init(); //�� �ʱ�ȭ
//		temp.assign(v.begin(), v.end()); //temp ���Ϳ� ���ο� ���̾���� ��� v ���͸� ����
//	}
//
//	//���� �����ִ� ���̾���� ������ ��� ���ϱ�
//	for (int i = 0; i < v.size(); i++) {
//		answer = answer + v[i].m;
//	}
//
//	cout << answer << "\n";
//	
//	return 0;
//}