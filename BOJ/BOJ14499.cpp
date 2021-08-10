//#include<iostream>
//
//using namespace std;
//
//int N, M, x, y, k, command;
//bool skip;
//int map[20][20];
//int temp[6];
//int dice[6] = { 0,0,0,0,0,0 }; //��, ��, ����, �޿�, ��, �Ʒ�
//
//void check() {
//	//�̵��� ĭ�� ���� 0�̸�
//	if (map[x][y] == 0) {
//		map[x][y] = dice[5]; //�ʿ� �ֻ��� �ٴڸ��� ����
//	}
//	//�̵��� ĭ�� ���� 0�� �ƴ϶��
//	else {
//		dice[5] = map[x][y]; //�ֻ��� �ٴڿ� �ʿ� �ִ� ���� ����
//		map[x][y] = 0; //���� 0���� �ٲ�
//	}
//}
//
//void init() {
//	for (int i = 0; i < 6; i++) {
//		temp[i] = dice[i];
//	}
//}
//
//void solve(int command) {
//	switch (command) {
//	case 1:
//	{
//		//�̵��� ĭ�� ���� �����
//		if (y + 1 >= M) {
//			skip = true; //��ŵ
//			return;
//		}
//		init(); //temp �迭�� �ֻ��� ����
//		dice[0] = temp[3]; //�޿� -> ��
//		dice[2] = temp[0]; //�� -> ����
//		dice[3] = temp[5]; //�Ʒ� -> �޿�
//		dice[5] = temp[2]; //���� -> �Ʒ�
//		y = y + 1; //���������� ��ĭ �̵�
//		check(); //�ֻ��� ���� ��� Ȯ��
//		break;
//	}
//	case 2:
//	{
//		//�̵��� ĭ�� ���� �����
//		if (y - 1 < 0) {
//			skip = true; //��ŵ
//			return;
//		}
//		init(); //temp �迭�� �ֻ��� ����
//		dice[0] = temp[2]; //���� -> ��
//		dice[2] = temp[5]; //�Ʒ� -> ����
//		dice[3] = temp[0]; //�� -> �޿�
//		dice[5] = temp[3]; //�޿� -> �Ʒ�
//		y = y - 1; //�������� ��ĭ �̵�
//		check(); //�ֻ��� ���� ��� Ȯ��
//		break;
//	}
//	case 3:
//	{
//		//�̵��� ĭ�� ���� �����
//		if (x - 1 < 0) {
//			skip = true; //��ŵ
//			return;
//		}
//		init(); //temp �迭�� �ֻ��� ����
//		dice[0] = temp[1]; //�� -> ��
//		dice[1] = temp[5]; //�Ʒ� -> ��
//		dice[4] = temp[0]; //�� -> ��
//		dice[5] = temp[4]; //�� -> �Ʒ�
//		x = x - 1; //���� ��ĭ �̵�
//		check(); //�ֻ��� ���� ��� Ȯ��
//		break;
//	}
//	case 4:
//	{
//		//�̵��� ĭ�� ���� �����
//		if (x + 1 >= N) {
//			skip = true; //��ŵ
//			return;
//		}
//		init(); //temp �迭�� �ֻ��� ����
//		dice[0] = temp[4]; //�� -> ��
//		dice[1] = temp[0]; //�� -> ��
//		dice[4] = temp[5]; //�Ʒ� -> ��
//		dice[5] = temp[1]; //�� -> �Ʒ�
//		x = x + 1; //�Ʒ��� ��ĭ �̵�
//		check(); //�ֻ��� ���� ��� Ȯ��
//		break;
//	}
//	}
//}
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
//
//	cin >> N >> M >> x >> y >> k;
//
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < M; j++) {
//			cin >> map[i][j];
//		}
//	}
//	for (int i = 0; i < k; i++) {
//		cin >> command;
//		skip= false;
//		solve(command);
//		//��ŵ�� false�̸� �ֻ��� ���� �� ���
//		if (!skip) {
//			cout << dice[0] << "\n";
//		}
//	}
//	return 0;
//}