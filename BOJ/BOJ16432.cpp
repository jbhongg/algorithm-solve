//#include<iostream>
//#include<vector>
//#include<algorithm>
//
//using namespace std;
//
//bool arr[1001][10];
//int N;
//bool visit[1001][10];
//int answer[10];
//
//bool solve(int k, int back) {
//	//������ ������ ���� ������ ���� �迭 ��� �� ����
//	if (k == N) {
//		for (int i = 0; i < N; i++) {
//			cout << answer[i] << "\n";
//		}
//		return true;
//	}
//	for (int i = 1; i < 10; i++) {
//		//���� ������ ������ ��� ���� �ƴϰ�, �湮���� �ʾҰ�, ���� ���� ������ �ִ� ���̶��
//		if (i != back && !visit[k + 1][i] && arr[k][i]) {
//			visit[k + 1][i] = true; //�湮 ǥ�� [���糯][���� ����]
//			answer[k] = i; //���� �迭�� ���� ���� ���� ����
//			//���
//			if (solve(k + 1, i)) {
//				return true;
//			}
//		}
//	}
//	return false;
//}
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
//
//	cin >> N;
//
//	for (int i = 0; i < N; i++) {
//		int m;
//		cin >> m;
//		for (int j = 0; j < m; j++) {
//			int a;
//			cin >> a;
//			arr[i][a] = true; //[��][���� ����] -> ������ ���� ������ �ִ� �� ǥ��
//		}
//	}
//
//	//������ ������ ���� �� �ָ� -1 ���
//	if (!solve(0, 0)) {
//		cout << -1 << "\n";
//	}
//	
//	return 0;
//}