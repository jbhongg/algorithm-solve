//#include<iostream>
//#include<limits.h>
//#include<algorithm>
//#include<vector>
//#include<math.h>
//#include<queue>
//
//using namespace std;
//
//int map[16][15], temp[16][15];
//int N, M, D, cnt, answer;
//vector <int> v; // �ü� ��ġ ���� ����
//vector <pair <pair<int,int>, int> > shot[3]; //ȭ�� ����(�߻��� ��, ��, �Ÿ�)
//queue <int> q;
//
//void init() {
//	//�� �ʱ�ȭ
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < M; j++) {
//			map[i][j] = temp[i][j];
//		}
//	}
//}
//
//void move() {
//	//�Ʒ������� �� Ž��
//	for (int j = 0; j < M; j++) {
//		for (int i = N - 1; i >= 0; i--) {
//			q.push(map[i][j]); //�� ���� ť�� ����
//		}
//		q.pop(); //ù��° ���� ����(�� �Ʒ��� ���� ��ĭ �����̸� ������Ƿ�)
//		q.push(0); // ť�� �������� 0�� �߰�
//		//���� �Ʒ������� ť�� �ִ� ���� �־���
//		for (int i = N - 1; i >= 0; i--) {
//			map[i][j] = q.front();
//			q.pop();
//		}
//	}
//}
//
//void attack() {
//	for (int i = 0; i < 3; i++) {
//		//ȭ���� ������ �ʱ�ȭ ���� �ƴϸ� ȭ���� �߻��� �� �ִٴ� ���̹Ƿ�
//		if (shot[i].front().first.first != INT_MAX) {
//			//ȭ���� �߻��� ��ġ�� ���� ������ ���� ���ְ� ���� ���� �� ����
//			if (map[shot[i].front().first.first][shot[i].front().first.second] == 1) {
//				map[shot[i].front().first.first][shot[i].front().first.second] = 0;
//				cnt++;
//			}
//		}
//	}
//}
//
//bool check() {
//	int count = 0;
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < M; j++) {
//			//�ʿ� ���� ������ count ����
//			if (map[i][j] != 0) {
//				count++;
//			}
//			//cout�� 1�̸� ����
//			if (count == 1) {
//				goto L;
//			}
//		}
//	}
//	//count�� 0�̸� ���� ���ٴ� ���̹Ƿ� true ��ȯ
//	L:if (count == 0) {
//		return true;
//	}
//	//���� ������ false ��ȯ
//	else {
//		return false;
//	}
//}
//
//void cal() {
//	cnt = 0;
//	//�ʿ� ���� ������
//	while (!check()) {
//		//ȭ�� ���� �ʱ�ȭ
//		for (int i = 0; i < 3; i++) {
//			shot[i].clear();
//		}
//		shot[0].push_back(make_pair(make_pair(INT_MAX, INT_MAX), INT_MAX));
//		shot[1].push_back(make_pair(make_pair(INT_MAX, INT_MAX), INT_MAX));
//		shot[2].push_back(make_pair(make_pair(INT_MAX, INT_MAX), INT_MAX));
//		//�Ʒ������� Ž��
//		for (int i = N - 1; i >= 0; i--) {
//			for (int j = 0; j < M; j++) {
//				//���� �߰��ϸ�
//				if (map[i][j] == 1) {
//					//ù��° �ü����� Ž�� ����
//					for (int k = 0; k < 3; k++) {
//						//�������� �Ÿ��� ���� ���� �Ÿ����� �۰ų� ������
//						if (((abs(N - i)) + (abs(v[k] - j))) <= D) {
//							//���� ����Ǿ� �ִ� �Ÿ��� �������� �Ÿ��� ������
//							if (shot[k].front().second == ((abs(N - i)) + (abs(v[k] - j)))) {
//								//���� ����Ǿ� �ִ� ��ġ���� Ž���� ���� ��ġ�� �� ���ʿ� ������
//								if (shot[k].front().first.second >= j) {
//									//���� ���� ��� �� ��ġ�� ����
//									shot[k].front().first.first = i;
//									shot[k].front().first.second = j;
//								}
//							}
//							//���� ����Ǿ� �ִ� �Ÿ����� �������� �Ÿ��� ������
//							else if(shot[k].front().second > ((abs(N - i)) + (abs(v[k] - j)))){
//								//���� ���� ��� �� ��ġ�� �����ϰ� �������� �Ÿ��� ����
//								shot[k].front().second = (abs(N - i)) + (abs(v[k] - j));
//								shot[k].front().first.first = i;
//								shot[k].front().first.second = j;
//							}
//						}
//
//					}
//
//					
//				}
//			}
//		}
//		attack(); //ȭ�� �߻�
//		move(); //���� ��ĭ�� �Ʒ��� �̵�
//	}
//	
//
//}
//
//void solve(int n, int idx) {
//	//�ü� ��ġ�� ������
//	if (n == 3) {
//		cal(); //ȭ���� �߻��� ��ġ ���
//		answer = max(answer, cnt);
//		init();//�� �ʱ�ȭ
//		return;
//	}
//
//	//����
//	for (int i = idx; i < M; i++) {
//		//����ĭ�� �ü��� ������
//		if (map[N][i] != 2) {
//			map[N][i] = 2; //�ü� ��ġ
//			v.push_back(i); //�ü��� ��ġ ���Ϳ� ����
//			solve(n + 1,i+1);
//			//���� ����
//			map[N][i] = 0;
//			v.pop_back();
//		}
//	}
//}
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
//
//	cin >> N >> M >> D;
//
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < M; j++) {
//			cin >> map[i][j];
//			temp[i][j] = map[i][j];
//		}
//	}
//
//	solve(0,0);
//
//	cout << answer << "\n";
//	
//	return 0;
//}