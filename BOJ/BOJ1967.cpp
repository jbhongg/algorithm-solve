//#include<iostream>
//#include<vector>
//
//using namespace std;
//
//int n, node, answer = 0;
//vector < pair <int, int> > v[10001];
//
//void solve(int x, int w, int bx) {
//	//���� ��忡�� �� �� �ִ� �� Ž��
//	for (int i = 0; i < v[x].size(); i++) {
//		int nx = v[x][i].first; //���� ��
//		int d = v[x][i].second;
//		//���� ��ġ�� �� ��ġ�� ���� ������ ���
//		if (nx != bx) {
//			solve(nx, w + d, x);
//		}
//		//���� ��ġ�� �� ��ġ�� ������
//		else {
//			//��������� �Ÿ��� �� ũ��
//			if (answer < w) {
//				answer = w; //��������� �Ÿ� ����
//				node = x; //���� �ճ�带 ���� ��ġ�� ����
//			}
//		}
//	}
//}
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
//
//	cin >> n;
//
//	for (int i = 0; i < n - 1; i++) {
//		int parent, child, w;
//		cin >> parent >> child >> w;
//		v[parent].push_back(make_pair(child, w));
//		v[child].push_back(make_pair(parent, w));
//	}
//	solve(1, 0, -1); //1���� ���� �հŸ� Ž��
//	answer = 0;
//	solve(node, 0, -1); //1���� ���� �հŸ����� ���� �� �Ÿ� Ž��
//
//	cout << answer << "\n";
//
//	return 0;
//}