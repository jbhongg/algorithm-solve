//#include<iostream>
//#include<queue>
//
//using namespace std;
//
//bool visit[1002][1002]; //[���÷��̿� �ִ� �̸�Ƽ�� ����][Ŭ�����忡 �ִ� �̸�Ƽ�� ����]
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
//	
//	int S;
//	queue <pair < pair <int, int>, int> > q; //���÷���, Ŭ��, �ð�
//
//	cin >> S;
//	q.push(make_pair(make_pair(1, 0), 0)); //�ʱⰪ push
//	visit[1][0] = true;
//	while (!q.empty()) {
//		int dis = q.front().first.first;
//		int clip = q.front().first.second;
//		int time = q.front().second;
//		q.pop();
//
//		//���÷��̿� �ִ� �̸�Ƽ�� ������ S�� ������ �ð� ��� �� Ż��
//		if (dis == S) {
//			cout << time << "\n";
//			break;
//		}
//
//		//���÷��̿� �ִ� �̸�Ƽ�� ������ 1�̻��̰� �ִ� ���϶��
//		if (dis > 0 && dis < 1002) {
//			//���� �湮���� �ʾҴٸ�(1�� ����)
//			if (!visit[dis][dis]) {
//				visit[dis][dis] = true; //�湮 üũ
//				q.push(make_pair(make_pair(dis, dis), time + 1)); //ť�� �߰�
//			}
//
//			//���� �湮���� �ʾҴٸ�(3�� ����)
//			if (!visit[dis - 1][clip]) {
//				visit[dis - 1][clip] = true; //�湮 üũ
//				q.push(make_pair(make_pair(dis-1, clip), time + 1));//ť�� �߰�
//			}
//		}
//
//		//Ŭ�������� �̸�Ƽ�� ������ 1�� �̻��̰� ���÷��̿� �ִ� �̸�Ƽ�� �������� ���� �ִ밪 �����̸�
//		if (clip > 0 && dis + clip < 1002) {
//			//���� �湮���� �ʾҴٸ�(2�� ����)
//			if (!visit[dis + clip][clip]) {
//				visit[dis + clip][clip] = true; //�湮 üũ
//				q.push(make_pair(make_pair(dis + clip, clip), time + 1));//ť�� �߰�
//			}
//		}
//	}
//	
//	return 0;
//}