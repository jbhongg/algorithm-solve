//#include<iostream>
//#include<algorithm>
//#include<string>
//
//using namespace std;
//
//string S;
//
//// 다음 다양한 단어를 만들어 주기 위한 함수
//int solve(int index) {
//
//	int minn = 1000000;
//	int idx = -1;
//
//	// 가지고 온 인덱스의 알파벳보다 크면서 그 중 가장 작은 알파벳을 구함
//	for (int i = (index + 1); i < 26; i++) { 
//		if (S.at(index) < S.at(i)) {
//			minn = (minn, S.at(i));
//			if (minn == S.at(i)) {  //가장 작은 알파벳의 인덱스를 저장
//				idx = i;
//			}
//		}
//	}
//	S.push_back(char(S.at(idx))); // 입력한 값 맨 뒤에 가장 작은 알파벳을 추가
//	S.erase(index, (26-index));   // 가져온 인덱스부터 추가한 알파벳 전까지 삭제 
//	
//	return 0;
//}
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
//
//	int maxn, err = 0;
//	int arr[26] = { 0, }; // 알파벳을 체크 하기 위한 변수
//
//	cin >> S;
//
//	//입력값 외에 다른 알파벳이 존재하지 않는 경우
//	if (S.length() == 26) {
//		maxn = S.at(25);                 //마지막 단어 부터 역순으로 뒤에 나보다 큰 알파벳이 존재하는지 확인
//		for (int i = 24; i >= 0; i--) {
//			if (S.at(i) < maxn) {        //존재한다면
//				solve(i);                //현재의 인덱스 값을 가지고 함수로 이동
//				break;                   
//			}
//			else {                       //뒤에 큰 알파벳이 없다면
//				maxn = S.at(i);          //가장 큰 값을 현재의 알파벳으로 저장
//				if (i == 0) {            //맨 처음 알파벳까지 확인한거라면
//					err = 1;             //-1을 출력하기 위한 변수의 값을 변화 
//				}
//			}
//		}
//	}
//	//입력값 외의 다른 알파벳이 존재하는 경우
//	else {
//		for (int i = 0; i < S.length(); i++) {
//			arr[S.at(i) - 97] = 1;       //없는 알파벳이 무엇인지 체크(arr 배열의 0번 인덱스를 'a', 25번 인덱스를 'z'로 생각)
//		}
//		for (int i = 0; i < 26; i++) {
//			if (arr[i] == 0) {           //없는 알파벳중 가장 작은 알파벳을 입력값 맨 뒤에 추가
//				S.push_back(char(i+97));
//				break;
//			}
//		}
//	}
//
//	if (err == 1) {
//		cout << -1 << endl;
//	}
//	else {
//		cout << S << endl;
//	}
//
//	return 0;
//}