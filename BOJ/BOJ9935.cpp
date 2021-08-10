//#include<iostream>
//#include<string>
//
//using namespace std;
//char temp[1000001];
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
//
//	string s, bomb;
//	int idx = 0;
//	cin >> s >> bomb;
//	//만약 문자열에 폭타문자열이 하나도 없으면 현재 문자열 출력 후 종료
//	if (s.find(bomb) == -1) {
//		cout << s << "\n";
//		return 0;
//	}
//	else {
//		for (int i = 0; i < s.length(); i++) {
//			temp[idx] = s[i]; //문자열을 순서대로 복사
//			//복사한 값이 폭타 문자열의 마지막 값과 같으면
//			if (temp[idx] == bomb[bomb.length() - 1]) {
//				//현재 복사된 문자열의 길이가 폭탄 문자열의 길이보다 크거나 같으면
//				if ((idx+1) - bomb.length() >= 0) {
//					bool flag = true; //폭탄 문자열을 포함했는지를 알려주는 flag
//					for (int j = 1; j < bomb.length(); j++) {
//						//복사된 문자열과 폭탄 문자열을 뒤에서부터 비교해서 서로 다르면 
//						if (temp[idx - j] != bomb[bomb.length() - 1 - j]) {
//							flag = false; //폭탄 문자열을 포함하지 않았다고 표시 후 탈출
//							break;
//						}
//					}
//					//만약 폭탄문자열이 있으면
//					if (flag) {
//						idx = idx - bomb.length(); //복사 문자열의 인덱스를 폭탄 문자열의 길이 만큼 뺀걸로 바꾸어줌
//					}
//				}
//			}
//			idx++; //인덱스 증가
//		}
//	}
//	//인덱스가 0이라면 문자가 하나도 없다는 의미이므로 FRULA출력
//	if (idx == 0) {
//		cout << "FRULA" << "\n";
//	}
//	//아니면 인덱스까지 출력
//	else {
//		for (int i = 0; i < idx; i++) {
//			cout << temp[i];
//		}
//		cout << "\n";
//	}
//
//	return 0;
//}