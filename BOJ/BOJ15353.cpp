//#include<iostream>
//#include <string>
//#include<algorithm>
//
//using namespace std;
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
//
//	int num, next = 0;
//	string A, B, answer = "";
//
//	cin >> A >> B;
//
//	reverse(A.begin(), A.end()); //자리수를 맞추기 위해 뒤집어줌
//	reverse(B.begin(), B.end()); //자리수를 맞추기 위해 뒤집어줌
//
//	int a_len = A.length(); 
//	int b_len = B.length();
//
//	//B가 A보다 크면
//	if (A.length() < B.length()) {
//		for (int i = 0; i < (b_len - a_len); i++) {
//			A += '0'; //A의 뒤에 0을 붙임
//		}
//	}
//	//A가 B보다 크면
//	else if (A.length() > B.length()) {
//		for (int i = 0; i < (a_len - b_len); i++) {
//			B += '0'; //B의 뒤에 0을 붙임
//		}
//	}
//
//	for (int i = 0; i < A.length(); i++) {
//		num = (A[i] - '0' + B[i] - '0' + next) % 10; //계산 
//		answer += to_string(num); //계산한 값을 빈 스트링에 넣어줌
//		next = (A[i] - '0' + B[i] - '0' + next) / 10; //자리 올림수 저장
//	}
//
//	//자리 올림수가 남아있으면
//	if (next != 0) {
//		answer += to_string(next); //자리올림수를 붙여줌
//	}
//
//	reverse(answer.begin(), answer.end()); //다시 스트링을 뒤집어줌
//
//	cout << answer << "\n";
//	
//	return 0;
//}