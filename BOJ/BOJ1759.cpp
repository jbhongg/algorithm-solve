//#include<iostream>
//#include<algorithm>
//#include<vector>
//
//using namespace std;
//
//char vowel[5] = { 'a', 'e', 'i', 'o', 'u' };
//char c[15];
//vector <char> v;
//int L, C;
//
//void print() {
//	for (int i = 0; i < L; i++) {
//		cout << v[i];
//	}
//	cout << "\n";
//}
//
//bool check() {
//	int count = 0;
//	//모음 갯수 세기
//	for (int i = 0; i < L; i++) {
//		for (int j = 0; j < 5; j++) {
//			if (v[i] == vowel[j]) {
//				count++;
//			}
//		}
//	}
//	//모음갯수가 0개이거나 L-1개 이상(자음이 2개 미만이라는 뜻)이면
//	if (count == 0 || count >= L - 1) {
//		return false; //false 반환
//	}
//	return true;
//}
//
//void solve(int k, int idx) {
//	//다뽑았으면
//	if (k == L) {
//		//모음 자음 갯수 확인
//		//부적절하면
//		if (!check()) {
//			return;
//		}
//		//적절하면 출력
//		else {
//			print();
//		}
//		return;
//	}
//
//	//조합
//	for (int i = idx; i < C; i++){
//		v.push_back(c[i]);
//		solve(k + 1, i+1);
//		v.pop_back();
//	}
//}
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
//
//	cin >> L >> C;
//
//	for (int i = 0; i < C; i++) {
//		cin >> c[i];
//	}
//
//	sort(c, c+C); //오름차순 정렬
//	solve(0,0);
//
//	return 0;
//}