//#include<iostream>
//
//using namespace std;
//
//int map[499][499];
//int N, c, r, answer;
//��Ѹ� ��ġ�� Ž���ϱ� ���� �迭 �� �迭�� �������� ������ ��ġ
//int dc[4][10] = { {-2,-1,-1,-1,0,1,1,1,2,0}, {-1,-1,0,0,0,0,1,1,2,1}, {-2,-1,-1,-1,0,1,1,1,2,0}, {-2,-1,-1,0,0,0,0,1,1,-1} };
//int dr[4][10] = { {0,-1,0,1,-2,-1,0,1,0,-1}, {-1,1,-2,-1,1,2,-1,1,0,0}, {0,-1,0,1,2,-1,0,1,0,1}, {0,-1,1,-2,-1,1,2,-1,1,0} };
////��Ѹ� ��ġ�� ���� ����
//float rate[4][9] = { {0.02, 0.1, 0.07, 0.01, 0.05, 0.1, 0.07, 0.01, 0.02}, {0.01, 0.01, 0.02, 0.07, 0.07, 0.02, 0.1, 0.1, 0.05}, {0.02, 0.01, 0.07, 0.1, 0.05, 0.01, 0.07, 0.1, 0.02}, {0.05, 0.1, 0.1, 0.02, 0.07, 0.07, 0.02, 0.01, 0.01} };
//
//void sand(int dir) {
//	int sand = map[c][r]; //���� ĭ�� ���� ��ü���� ����
//	int temp = sand;      //���� �𷡷��� �����ϱ� ���� ����
//
//	switch (dir) {
//	//���� ������ ���
//	case 0: {
//		//��Ѹ� ��ġ Ž��
//		for (int i = 0; i < 10; i++) {
//			int nc = c + dc[0][i];
//			int nr = r + dr[0][i];
//			//Ž���� ��ġ�� ���� ��ġ��
//			if (i == 9) {
//				//Ž���� ��ġ�� �ʾȿ� ������
//				if (nc >= 0 && nc < N && nr >= 0 && nr < N) {
//					map[nc][nr] = map[nc][nr] + temp; //���� ���� �𷡾��� Ž�� ��ġ�� ������
//					map[c][r] = 0; //���� ��ġ�� 0���� �ٲ��ְ� ����
//					break;
//				}
//				//Ž���� ��ġ�� �� �ٱ��� ������
//				else {
//					answer = answer + temp; //���� ���� �𷡾��� ���� ������ ���� �� ���� ������ ������ ������
//					map[c][r] = 0; //���� ��ġ�� 0���� �ٲ��ְ� ����
//					break;
//				}
//			}
//			//Ž���� ��ġ�� �ʾȿ� ������
//			if (nc >= 0 && nc < N && nr >= 0 && nr < N) {
//				temp = temp - (int)(sand * rate[0][i]); //�ش� ��ġ�� ������ŭ �𷡸� ����ؼ� ���� �𷡷����� ����
//				map[nc][nr] = map[nc][nr] + (int)(sand * rate[0][i]); //Ž���� ��ġ�� ������ŭ �𷡸� ����ؼ� ������
//			}
//			//Ž���� ��ġ�� �� �ٱ��� ������
//			else {
//				temp = temp - (int)(sand * rate[0][i]);       //�ش� ��ġ�� ������ŭ �𷡸� ����ؼ� ���� �𷡷����� ����
//				answer = answer + (int)(sand * rate[0][i]);   //�ش� ��ġ�� ������ŭ �𷡸� ����ؼ� ���� ������ ���� �� ���� ������ ������ ������
//			}
//		}
//		break;
//	}
//	//�Ʒ��� ������ ���
//	case 1: {
//		for (int i = 0; i < 10; i++) {
//			int nc = c + dc[1][i];
//			int nr = r + dr[1][i];
//			if (i == 9) {
//				if (nc >= 0 && nc < N && nr >= 0 && nr < N) {
//					map[nc][nr] = map[nc][nr] + temp;
//					map[c][r] = 0;
//					break;
//				}
//				else {
//					answer = answer + temp;
//					map[c][r] = 0;
//					break;
//				}
//			}
//			if (nc >= 0 && nc < N && nr >= 0 && nr < N) {
//				temp = temp - (int)(sand * rate[1][i]);
//				map[nc][nr] = map[nc][nr] + (int)(sand * rate[1][i]);
//			}
//			else {
//				temp = temp - (int)(sand * rate[1][i]);
//				answer = answer + (int)(sand * rate[1][i]);
//			}
//		}
//		break;
//	}
//	//������ ������ ���
//	case 2: {
//		for (int i = 0; i < 10; i++) {
//			int nc = c + dc[2][i];
//			int nr = r + dr[2][i];
//			if (i == 9) {
//				if (nc >= 0 && nc < N && nr >= 0 && nr < N) {
//					map[nc][nr] = map[nc][nr] + temp;
//					map[c][r] = 0;
//					break;
//				}
//				else {
//					answer = answer + temp;
//					map[c][r] = 0;
//					break;
//				}
//			}
//			if (nc >= 0 && nc < N && nr >= 0 && nr < N) {
//				temp = temp - (int)(sand * rate[2][i]);
//				map[nc][nr] = map[nc][nr] + (int)(sand * rate[2][i]);
//			}
//			else {
//				temp = temp - (int)(sand * rate[2][i]);
//				answer = answer + (int)(sand * rate[2][i]);
//			}
//		}
//		break;
//	}
//	//���� ������ ���
//	case 3: {
//		for (int i = 0; i < 10; i++) {
//			int nc = c + dc[3][i];
//			int nr = r + dr[3][i];
//			if (i == 9) {
//				if (nc >= 0 && nc < N && nr >= 0 && nr < N) {
//					map[nc][nr] = map[nc][nr] + temp;
//					map[c][r] = 0;
//					break;
//				}
//				else {
//					answer = answer + temp;
//					map[c][r] = 0;
//					break;
//				}
//			}
//			if (nc >= 0 && nc < N && nr >= 0 && nr < N) {
//				temp = temp - (int)(sand * rate[3][i]);
//				map[nc][nr] = map[nc][nr] + (int)(sand * rate[3][i]);
//			}
//			else {
//				temp = temp - (int)(sand * rate[3][i]);
//				answer = answer + (int)(sand * rate[3][i]);
//			}
//		}
//		break;
//	}
//	}
//
//}
//
//void move(int dir, int num) {
//	//���� �����̸�
//	if (dir == 0) {
//		for (int i = 0; i < num; i++) {
//			r = r - 1; //�� �̵�
//			//���� 0�ε� ���� -1�̸� ���� 0���� �ʱ�ȭ �ϰ� ����
//			if (c == 0 && r == -1) {
//				r = 0;
//				return;
//			}
//			else {
//				//�̵��� ��ġ�� ��ĭ�̾ƴϸ�
//				if (map[c][r] != 0) {
//					sand(dir);
//				}
//			}
//		}
//	}
//	//�Ʒ��� �����̸�
//	else if (dir == 1) {
//		for (int i = 0; i < num; i++) {
//			c = c + 1; //�� �̵�
//			//�̵��� ��ġ�� ��ĭ�̾ƴϸ�
//			if (map[c][r] != 0) {
//				sand(dir);
//			}
//		}
//	}
//	//������ �����̸�
//	else if (dir == 2) {
//		for (int i = 0; i < num; i++) {
//			r = r + 1; //�� �̵�
//			//�̵��� ��ġ�� ��ĭ�̾ƴϸ�
//			if (map[c][r] != 0) {
//				sand(dir);
//			}
//		}
//	}
//	//���� �����̸�
//	else if (dir == 3) {
//		for (int i = 0; i < num; i++) {
//			c = c - 1; //�� �̵�
//			//�̵��� ��ġ�� ��ĭ�̾ƴϸ�
//			if (map[c][r] != 0) {
//				sand(dir);
//			}
//		}
//	}
//
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
//		}
//	}
//	//����̵��� ���� ��ġ(�����)
//	c = N / 2;
//	r = N / 2;
//	//����(������ ����)
//	int dir = 0;
//
//	int num1 = 1; //���ʰ� �Ʒ��� ������ �����ؾ��� Ƚ���� ��Ÿ�� ����
//	int num2 = 2; //�����ʰ� ���� ������ �����ؾ��� Ƚ���� ��Ÿ�� ����
//	
//	while (true) {
//		//����̵��� 0,0�� �����ϸ� ����
//		if (c == 0 && r == 0) {
//			break;
//		}
//		//���� �����̸�
//		if (dir == 0) {
//			move(dir, num1);
//			dir = 1; //���������� �Ʒ���
//		}
//		//�Ʒ��� �����̸�
//		else if (dir == 1) {
//			move(dir, num1);
//			dir = 2; //���������� ������
//			num1 = num1 + 2; //������ ���ʰ� �Ʒ��� ������ �����ؾ��� Ƚ�� ���
//		}
//		//������ �����̸�
//		else if (dir == 2) {
//			move(dir, num2);
//			dir = 3; //���������� ����
//		}
//		//���� �����̸�
//		else if (dir == 3) {
//			move(dir, num2);
//			dir = 0; //���������� ����
//			num2 = num2 + 2; //������ �����ʰ� ���� ������ �����ؾ��� Ƚ�� ���
//		}
//	}
//	cout << answer << "\n";
//
//	return 0;
//}