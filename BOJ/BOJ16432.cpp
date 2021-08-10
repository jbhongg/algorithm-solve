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
//	//마지막 날까지 떡을 줬으면 정답 배열 출력 후 종료
//	if (k == N) {
//		for (int i = 0; i < N; i++) {
//			cout << answer[i] << "\n";
//		}
//		return true;
//	}
//	for (int i = 1; i < 10; i++) {
//		//떡의 종류가 이전에 줬던 떡이 아니고, 방문하지 않았고, 현재 날에 가지고 있는 떡이라면
//		if (i != back && !visit[k + 1][i] && arr[k][i]) {
//			visit[k + 1][i] = true; //방문 표시 [현재날][떡의 종류]
//			answer[k] = i; //정답 배열에 현재 떡의 종류 저장
//			//재귀
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
//			arr[i][a] = true; //[날][떡의 종류] -> 현재의 날에 가지고 있는 떡 표시
//		}
//	}
//
//	//마지막 날까지 떡을 못 주면 -1 출력
//	if (!solve(0, 0)) {
//		cout << -1 << "\n";
//	}
//	
//	return 0;
//}