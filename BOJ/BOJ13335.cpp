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
//	int n, w, L, a, answer = 0, sum = 0;
//
//	cin >> n >> w >> L;
//
//	queue <int> q; //�ٸ��� ť�� ����
//
//	for (int i = 0; i < n; i++) {
//		cin >> a;
//		while (true) {
//			//�ٸ��� Ʈ���� ���� ���
//			if (q.size() == w) {
//				//�Ǿ� Ʈ���� ���Ը� ���ְ� ť���� pop���ش�
//				sum = sum - q.front();
//				q.pop();
//			}
//			//���� Ʈ���� ���Ը� ���ص� �ٸ��� �ִ����ߺ��� �۰ų� ���� ���
//			if ((sum + a) <= L) {
//				break;
//			}
//			//�ٸ��� ���� Ʈ���� �ö�� �� ��� Ʈ���� �̵���Ű�� �ǹ̷� ť�� 0�� �־��ش�
//			q.push(0);
//			//�̵��� �� ���� count
//			answer++;
//		}
//		//�ٸ��� �ö�� Ʈ���� ť�� �־��ش�
//		q.push(a);
//		//�ٸ����� �ִ� Ʈ������ ���Կ� �߰����ش�
//		sum = sum + a;
//		//�̵������ϱ� count
//		answer++;
//	}
//
//	//������ Ʈ���� ��� �ٸ� ���ۺκп� �ö�� �͸� count �߱� ������ �ٸ��� �� �������� �� ���� �߰��ؼ� ���
//	cout << (answer+w) << "\n";
//
//	return 0;
//}