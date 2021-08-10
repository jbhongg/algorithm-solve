//#include <iostream>
//#include <vector>
//#include<limits.h>
//
//using namespace std;
//
//int map[12][12];
//vector <pair <pair <int, int>, int> > core;
//int dc[4] = { -1,0,1,0 };
//int dr[4] = { 0,1,0,-1 };
//int N, wn;
//vector <int> sel;
//vector <pair <int, int>> answer;
//
//int core_count() {
//	int count = 0;
//	for (int i = 0; i < core.size(); i++) {
//		if (core.at(i).second == 1) {
//			count++;
//		}
//	}
//
//	return count;
//}
//
//int wire(int c, int r, int dir) {
//	int count = 1;
//	int nc = c;
//	int nr = r;
//	while (true) {
//		nc = nc + dc[dir];
//		nr = nr + dr[dir];
//		//�ʾȿ� ������
//		if (nc >= 0 && nc < N && nr >= 0 && nr < N) {
//			//��ĭ�̶��
//			if (map[nc][nr] == 0) {
//				count++; //���� �ϳ� ����
//			}
//			//��ĭ�� �ƴ϶��
//			else {
//				count = 0; //���������� 0�����ϰ� Ż��
//				break;
//			}
//		}
//		//�ʹ����� ������ Ż��
//		else {
//			break;
//		}
//	}
//
//	return count;
//}
//
//void solve(int k, int n) {
//	//�ִ��� ����� �ھ� ���� �ھ� ��ü���� ���� ���� ������ ���� �ּҶ�� ����� ������ ������ ũ�� ������ ����
//	if (answer.front().first == core.size() && n >= answer.front().second) {
//		return;
//	}
//	//�ھ ��� ������
//	if (k == core.size()) {
//		int core_n = core_count(); //������ ����� �ھ� ���� ����
//		//�ִ��� ����� �ھ� ���� ���� ������ ����� �ھ� ���� ���ٸ�
//		if (answer.front().first == core_n) {
//			//�ּҶ�� ����� ������ ������ ���� ������ ���� ������
//			if (answer.front().second > n) {
//				answer.front().second = n; //���� ������ �� ����
//			}
//		}
//		//�ִ��� ����� �ھ� ������ ���� ������ ����� �ھ� ���� ũ�ٸ�
//		else if (answer.front().first < core_n) {
//			answer.front().first = core_n; //���� �ھ��� �� ����
//			answer.front().second = n; //���� ������ �� ����
//		}
//		return;
//	}
//	int c = core.at(k).first.first;
//	int r = core.at(k).first.second;
//	//4�� Ž��
//	for (int j = 0; j < 4; j++) {
//		int nc = c + dc[j];
//		int nr = r + dr[j];
//		//�ʾȿ� �ְ� Ž���� ĭ�� ��ĭ�̸�
//		if (nc >= 0 && nc < N && nr >= 0 && nr < N && map[nc][nr] == 0) {
//			int temp = wire(nc, nr, j); //������ ��� �ִ��� Ȯ��
//			//������ ��� ������
//			if (temp != 0) {
//				core.at(k).second = 1; //���� �ھ ������ ����Ǿ��ٰ� ǥ��
//				int tc = nc;
//				int tr = nr;
//				map[tc][tr] = 2; 
//				//�ʿ� ������ ��
//				for (int q = 0; q < temp - 1; q++) {
//					tc = tc + dc[j];
//					tr = tr + dr[j];
//					map[tc][tr] = 2;
//				}
//				solve(k + 1, n + temp); 
//				core.at(k).second = 0; //�ھ� ���� ��������
//				tc = nc;
//				tr = nr;
//				map[tc][tr] = 0;
//				//���� ȸ��
//				for (int q = 0; q < temp - 1; q++) {
//					tc = tc + dc[j];
//					tr = tr + dr[j];
//					map[tc][tr] = 0;
//				}
//			}
//			//������ ��� ������
//			else if (temp == 0 && j == 3) {
//				solve(k + 1, n + temp);
//			}
//		}
//	}
//	
//	
//}
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
//
//	int T;
//	cin >> T;
//	for (int test_case = 1; test_case <= T; test_case++)
//	{
//		cin >> N;
//		answer.clear();
//		core.clear();
//		answer.push_back(make_pair(-1, INT_MAX));
//		for (int i = 0; i < N; i++) {
//			for (int j = 0; j < N; j++) {
//				cin >> map[i][j];
//				//�� �����ڸ��� �ִ� �ھ �����ϰ� �ھ ���Ϳ� ��� ����
//				if (i != 0 && i != N - 1 && j != 0 && j != N - 1 && map[i][j] == 1) {
//					core.push_back(make_pair(make_pair(i, j), 0));
//				}
//			}
//		}
//		solve(0, 0);
//
//		//������ �ϳ��� ��� ���� �� 0���
//		if (answer.front().first == -1) {
//			answer.front().second = 0;
//		}
//
//		cout << "#" << test_case << " " << answer.front().second << "\n";
//	}
//	return 0;
//}