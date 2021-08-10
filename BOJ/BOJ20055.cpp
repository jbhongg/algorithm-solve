//#include<iostream>
//#include<deque>
//
//using namespace std;
//
//deque <pair <int, int>> q; //(������, �κ��� ����(0: �κ��� ���� 1: �κ� ����))
//deque <int> robot; //(�ö� �κ� ������� �κ��� ��ġ ����)
//int N, K, A;
//
//bool check() {
//	int count = 0;
//
//	for (int i = 0; i < q.size(); i++) {
//		//�����̳� ��Ʈ�� �������� 0���� �� �͵��� ī��Ʈ
//		if (q.at(i).first <= 0) {
//			count++;
//		}
//		//�������� 0���� �� �͵��� k�̻��̸� ����
//		if (count >= K) {
//			return false;
//		}
//	}
//
//	return true; //�ƴϸ� ���� �ܰ� ����
//}
//
////�������� ��ġ�� �κ��� �ִ��� Ȯ��
//void down_check() {
//	if (q.at(N - 1).second == 1) {
//		q.at(N - 1).second = 0; //�������� ��ġ�� �κ��� ������ �κ��� ������ ����
//		for (int i = 0; i < robot.size(); i++) {
//			if (robot.at(i) == N - 1) {
//				robot.erase(robot.begin() + i); //�������� ��ġ�� �ִ� �κ� ����
//			}
//		}
//	}
//}
//
//void rotate() {
//	pair <int, int> p;
//	//�����̳� ��Ʈ �ѹ��� ȸ��
//	p = q.back();
//	q.pop_back();
//	q.push_front(p);
//	for (int i = 0; i < robot.size(); i++) {
//		robot.at(i)++; //�κ��� ���� ��ġ ����
//	}
//	down_check(); //�������� ��ġ�� �κ��� �ִ��� Ȯ��
//
//}
//
//void move() {
//	for (int i = 0; i < robot.size(); i++) {
//		//�κ��� ���� ��ġ�� �������� 1 �̻��̰� �κ��� ���ٸ� �̵�
//		if (q.at(robot.at(i) + 1).first > 0 && q.at(robot.at(i) + 1).second == 0) {
//			q.at(robot.at(i)).second = 0; //�κ��� ���� �ִ� ��ġ�� �κ� ���� ǥ�� �ٲ�
//			q.at(robot.at(i) + 1).first--; //�κ��� �̵��� ��ġ�� ������ 1 ����
//			q.at(robot.at(i) + 1).second = 1; //�̵��� ��ġ�� �κ� ǥ��
//			robot.at(i)++; //�κ��� ���� ��ġ ����
//		}
//	}
//	down_check(); //�������� ��ġ�� �κ��� �ִ��� Ȯ��
//}
//
//void raise() {
//	//�ö󰡴� ��ġ�� �κ��� ���ٸ� �κ� �ø�
//	if (q.at(0).second == 0 && q.at(0).first > 0) {
//		q.at(0).first--;    //�ö󰡴� ��ġ�� ������ 1 ����
//		q.at(0).second = 1; //�ö󰡴� ��ġ�� �κ� ǥ�� 
//		robot.push_back(0); //�κ� �߰�
//	}
//}
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
//
//	int count = 0; // �ܰ� ���� ����
//
//	cin >> N >> K;
//
//	for (int i = 0; i < 2 * N; i++) {
//		cin >> A;
//		q.push_back(make_pair(A, 0));
//	}
//	do {
//		count++;
//		rotate(); // ���� 1
//		move();   // ���� 2 
//		raise();  // ���� 3
//	} while (check());  // ���� 4
//
//	cout << count << '\n';
//
//	return 0;
//}