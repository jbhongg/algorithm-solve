//#include<iostream>
//
//using namespace std;
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
//
//	int N, M, answer = 0;
//
//	cin >> N >> M;
//
//	int** num = new int* [N]; // �迭 �����Ҵ�
//
//	for (int i = 0; i < N; i++) {
//		num[i] = new int[M];
//	}
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < M; j++) {
//			cin >> num[i][j];
//		}
//	}
//
//	answer = 2 * N * M; //����, �Ʒ��� ���� ���
//
//    //�������� �ѳ��� ���
//	for (int i = 0; i < N; i++) {
//		answer = answer + num[i][0] + num[i][M - 1]; //�糡 �ٱ��� ���
//		for (int j = 0; j < M - 1; j++) {
//			answer = answer + abs(num[i][j] - num[i][j + 1]); //���� �ѳ��� ���
//		}
//	}
//
//	//�������� �ѳ��� ���
//	for (int j = 0; j < M; j++) {
//		answer = answer + num[0][j] + num[N - 1][j]; //�糡 �ٱ��� ���
//		for (int i = 0; i < N - 1; i++) {
//			answer = answer + abs(num[i][j] - num[i + 1][j]); //���� �ѳ��� ���
//		}
//	}
//
//	cout << answer << '\n';
//
//	//�迭 �޸� ����
//	for (int i = 0; i < N; i++) {
//		delete[] num[i];
//	}
//	delete[] num;
//
//	return 0;
//}