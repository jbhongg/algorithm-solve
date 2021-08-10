//#include<iostream>
//#include<queue>
//
//using namespace std;
//
//queue <int> q; //같은 라인의 배열들 저장
//int arr[300][300];
//int N, M, R, minn;
//
////배열 회전
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
//	 //행과 열중 작은 수 / 2 만큼 라인이 존재하므로 마지막 라인을 회전시켜준뒤 종료
//	if (x == (minn / 2)) {
//		return;
//	}
//	//큐에 같은 라인 중 위쪽행 저장
//	for (int j = x; j < m; j++) {
//		q.push(arr[x][j]);
//	}
//	//큐에 같은 라인 중 오른쪽열 저장
//	for (int i = x + 1; i < n; i++) {
//		q.push(arr[i][m - 1]);
//	}
//	//큐에 같은 라인 중 아래쪽행 저장
//	for (int j = m - 2; j >= x; j--) {
//		q.push(arr[n - 1][j]);
//	}
//	//큐에 같은 라인 중 왼쪽열 저장
//	for (int i = n - 2; i >= x + 1; i--) {
//		q.push(arr[i][x]);
//	}
//	//회전수 만큼 회전(원형 큐)
//	for (int i = 0; i < R; i++) {
//		int temp = q.front();
//		q.pop();
//		q.push(temp);
//	}
//	//배열에 저장
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
//	//시작위치를 하나 증가하고 행의 끝 위치와 열의 끝 위치를 하나 줄여서 재귀
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
//	//행과 열중 작은 값을 저장
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