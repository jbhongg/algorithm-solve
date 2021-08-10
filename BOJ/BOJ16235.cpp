//#include<iostream>
//#include<vector>
//#include<algorithm>
//
//using namespace std;
//
//int add_food[10][10]; //�ܿ￡ �߰��� ���
//int food[10][10]; //���� ���
//vector <int> map[10][10]; //������ ������ ��
//int N, M, K, answer;
//int dc[8] = {-1,-1,0,1,1,1,0,-1};
//int dr[8] = {0,1,1,1,0,-1,-1,-1};
//
//void cal() {
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < N; j++) {
//			answer = answer + map[i][j].size(); //ĭ�� ����� ������ ����
//		}
//	}
//}
//
//void winter() {
//	//�� ĭ�� �ش��ϴ� �߰� ����� �߰� 
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < N; j++) {
//			food[i][j] = food[i][j] + add_food[i][j];
//		}
//	}
//}
//
//void autumn() {
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < N; j++) {
//			//���� ĭ�� ������ �ִٸ�
//			if (map[i][j].size() != 0) {
//				//���� ���� ��ŭ ����
//				for (int k = 0; k < map[i][j].size(); k++) {
//					//���� ������ ���̰� 5�� ������
//					if (map[i][j].at(k) % 5 == 0) {
//						//8�� Ž��
//						for (int r = 0; r < 8; r++) {
//							int nc = i + dc[r];
//							int nr = j + dr[r];
//							//Ž���� ĭ�� �ʾȿ� �ִٸ�
//							if (nc >= 0 && nc < N && nr >= 0 && nr < N) {
//								map[nc][nr].push_back(1); //Ž���� ĭ�� ���� 1¥�� ������ �־���
//							}
//						}
//					}
//				}
//			}
//		}
//	}
//}
//
//void spring_and_summer() {
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < N; j++) {
//			//ĭ�� ������ �ϳ����
//			if (map[i][j].size() == 1) {
//				//ĭ�� ��к��� ������ ���̰� ũ��
//				if (food[i][j] < map[i][j].front()) {
//					//���� ����
//					food[i][j] = food[i][j] + (map[i][j].front() / 2); //ĭ�� ������� �ְ�
//					map[i][j].pop_back(); //���� ����
//				}
//				//ĭ�� ��к��� ������ ���̰� �۰ų� ������
//				else {
//					food[i][j] = food[i][j] - map[i][j].front(); //ĭ�� ����� ������ ���̸�ŭ ����
//					map[i][j].front() = map[i][j].front() + 1; //������ ���� �ѻ� ����
//				}
//			}
//			//ĭ�� ������ ���������
//			else if (map[i][j].size() > 1) {
//				sort(map[i][j].begin(), map[i][j].end()); //���̼����� �������� ����
//				for (int k = 0; k < map[i][j].size(); k++) {
//					//ĭ�� ��к��� ���� ������ ���̰� ũ��
//					if (food[i][j] < map[i][j].at(k)) {
//						//������ �������� ���� �������� ���� ���� �� Ż��
//						for (int q = map[i][j].size() - 1; q >= k; q--) {
//							food[i][j] = food[i][j] + (map[i][j].at(q) / 2); //ĭ�� ������� �ְ�
//							map[i][j].pop_back(); //���� ����
//						}
//						break;
//					}
//					//ĭ�� ��к��� ���� ������ ���̰� �۰ų� ������
//					else {
//						food[i][j] = food[i][j] - map[i][j].at(k); //ĭ�� ����� ���� ������ ���̸�ŭ ����
//						map[i][j].at(k) = map[i][j].at(k) + 1; //���� ������ ���� �ѻ� ����
//					}
//				}
//			}
//		}
//	}
//}
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
//
//	cin >> N >> M >> K;
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < N; j++) {
//			cin >> add_food[i][j]; //�ܿ￡ �߰��� ��� ����
//			food[i][j] = 5; //�ʱ� ����� 5
//		}
//	}
//
//	for (int i = 0; i < M; i++) {
//		int c, r, age;
//		cin >> c >> r >> age;
//		map[c-1][r-1].push_back(age); //���� ���̸� �ʿ� ����
//	}
//
//	int count = 0;
//
//	//K���� ������ ����
//	while (count != K) {
//		spring_and_summer(); //���� ����
//		autumn(); //����
//		winter(); //�ܿ�
//		count++; //�� ����
//	}
//
//	cal(); //���� ���� ���
//	
//	cout << answer << "\n";
//
//	return 0;
//}