//#include<iostream>
//#include<vector>
//
//using namespace std;
//
//int N, P, E;
//bool flag = false;
//vector < pair <int, int> > v;
//vector <int> sel;
//int answer[20];
//
//void solve(int idx) {
//	//�ѹ��̶� �ټ� ������ ����
//	if (flag) {
//		return;
//	}
//	//�ٻ̾�����
//	if (sel.size() == P) {
//		int minn = 0, maxn = 0;
//		for (int i = 0; i < P; i++) {
//			minn = v[sel[i]].first + minn; //���� ���յ� ������� x���� ����
//			maxn = v[sel[i]].second + maxn; //���� ���յ� ������� y���� ����
//		}
//		int n = E - minn;
//		//���� ���յ� ������� x���� y�� ���̿� E�� ������ �� �� ����
//		if (E >= minn && E <= maxn) {
//			//�ϴ� ���� �ּڰ� ��ŭ ����ϰ� ������ ���� ���
//			for (int i = 0; i < P; i++) {
//				answer[sel[i]] = v[sel[i]].first;
//				while (true) {
//					if (n == 0) {
//						break;
//					}
//					if (answer[sel[i]] == v[sel[i]].second) {
//						break;
//					}
//					else {
//						answer[sel[i]]++;
//						n--;
//					}
//
//				}
//			}
//			flag = true;
//		}
//		else {
//			return;
//		}
//	}
//
//	//����
//	for (int i = idx; i < N; i++) {
//		sel.push_back(i);
//		solve(i + 1);
//		sel.pop_back();
//	}
//}
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
//	
//	cin >> N >> P >> E;
//
//	for (int i = 0; i < N; i++) {
//		int x, y;
//		cin >> x >> y;
//		v.push_back(make_pair(x, y));
//	}
//	
//	solve(0);
//
//	if (!flag) {
//		cout << -1 << "\n";
//	}
//	else {
//		for (int i = 0; i < N; i++) {
//			cout << answer[i] << " ";
//		}
//		cout << "\n";
//	}
//
//	return 0;
//}