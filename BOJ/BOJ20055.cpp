//#include<iostream>
//#include<deque>
//
//using namespace std;
//
//deque <pair <int, int>> q; //(내구도, 로봇의 유무(0: 로봇이 없음 1: 로봇 있음))
//deque <int> robot; //(올라간 로봇 순서대로 로봇의 위치 저장)
//int N, K, A;
//
//bool check() {
//	int count = 0;
//
//	for (int i = 0; i < q.size(); i++) {
//		//컨테이너 벨트의 내구도가 0이하 인 것들을 카운트
//		if (q.at(i).first <= 0) {
//			count++;
//		}
//		//내구도가 0이하 인 것들이 k이상이면 종료
//		if (count >= K) {
//			return false;
//		}
//	}
//
//	return true; //아니면 다음 단계 진행
//}
//
////내려가는 위치에 로봇이 있는지 확인
//void down_check() {
//	if (q.at(N - 1).second == 1) {
//		q.at(N - 1).second = 0; //내려가는 위치에 로봇이 있으면 로봇을 땅으로 내림
//		for (int i = 0; i < robot.size(); i++) {
//			if (robot.at(i) == N - 1) {
//				robot.erase(robot.begin() + i); //내려가는 위치에 있던 로봇 삭제
//			}
//		}
//	}
//}
//
//void rotate() {
//	pair <int, int> p;
//	//컨테이너 벨트 한바퀴 회전
//	p = q.back();
//	q.pop_back();
//	q.push_front(p);
//	for (int i = 0; i < robot.size(); i++) {
//		robot.at(i)++; //로봇의 현재 위치 저장
//	}
//	down_check(); //내려가는 위치에 로봇이 있는지 확인
//
//}
//
//void move() {
//	for (int i = 0; i < robot.size(); i++) {
//		//로봇의 다음 위치의 내구도가 1 이상이고 로봇이 없다면 이동
//		if (q.at(robot.at(i) + 1).first > 0 && q.at(robot.at(i) + 1).second == 0) {
//			q.at(robot.at(i)).second = 0; //로봇이 원래 있던 위치의 로봇 유무 표시 바꿈
//			q.at(robot.at(i) + 1).first--; //로봇이 이동한 위치의 내구도 1 줄임
//			q.at(robot.at(i) + 1).second = 1; //이동한 위치에 로봇 표시
//			robot.at(i)++; //로봇의 현재 위치 저장
//		}
//	}
//	down_check(); //내려가는 위치에 로봇이 있는지 확인
//}
//
//void raise() {
//	//올라가는 위치에 로봇이 없다면 로봇 올림
//	if (q.at(0).second == 0 && q.at(0).first > 0) {
//		q.at(0).first--;    //올라가는 위치의 내구도 1 감소
//		q.at(0).second = 1; //올라가는 위치에 로봇 표시 
//		robot.push_back(0); //로봇 추가
//	}
//}
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
//
//	int count = 0; // 단계 저장 변수
//
//	cin >> N >> K;
//
//	for (int i = 0; i < 2 * N; i++) {
//		cin >> A;
//		q.push_back(make_pair(A, 0));
//	}
//	do {
//		count++;
//		rotate(); // 과정 1
//		move();   // 과정 2 
//		raise();  // 과정 3
//	} while (check());  // 과정 4
//
//	cout << count << '\n';
//
//	return 0;
//}