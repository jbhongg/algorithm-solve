//#include<iostream>
//#include<string>
//
//using namespace std;
//
//bool check[988]; //가능한 수를 판별하기 위한 배열
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
//
//	int N, num, strike, ball;
//	fill_n(check, 988, true); //boolean 배열 true로 초기화
//
//	cin >> N;
//
//	for (int i = 0; i < N; i++) {
//		cin >> num >> strike >> ball;
//		string talk = to_string(num); //입력 받은 숫자 문자열로 변환 
//		//123~987 완전 탐색
//		for (int j = 123; j <= 987; j++) {
//			string answer = to_string(j); //탐색할 숫자 문자열로 변환
//			//같은 숫자가 있거나 0이 들어가 있는 수는 탐색 x
//			if (answer[0] != answer[1] && answer[0] != answer[2] && answer[1] != answer[2] && answer[0] != '0' && answer[1] != '0' && answer[2] != '0') {
//				int count_s = 0, count_b = 0; //입력 받은 문자와 탐색한 문자 사이의 스트라이크와 볼의 갯수를 세기 위한 변수
//				for (int k = 0; k < 3; k++) {
//					for (int r = 0; r < 3; r++) {
//						//같은 자리인데 같은 숫자이면 스트라이크 갯수 증가
//						if (k == r && answer[k] == talk[r]) {
//							count_s++;
//						}
//						//다른 자리인데 같은 숫자이면 볼 갯수 증가
//						else if (k != r && answer[k] == talk[r]) {
//							count_b++;
//						}
//					}
//				}
//				//입력받은 스트라이크와 볼의 갯수와 다르면 해당 수는 답이 될 수 없으므로 해당 배열 false로 변환
//				if (count_s != strike || count_b != ball) {
//					check[j] = false;
//				}
//			}
//			else {
//				check[j] = false; //답이 될 수 없는 수 이므로 해당 배열 false로 변환
//			}
//		}
//	}
//
//	int answer = 0;
//
//	//true인 것의 갯수를 세서 출력
//	for (int i = 123; i <= 987; i++) {
//		if (check[i]) {
//			answer++;
//		}
//	}
//
//	cout << answer << '\n';
//
//	return 0;
//}