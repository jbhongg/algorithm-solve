//#include<iostream>
//#include<deque>
//#include<vector>
//
//using namespace std;
//
//deque <int> gear[4]; //톱니바퀴 저장
//int state[3]; // 0 : 1번과 2번 톱니바퀴 맞닿은 부분의 상태 1 : 2번과 3번 톱니바퀴 맞닿은 부분의 상태 2 : 3번과 4번 톱니바퀴의 맞닿은 부분의 상태 
//
////톱니바퀴 회전
//void move(int num, int dir) {
//	int temp;
//	//시계방향 회전
//	if (dir == 1) {
//		temp = gear[num].back();
//		gear[num].pop_back();
//		gear[num].push_front(temp);
//	}
//	//반시계방향 회전
//	else {
//		temp = gear[num].front();
//		gear[num].pop_front();
//		gear[num].push_back(temp);
//	}
//}
//
//void check(int n, int r) {
//	//입력받은 톱니바퀴 회전
//	move(n - 1, r);
//	//입력받은 톱니바퀴가 1번 톱니바퀴면
//	if (n == 1) {
//		for (int i = 0; i < 3; i++) {
//			r = r * -1; //다음 회전은 반대 방향으로 회전하므로 방향을 바꿔줌
//			//톱니바퀴 맞닿은 부분의 극이 같다면
//			if (state[i] == 1) {
//				move(i + 1, r); //다음톱니바퀴 회전
//			}
//			else break;
//		}
//	}
//	//입력받은 톱니바퀴가 2번 톱니바퀴면
//	else if (n == 2) {
//		//1번 톱니바퀴와 맞닿은 부분의 극이 같다면
//		if (state[0] == 1) {
//			move(0, r * -1); //1번 톱니바퀴 회전(반대방향)
//		}
//		for (int i = 1; i < 3; i++) {
//			r = r * -1; //다음 회전은 반대 방향으로 회전하므로 방향을 바꿔줌
//			//톱니바퀴 맞닿은 부분의 극이 같다면
//			if (state[i] == 1) {
//				move(i + 1, r); //다음톱니바퀴 회전
//			}
//			else break;
//		}
//	}
//	//입력받은 톱니바퀴가 3번 톱니바퀴면
//	else if (n == 3) {
//		//4번 톱니바퀴와 맞닿은 부분의 극이 같다면
//		if (state[2] == 1) {
//			move(3, r * -1); //4번 톱니바퀴 회전(반대방향)
//		}
//		for (int i = 1; i >= 0; i--) {
//			r = r * -1; //다음 회전은 반대 방향으로 회전하므로 방향을 바꿔줌
//			//톱니바퀴 맞닿은 부분의 극이 같다면
//			if (state[i] == 1) {
//				move(i, r); //이전 톱니바퀴 회전
//			}
//			else break;
//		}
//	}
//	//입력받은 톱니바퀴가 4번 톱니바퀴면
//	else if (n == 4) {
//		for (int i = 2; i >= 0; i--) {
//			r = r * -1; //다음 회전은 반대 방향으로 회전하므로 방향을 바꿔줌
//			//톱니바퀴 맞닿은 부분의 극이 같다면
//			if (state[i] == 1) {
//				move(i, r);//이전 톱니바퀴 회전
//			}
//			else break;
//		}
//	}
//}
//
//void solve(int n, int r) {
//	for (int i = 0; i < 3; i++) {
//		//톱니바퀴가 맞닿은 부분이 극이 서로 같은지 다른지 상태 저장 
//		if (gear[i].at(2) == gear[i + 1].at(6)) {
//			state[i] = 0; // 같으면 0
//		}
//		else {
//			state[i] = 1; //다르면 1
//		}
//	}
//	check(n, r);
//
//}
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
//
//	int k, n, r, sum = 0;;
//
//	for (int i = 0; i < 4; i++) {
//		string s;
//		cin >> s;
//		for (int j = 0; j < s.length(); j++) {
//			int temp = s[j] - '0';
//			gear[i].push_back(temp);
//		}
//	}
//
//	cin >> k; //회전 횟수
//
//	for (int i = 0; i < k; i++) {
//		cin >> n >> r;
//		solve(n, r);
//	}
//
//	//각 톱니바퀴의 12시 방향 극 확인 후 점수 합산
//	if (gear[0].at(0) == 1) {
//		sum = sum + 1;
//	}
//	if (gear[1].at(0) == 1) {
//		sum = sum + 2;
//	}
//	if (gear[2].at(0) == 1) {
//		sum = sum + 4;
//	}
//	if (gear[3].at(0) == 1) {
//		sum = sum + 8;
//	}
//
//	cout << sum << '\n';
//
//	return 0;
//}