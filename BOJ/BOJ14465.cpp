//#include<iostream>
//#include<algorithm>
//#include<limits.h>
//
//using namespace std;
//
//int light[100001];
//int ans = INT_MAX;
//int cnt;
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
//	
//	int N, K, B;
//
//	cin >> N >> K >> B;
//
//	//고장난 신호등은 1로 표시
//	for (int i = 0; i < B; i++) {
//		int x;
//		cin >> x;
//		light[x] = 1;
//	}
//
//	//1번 신호등 부터 K번 신호등 사이의 고장난 신호등 갯수 저장
//	for (int i = 1; i <= K; i++) {
//		cnt = cnt + light[i];
//	}
//
//	int idx = 1;
//	//K+1번 신호등부터 하나씩 고장난 신호등 갯수 더해주고 1번 신호등 부터 차례로 고장난 신호등 갯수 빼줌
//	for (int i = K+1; i <= N; i++) {
//		cnt = cnt + light[i];
//		cnt = cnt - light[idx];
//		idx++;
//		ans = min(ans, cnt);
//	}
//
//	cout << ans << "\n";
//
//	return 0;
//}