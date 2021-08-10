//#include<iostream>
//#include<algorithm>
//#include<limits.h>
//
//using namespace std;
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
//	
//	int N, H, cnt = 0, answer = INT_MAX;
//	int s[100000]; //석순
//	int j[100000]; //종유석
//
//	cin >> N >> H;
//
//	//석순과 종유석을 따로 저장
//	for (int i = 0; i < N/2; i++) {
//		cin >> s[i] >> j[i];
//	}
//
//	//석순과 종유석 오름차순 정렬
//	sort(s, s + (N / 2));
//	sort(j, j + (N / 2));
//	
//	//1부터 H까지 모두 탐색
//	for (int i = 1; i <= H; i++) {
//		//lower_bound(arr, arr+N, k) - arr -> k이상의 수가 처음 시작하는 인덱스 반환
//		//upper_bound(arr, arr+N, k) - arr -> k초과의 수가 처음 시작하는 인덱스 반환
//
//		int s_idx = lower_bound(s, s + (N / 2), i) - s; //해당 구간으로 지나갈때 부딪히는 수석의 갯수 계산
//		int sum = (N / 2) - s_idx;
//		int j_idx = upper_bound(j, j + (N / 2), H - i) - j;  //해당 구간으로 지나갈때 부딪히는 종유석의 갯수 계산
//		sum += (N / 2) - j_idx;; //부딪히는 종유석과 수석의 합 
//
//		//현재 저장되어 있는 답과 현재 구간으로 지나갈 때 부딪히는 종유석과 수석의 합이 같으면
//		if (answer == sum) {
//			cnt++; // 구간의 갯수 증가
//		}
//		//현재 저장되어 있는 답보다 현재 구간으로 지나갈 때 부딪히는 종유석과 수석의 합이 작으면
//		else if (answer > sum) {
//			answer = sum; //답에 현재 구간으로 지나갈 때 부딪히는 종유석과 수석의 합 저장
//			cnt = 1; //구간의 갯수 1로 초기화
//		}
//	}
//
//	cout << answer << " " << cnt << "\n";
//
//	return 0;
//}