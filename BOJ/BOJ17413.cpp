//#include<iostream>
//#include<string>
//#include<queue>
//
//using namespace std;
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
//
//	string s;
//	char a; 
//	int idx = 0; // 부분 문자열의 시작점을 저장하는 변수
//	queue <pair <int, int>> q;
//
//	getline(cin, s);
//
//	//공백과 특수문자의 위치를 저장
//	for (int i = 0; i < s.length(); i++) {
//		if (s[i] == '<') {
//			q.push(make_pair(i, 1));
//		}
//		else if (s[i] == '>') {
//			q.push(make_pair(i, 2));
//		}
//		else if (s[i] == ' ') {
//			q.push(make_pair(i, 3));
//		}
//	}
//
//	//<ab cd>fe hg<ij kl>
//	//one1 two2 three3 4fourr 5five 6six
//
//	//마지막에 공백이나 특수문자로 끝나지 않는 경우 맨마지막에 공백을 추가
//	if (q.size() == 0 || q.back().first != (s.length()-1)) {
//		q.push(make_pair(s.length(), 3));
//	}
//
//
//	while (!q.empty()) {
//		//단어여서 뒤집어야 하는경우
//		if (q.front().first != idx) {
//			//단어를 뒤집는 코드
//			for (int i = 0; i < ((q.front().first-idx)/2); i++) {
//				a = s[idx + i];
//				s[idx + i] = s[(q.front().first - 1) - i];
//				s[(q.front().first - 1) - i] = a;
//			}
//			//단어 다음에 특수 문자가 오는 경우
//			if (q.front().second == 1) {
//				goto L;
//			} 
//			idx = q.front().first + 1;
//			q.pop();
//		}
//		//태그인 경우 '>'가 나올때까지 탐색
//		else {
//			if (q.front().second == 1) {
//				L:q.pop();
//				while (!q.empty()) {
//					//'>'가 나오면 다음 부분 문자열의 시작점을 저장
//					if (q.front().second == 2) {
//						idx = (q.front().first) + 1;
//						q.pop();
//						break;
//					}
//					q.pop();
//				}
//			}
//		}
//	}
//
//	cout << s << '\n';
//
//	return 0;
//}