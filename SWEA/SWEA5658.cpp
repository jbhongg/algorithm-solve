//#include<iostream>
//#include<deque>
//#include<vector>
//#include<algorithm>
//
//using namespace std;
//
//deque <char> d; //문자열을 문자 하나씩 저장
//vector <string> v; //문자를 합쳐서 저장하는 변수
//vector <int> v2; //합쳐진 16진수 문자를 10진수로 바꾸어 저장
//int N;
//
////내림차순 정렬
//bool cmp(int a, int b) {
//	return a > b;
//}
//
//
//void change() {
//	for (int i = 0; i < v.size(); i++) {
//		v2.push_back(strtol(v.at(i).c_str(), NULL, 16));
//	}
//}
//
////생성가능한 비밀번호를 저장하는 함수
//void check() {
//	string temp;
//	for (int i = 0; i <= N; i++) {
//		if (i != 0 && i % (N / 4) == 0) {
//			v.push_back(temp);
//			temp.clear();
//			if (i == N) {
//				return;
//			}
//		}
//		temp.push_back(d.at(i));
//	}
//
//}
//
////한칸씩 회전하는 함수
//void rotate() {
//	char c = d.back();
//	d.pop_back();
//	d.push_front(c);
//}
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
//
//	int test_case, T;
//	cin >> T;
//
//	for (test_case = 1; test_case <= T; ++test_case)
//	{
//		//초기화
//		d.clear();
//		v.clear();
//		v2.clear();
//		int K;
//		cin >> N >> K;
//		string s;
//		cin >> s;
//		for (int i = 0; i < s.length(); i++) {
//			d.push_back(s[i]); //입력받은 문자열을 문자하나씩 저장
//		}
//		check();
//		for (int i = 1; i < N / 4; i++) {
//			rotate();
//			check();
//		}
//
//		//중복되는 비밀번호를 제거
//		sort(v.begin(), v.end());
//		v.erase(unique(v.begin(), v.end()), v.end());
//
//		//16진수 문자를 10진수로 바꿈
//		change();
//
//		//내림차순 정렬
//		sort(v2.begin(), v2.end(), cmp);
//
//		cout << "#" << test_case << " " << v2[K - 1] << "\n";
//	}
//
//	return 0;
//}