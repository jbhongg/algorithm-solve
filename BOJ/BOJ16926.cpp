//#include<iostream>
//#include<queue>
//
//using namespace std;
//
//queue <int> q; //���� ������ �迭�� ����
//int arr[300][300];
//int N, M, R, minn;
//
////�迭 ȸ��
//void rotate(int x, int n, int m) {
//
//	//            (0,0)       1       (0,M-1)
//
//
//	//              4                    2
//
//
//   //            (N-1,0)      3      (N-1,M-1)
//
//
//	 //��� ���� ���� �� / 2 ��ŭ ������ �����ϹǷ� ������ ������ ȸ�������ص� ����
//	if (x == (minn / 2)) {
//		return;
//	}
//	//ť�� ���� ���� �� ������ ����
//	for (int j = x; j < m; j++) {
//		q.push(arr[x][j]);
//	}
//	//ť�� ���� ���� �� �����ʿ� ����
//	for (int i = x + 1; i < n; i++) {
//		q.push(arr[i][m - 1]);
//	}
//	//ť�� ���� ���� �� �Ʒ����� ����
//	for (int j = m - 2; j >= x; j--) {
//		q.push(arr[n - 1][j]);
//	}
//	//ť�� ���� ���� �� ���ʿ� ����
//	for (int i = n - 2; i >= x + 1; i--) {
//		q.push(arr[i][x]);
//	}
//	//ȸ���� ��ŭ ȸ��(���� ť)
//	for (int i = 0; i < R; i++) {
//		int temp = q.front();
//		q.pop();
//		q.push(temp);
//	}
//	//�迭�� ����
//	for (int j = x; j < m; j++) {
//		arr[x][j] = q.front();
//		q.pop();
//	}
//	for (int i = x + 1; i < n; i++) {
//		arr[i][m - 1] = q.front();
//		q.pop();
//	}
//	for (int j = m - 2; j >= x; j--) {
//		arr[n - 1][j] = q.front();
//		q.pop();
//	}
//	for (int i = n - 2; i >= x + 1; i--) {
//		arr[i][x] = q.front();
//		q.pop();
//	}
//	//������ġ�� �ϳ� �����ϰ� ���� �� ��ġ�� ���� �� ��ġ�� �ϳ� �ٿ��� ���
//	rotate(x + 1, n - 1, m - 1);
//}
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
//
//	cin >> N >> M >> R;
//
//	//��� ���� ���� ���� ����
//	if (N >= M) {
//		minn = M;
//	}
//	else {
//		minn = N;
//	}
//
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < M; j++) {
//			cin >> arr[i][j];
//		}
//	}
//
//	rotate(0, N, M);
//
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < M; j++) {
//			cout << arr[i][j] << " ";
//		}
//		cout << '\n';
//	}
//	return 0;
//}