//#include<iostream>
//#include<vector>
//#include<algorithm>
//
//using namespace std;
//
//vector <pair<int, int>> v;
//int temp, N, cnt, answer;
//
//void cal() {
//	cnt = 0;
//	//깨진 달걀 세기
//	for (int i = 0; i < N; i++) {
//		if (v.at(i).first <= 0) {
//			cnt++;
//		}
//	}
//}
//
//void solve(int idx) {
//	//다 깨진 상황이 있으면 그게 최댓값이므로 종료
//	if (answer == N) {
//		return;
//	}
//	//마지막 계란까지 갔으면
//	if (idx == N) {
//		cal(); //계산
//		answer = max(answer, cnt); //최댓값 저장
//		return;
//	}
//	//들고 있는 계란이 이미 깨진 계란이면 다음 계란으로 이동
//	if (v.at(idx).first <= 0) {
//		solve(idx + 1);
//		return;
//	}
//	for (int i = 0; i < N; i++) {
//		//자기 자신이거나 칠 계란이 이미 깨진 계란이라면
//		if (i == idx || v.at(i).first <= 0) {
//			//칠 계란이 마지막 계란이라면
//			if (i == N - 1) {
//				//들고 있는 계란을 다음 계란으로 이동
//				solve(idx + 1);
//			}
//			//다음 계란 탐색
//			continue;
//		}
//		//칠 수 있다면
//		else {
//			v.at(i).first = v.at(i).first - v.at(idx).second;   //칠 계란의 내구도 변화 계산
//			v.at(idx).first = v.at(idx).first - v.at(i).second; //들고 있는 계란의 내구도 변화 계산
//			solve(idx + 1); //들고 있는 계란을 다음 계란으로 이동
//			//이전 값으로 복구
//			v.at(i).first = v.at(i).first + v.at(idx).second;
//			v.at(idx).first = v.at(idx).first + v.at(i).second;
//		}
//	}
//}
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
//
//	int S, W;
//
//	cin >> N;
//
//	for (int i = 0; i < N; i++) {
//		cin >> S >> W;
//		v.push_back(make_pair(S, W));
//	}
//	
//	solve(0);
//
//	cout << answer << "\n";
//
//    return 0;
//}