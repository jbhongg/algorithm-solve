//#include<iostream>
//#include<queue>
//
//using namespace std;
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
//
//	int N;
//	queue <int> q; //��ȣ�� ������ ť
//
//	cin >> N;
//
//	//ť�� 1���� N���� ��ȣ ������� ����
//	for (int i = 1; i <= N; i++) {
//		q.push(i);
//	}
//
//	long long count = 1; //num^3�� int���� �Ѿ�Ƿ� long long���� ���
//	long long num = 1;
//
//	//ť�� ���� �ϳ��� ���������� �ݺ�
//	while (q.size() != 1) {
//		//ť�� ũ�⸸ŭ ���� ���󺹱��̹Ƿ� ť�� ũ��� ���� ������ ����ŭ �ݺ� �����ϸ� ���� ����� ť�� �ǵڷ� ����
//		for (int i = 1; i <= ((count-1)%q.size()); i++) {
//			int temp = q.front();
//			q.push(temp);
//			q.pop();
//		}
//		//ť�� �Ǿ� ����
//		q.pop();
//		num++;
//		count = num * num * num;
//	}
//	cout << q.front() << '\n';
//
//	return 0;
//}