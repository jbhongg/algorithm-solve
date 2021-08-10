//#include<iostream>
//#include<set>
//
//using namespace std;
//
//int map[9][9];
//set <int> s;
//bool flag;
//
//void check() {
//	//set의 크기가 9가 아니면 중복된 값이 들어온 것이므로 flag true로 변환
//	if (s.size() != 9) {
//		flag = true;
//	}
//}
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
//
//	int test_case, T;
//	cin >> T;
//	for (test_case = 1; test_case <= T; ++test_case)
//	{
//		flag = false; //불가능인지 가능인지 확인하기 위한 boolean 변수
//		int col = 0;
//		int row = 0;
//		int count = 0;
//		s.clear(); //set 초기화
//		//행 탐색
//		for (int i = 0; i < 9; i++) {
//			s.clear(); //set 초기화
//			for (int j = 0; j < 9; j++) {
//				cin >> map[i][j];
//				s.insert(map[i][j]);
//			}
//			check();
//		}
//		//위에서 불가능이 아니면
//		if (!flag) {
//			//열탐색
//			for (int i = 0; i < 9; i++) {
//				s.clear(); //set 초기화
//				for (int j = 0; j < 9; j++) {
//					s.insert(map[j][i]);
//				}
//				check();
//				// 불가능이면 탈출
//				if (flag) {
//					break;
//				}
//			}
//		}
//		//위에서 불가능이 아니면
//		if (!flag) {
//			//모든 행과 열을 탐색 완료할때까지 반복 
//			while (col != 9 && row != 9) {
//				s.clear(); //set 초기화
//				//3*3씩 탐색
//				for (int i = col; i < col + 3; i++) {
//					for (int j = row; j < row+3; j++) {
//						s.insert(map[i][j]);
//					}
//				}
//				check();
//				// 불가능이면 탈출
//				if (flag) {
//					break;
//				}
//				count++; //열 탐색 수를 세기 위한 변수
//				//3행을 모두 탐색후 다음 행으로 이동
//				col = col + 3;
//				//3열을 모두 탐색 완료하면 다음 열로 이동 행은 처음부터
//				if ((count % 3) == 0) {
//					row = row + 3;
//					col = 0;
//				}
//			}
//		}
//		//불가능이면 0 출력 아니면 1출력
//		if (flag) {
//			cout << "#" << test_case << " " << 0 << "\n";
//		}
//		else {
//			cout << "#" << test_case << " " << 1 << "\n";
//		}
//	}
//	
//	return 0;
//}