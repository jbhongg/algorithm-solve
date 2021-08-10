//#include<iostream>
//
//using namespace std;
//
//long long mat[101][101];
//long long temp[101][101];
//long long answer[101][101];
//long long N, M;
//
//void cal(long long x[101][101], long long y[101][101]) {
//	//행렬 곱셈
//	for (int i = 0; i < M; i++) {
//		for (int j = 0; j < M; j++) {
//			temp[i][j] = 0;
//			for (int k = 0; k < M; k++) {
//				temp[i][j] += ((x[i][k] * y[k][j]) % 1000000007);
//			}
//			temp[i][j] %= 1000000007;
//		}
//	}
//
//	for (int i = 0; i < M; i++) {
//		for (int j = 0; j < M; j++) {
//			x[i][j] = temp[i][j];
//		}
//	}
//}
//
//void solve(long long n) {
//	//지수를 2로 나눈 몫이 0이면 출력
//	if (n == 0) {
//		return;
//	}
//
//	//지수가 홀수이면  ex) (A^2)^2*A -> (A)^2 -> E * A
//	if (n % 2 == 1) {
//		cal(answer, mat); //행렬 계산
//		//지수를 2로 나눈 몫이 1이면 생략(마지막이므로 A^2을 구할 필요가 없음)
//		if (n != 1) {
//			cal(mat, mat); //행렬 계산
//		}
//		solve(n / 2); //지수를 2로 나눈 값을 인자로 재귀
//	}
//	//지수가 짝수이면 ex) (A^2)^2 -> A^2 -> E * A
//	else {
//		cal(mat, mat); //행렬 계산
//		solve(n / 2); //지수를 2로 나눈 값을 인자로 재귀
//	}
//}
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
//
//	cin >> N >> M;
//	mat[0][0] = 1;
//	mat[0][M - 1] = 1;
//	answer[0][0] = 1; // 단위 행렬 만들기
//	for (int i = 1; i < M; i++) {
//		mat[i][i - 1] = 1;
//		answer[i][i] = 1;
//	}
//
//	solve(N);
//
//	cout << answer[0][0] << "\n";
//	return 0;
//}