//#include<iostream>
//#include<queue>
//
//using namespace std;
//
//deque <pair <int, int>> q; //���� ���� first : �߿䵵 second : �ñ��� �������� �ƴ��� ǥ��
//
//void solve() {
//	for (int i = 1; i < q.size(); i++) {
//		//�Ǿտ� �ִ� ������ �߿䵵���� ū �߿䵵�� ���� ������ �ڿ� �ִٸ�
//		if (q.front().first < q.at(i).first) {
//			//�Ǿ� ������ �ǵڷ� ����
//			pair<int, int> p = q.front();
//			q.push_back(p);
//			q.pop_front();
//			i = 0;
//		}
//	}
//}
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
//
//	int t, n, m, imp;
//	cin >> t;
//	for (int test_case = 0; test_case < t; test_case++) {
//		cin >> n >> m; //������ ����, �ñ��� ������ ���� ��ġ
//		for (int i = 0; i < n; i++) {
//			cin >> imp; // �� ������ �߿䵵
//			//�ñ��� ������ ������ġ�� deque�� idx�� ���ٸ�
//			if (i == m) {
//				//second�� ���� 1�� �־���
//				q.push_back(make_pair(imp, 1));
//			}
//			//�ñ��� ������ �ƴ϶�� ���� 0���� �־���
//			else {
//				q.push_back(make_pair(imp, 0));
//			}
//		}
//		int count = 0; // �ñ��� ������ ���°�� �μ�Ǵ��� ���� ���� ����
//		while (!q.empty()) {
//			solve();
//			//�Ǿ��� ������ �ñ��� �������
//			if (q.front().second == 1) {
//				//ī��Ʈ+1 ���
//				cout << count+1 << '\n';
//				q.clear();
//				break;
//			}
//			//�Ǿ��� ������ �ñ��� ������ �ƴ϶�� ī��Ʈ ���� �� �Ǿ� ���� �μ�
//			count++;
//			q.pop_front();	
//		}
//		
//	}
//	return 0;
//}