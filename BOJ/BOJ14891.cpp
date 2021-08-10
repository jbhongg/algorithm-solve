//#include<iostream>
//#include<deque>
//#include<vector>
//
//using namespace std;
//
//deque <int> gear[4]; //��Ϲ��� ����
//int state[3]; // 0 : 1���� 2�� ��Ϲ��� �´��� �κ��� ���� 1 : 2���� 3�� ��Ϲ��� �´��� �κ��� ���� 2 : 3���� 4�� ��Ϲ����� �´��� �κ��� ���� 
//
////��Ϲ��� ȸ��
//void move(int num, int dir) {
//	int temp;
//	//�ð���� ȸ��
//	if (dir == 1) {
//		temp = gear[num].back();
//		gear[num].pop_back();
//		gear[num].push_front(temp);
//	}
//	//�ݽð���� ȸ��
//	else {
//		temp = gear[num].front();
//		gear[num].pop_front();
//		gear[num].push_back(temp);
//	}
//}
//
//void check(int n, int r) {
//	//�Է¹��� ��Ϲ��� ȸ��
//	move(n - 1, r);
//	//�Է¹��� ��Ϲ����� 1�� ��Ϲ�����
//	if (n == 1) {
//		for (int i = 0; i < 3; i++) {
//			r = r * -1; //���� ȸ���� �ݴ� �������� ȸ���ϹǷ� ������ �ٲ���
//			//��Ϲ��� �´��� �κ��� ���� ���ٸ�
//			if (state[i] == 1) {
//				move(i + 1, r); //������Ϲ��� ȸ��
//			}
//			else break;
//		}
//	}
//	//�Է¹��� ��Ϲ����� 2�� ��Ϲ�����
//	else if (n == 2) {
//		//1�� ��Ϲ����� �´��� �κ��� ���� ���ٸ�
//		if (state[0] == 1) {
//			move(0, r * -1); //1�� ��Ϲ��� ȸ��(�ݴ����)
//		}
//		for (int i = 1; i < 3; i++) {
//			r = r * -1; //���� ȸ���� �ݴ� �������� ȸ���ϹǷ� ������ �ٲ���
//			//��Ϲ��� �´��� �κ��� ���� ���ٸ�
//			if (state[i] == 1) {
//				move(i + 1, r); //������Ϲ��� ȸ��
//			}
//			else break;
//		}
//	}
//	//�Է¹��� ��Ϲ����� 3�� ��Ϲ�����
//	else if (n == 3) {
//		//4�� ��Ϲ����� �´��� �κ��� ���� ���ٸ�
//		if (state[2] == 1) {
//			move(3, r * -1); //4�� ��Ϲ��� ȸ��(�ݴ����)
//		}
//		for (int i = 1; i >= 0; i--) {
//			r = r * -1; //���� ȸ���� �ݴ� �������� ȸ���ϹǷ� ������ �ٲ���
//			//��Ϲ��� �´��� �κ��� ���� ���ٸ�
//			if (state[i] == 1) {
//				move(i, r); //���� ��Ϲ��� ȸ��
//			}
//			else break;
//		}
//	}
//	//�Է¹��� ��Ϲ����� 4�� ��Ϲ�����
//	else if (n == 4) {
//		for (int i = 2; i >= 0; i--) {
//			r = r * -1; //���� ȸ���� �ݴ� �������� ȸ���ϹǷ� ������ �ٲ���
//			//��Ϲ��� �´��� �κ��� ���� ���ٸ�
//			if (state[i] == 1) {
//				move(i, r);//���� ��Ϲ��� ȸ��
//			}
//			else break;
//		}
//	}
//}
//
//void solve(int n, int r) {
//	for (int i = 0; i < 3; i++) {
//		//��Ϲ����� �´��� �κ��� ���� ���� ������ �ٸ��� ���� ���� 
//		if (gear[i].at(2) == gear[i + 1].at(6)) {
//			state[i] = 0; // ������ 0
//		}
//		else {
//			state[i] = 1; //�ٸ��� 1
//		}
//	}
//	check(n, r);
//
//}
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
//
//	int k, n, r, sum = 0;;
//
//	for (int i = 0; i < 4; i++) {
//		string s;
//		cin >> s;
//		for (int j = 0; j < s.length(); j++) {
//			int temp = s[j] - '0';
//			gear[i].push_back(temp);
//		}
//	}
//
//	cin >> k; //ȸ�� Ƚ��
//
//	for (int i = 0; i < k; i++) {
//		cin >> n >> r;
//		solve(n, r);
//	}
//
//	//�� ��Ϲ����� 12�� ���� �� Ȯ�� �� ���� �ջ�
//	if (gear[0].at(0) == 1) {
//		sum = sum + 1;
//	}
//	if (gear[1].at(0) == 1) {
//		sum = sum + 2;
//	}
//	if (gear[2].at(0) == 1) {
//		sum = sum + 4;
//	}
//	if (gear[3].at(0) == 1) {
//		sum = sum + 8;
//	}
//
//	cout << sum << '\n';
//
//	return 0;
//}