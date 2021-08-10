//#include<iostream>
//
//using namespace std;
//
//int map[100][100];
//int sum_row[100];
//int sum_col[100];
//int n,c,r;
//
//void solve_col(int idx) {
//	for (int i = 0; i < n; i++) {
//		//현재 행에 해당하는 열들 중 1의 갯수가 홀수 인 것이 있으면 현재 행의 현재 열을 바꾸면 된다는 의미
//		if (sum_row[i] % 2 == 1) {
//			c = idx;
//			r = i;
//			break;
//		}
//	}
//}
//
//void solve_row(int idx) {
//	for (int i = 0; i < n; i++) {
//		//현재 열에 해당하는 행들 중 1의 갯수가 홀수 인 것이 있으면 현재 행의 현재 열을 바꾸면 된다는 의미
//		if (sum_col[i] % 2 == 1) {
//			c = i;
//			r = idx;
//		}
//	}
//}
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
//
//	int count_col = 0, count_row = 0;
//
//	cin >> n;
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < n; j++) {
//			cin >> map[i][j];
//		}
//	}
//	//각 행과 열의 1의 갯수 저장
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < n; j++) {
//			sum_col[i] = sum_col[i] + map[i][j];
//			sum_row[i] = sum_row[i] + map[j][i];
//		}
//	}
//
//	for (int i = 0; i < n; i++) {
//		//각 행이나 열에 1의 갯수가 홀수인 것이 2개 이상이면 종료
//		if (count_col > 1 || count_row > 1) {
//			break;
//		}
//		//현재 행의 1의 갯수가 홀수라면
//		if (sum_col[i] % 2 == 1) {
//			count_col++;  //행의 홀수 갯수를 나타내는 변수 증가
//			solve_col(i); //행의 정보를 인자로 넘겨서 함수 이동
//		}
//		//현재 열의 1의 갯수가 홀수라면
//		if (sum_row[i] % 2 == 1) {
//			count_row++;  //열의 홀수 갯수를 나타내는 변수 증가
//			solve_row(i); //열의 정보를 인자로 넘겨서 함수 이동
//		}
//	}
//
//	//각 행이나 열에 1의 갯수가 홀수인 것이 2개 이상이면 불가 출력
//	if (count_col > 1 || count_row > 1) {
//		cout << "Corrupt" << "\n";
//	}
//	//각 행과 열에 1의 갯수가 모두 짝수이면 가능 출력
//	else if (count_col == 0 && count_row == 0) {
//		cout << "OK" << "\n";
//	}
//	//둘다 아니면 하나의 값만 바꾸면 되므로 위의 탐색에서 찾은 행과 열의 정보를 출력
//	else {
//		cout << "Change bit (" << c+1 << "," << r+1 << ")" << "\n";
//	}
//	
//	return 0;
//}