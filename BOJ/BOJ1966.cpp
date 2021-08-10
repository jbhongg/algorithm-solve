//#include<iostream>
//#include<queue>
//
//using namespace std;
//
//deque <pair <int, int>> q; //문서 저장 first : 중요도 second : 궁금한 문서인지 아닌지 표시
//
//void solve() {
//	for (int i = 1; i < q.size(); i++) {
//		//맨앞에 있는 문서의 중요도보다 큰 중요도를 가진 문서가 뒤에 있다면
//		if (q.front().first < q.at(i).first) {
//			//맨앞 문서를 맨뒤로 보냄
//			pair<int, int> p = q.front();
//			q.push_back(p);
//			q.pop_front();
//			i = 0;
//		}
//	}
//}
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
//
//	int t, n, m, imp;
//	cin >> t;
//	for (int test_case = 0; test_case < t; test_case++) {
//		cin >> n >> m; //문서의 갯수, 궁금한 문서의 현재 위치
//		for (int i = 0; i < n; i++) {
//			cin >> imp; // 각 문서의 중요도
//			//궁금한 문서의 현재위치와 deque의 idx가 같다면
//			if (i == m) {
//				//second의 값을 1로 넣어줌
//				q.push_back(make_pair(imp, 1));
//			}
//			//궁금한 문서가 아니라면 값을 0으로 넣어줌
//			else {
//				q.push_back(make_pair(imp, 0));
//			}
//		}
//		int count = 0; // 궁금한 문서가 몇번째로 인쇄되는지 세기 위한 변수
//		while (!q.empty()) {
//			solve();
//			//맨앞의 문서가 궁금한 문서라면
//			if (q.front().second == 1) {
//				//카운트+1 출력
//				cout << count+1 << '\n';
//				q.clear();
//				break;
//			}
//			//맨앞의 문서가 궁금한 문서가 아니라면 카운트 증가 후 맨앞 문서 인쇄
//			count++;
//			q.pop_front();	
//		}
//		
//	}
//	return 0;
//}