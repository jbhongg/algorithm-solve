//#include<iostream>
//#include<vector>
//#include<algorithm>
//#include<limits.h>
//
//using namespace std;
//
//int M, min_dis = INT_MAX;
//int dis[100][13];
//vector <pair<int, int>> c, h;
//vector <int> sel;
//
//int cal() {
//	int dist = 0;
//	int sum = 0;
//	for (int i = 0; i < h.size(); i++) {
//		int minn = INT_MAX;
//		//M���� ġŲ���� ��� Ž��
//		for (int j = 0; j < sel.size(); j++) {
//			minn = min(minn, dis[i][sel[j]]); //���� ���� ġŲ �Ÿ� ����;
//		}
//		sum = sum + minn; //�������� ġŲ�Ÿ��� ������(������ ġŲ �Ÿ� ���)
//	}
//
//	return sum;
//}
//
//void solve(int idx) {
//	//M���� �̾�����
//	if (sel.size() == M) {
//		min_dis = min(min_dis, cal()); //���� ���� ������ ġŲ �Ÿ� ����
//		return;
//	}
//
//	//ġŲ�� ����
//	for (int i = idx; i < c.size(); i++) {
//		sel.push_back(i); //���Ϳ� ���� ġŲ�� �߰�
//		solve(i+1); //���
//		sel.pop_back(); //���� ���� ���󺹱�
//	}
//}
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
//
//	int N;
//
//	cin >> N >> M;
//
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < N; j++) {
//			int num;
//			cin >> num;
//			if (num == 2) {
//				c.push_back(make_pair(i, j)); //��� ġŲ�� ����
//			}
//			else if (num == 1) {
//				h.push_back(make_pair(i, j)); //��� �� ����
//			}
//		}
//	}
//
//	//�� ������ ġŲ ������ �Ÿ��� ����ϰ� ����
//	for (int i = 0; i < h.size(); i++) {
//		for (int j = 0; j < c.size(); j++) {
//			dis[i][j] = abs(h[i].first - c[j].first) + abs(h[i].second - c[j].second);
//		}
//	}
//
//	solve(0);
//
//	cout << min_dis  << "\n";
//
//	return 0;
//}