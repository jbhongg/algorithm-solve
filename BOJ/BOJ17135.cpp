//#include<iostream>
//#include<limits.h>
//#include<algorithm>
//#include<vector>
//#include<math.h>
//#include<queue>
//
//using namespace std;
//
//int map[16][15], temp[16][15];
//int N, M, D, cnt, answer;
//vector <int> v; // 궁수 위치 저장 벡터
//vector <pair <pair<int,int>, int> > shot[3]; //화살 정보(발사할 행, 열, 거리)
//queue <int> q;
//
//void init() {
//	//맵 초기화
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < M; j++) {
//			map[i][j] = temp[i][j];
//		}
//	}
//}
//
//void move() {
//	//아래서부터 열 탐색
//	for (int j = 0; j < M; j++) {
//		for (int i = N - 1; i >= 0; i--) {
//			q.push(map[i][j]); //한 행을 큐에 삽입
//		}
//		q.pop(); //첫번째 값을 제거(맨 아래줄 적은 한칸 움직이면 사라지므로)
//		q.push(0); // 큐의 마지막에 0을 추가
//		//행의 아래서부터 큐에 있는 값을 넣어줌
//		for (int i = N - 1; i >= 0; i--) {
//			map[i][j] = q.front();
//			q.pop();
//		}
//	}
//}
//
//void attack() {
//	for (int i = 0; i < 3; i++) {
//		//화살의 정보가 초기화 값이 아니면 화살을 발사할 수 있다는 뜻이므로
//		if (shot[i].front().first.first != INT_MAX) {
//			//화살을 발사할 위치에 적이 있으면 적을 없애고 죽인 적의 수 증가
//			if (map[shot[i].front().first.first][shot[i].front().first.second] == 1) {
//				map[shot[i].front().first.first][shot[i].front().first.second] = 0;
//				cnt++;
//			}
//		}
//	}
//}
//
//bool check() {
//	int count = 0;
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < M; j++) {
//			//맵에 적이 있으면 count 증가
//			if (map[i][j] != 0) {
//				count++;
//			}
//			//cout가 1이면 종료
//			if (count == 1) {
//				goto L;
//			}
//		}
//	}
//	//count가 0이면 적이 없다는 뜻이므로 true 반환
//	L:if (count == 0) {
//		return true;
//	}
//	//적이 있으면 false 반환
//	else {
//		return false;
//	}
//}
//
//void cal() {
//	cnt = 0;
//	//맵에 적이 있으면
//	while (!check()) {
//		//화살 정보 초기화
//		for (int i = 0; i < 3; i++) {
//			shot[i].clear();
//		}
//		shot[0].push_back(make_pair(make_pair(INT_MAX, INT_MAX), INT_MAX));
//		shot[1].push_back(make_pair(make_pair(INT_MAX, INT_MAX), INT_MAX));
//		shot[2].push_back(make_pair(make_pair(INT_MAX, INT_MAX), INT_MAX));
//		//아래서부터 탐색
//		for (int i = N - 1; i >= 0; i--) {
//			for (int j = 0; j < M; j++) {
//				//적을 발견하면
//				if (map[i][j] == 1) {
//					//첫번째 궁수부터 탐색 시작
//					for (int k = 0; k < 3; k++) {
//						//적까지의 거리가 공격 제한 거리보다 작거나 같으면
//						if (((abs(N - i)) + (abs(v[k] - j))) <= D) {
//							//현재 저장되어 있는 거리와 적까지의 거리가 같으면
//							if (shot[k].front().second == ((abs(N - i)) + (abs(v[k] - j)))) {
//								//현재 저장되어 있는 위치보다 탐색한 적의 위치가 더 왼쪽에 있으면
//								if (shot[k].front().first.second >= j) {
//									//현재 적의 행과 열 위치를 저장
//									shot[k].front().first.first = i;
//									shot[k].front().first.second = j;
//								}
//							}
//							//현재 저장되어 있는 거리보다 적까지의 거리가 작으면
//							else if(shot[k].front().second > ((abs(N - i)) + (abs(v[k] - j)))){
//								//현재 적의 행과 열 위치를 저장하고 적까지의 거리를 저장
//								shot[k].front().second = (abs(N - i)) + (abs(v[k] - j));
//								shot[k].front().first.first = i;
//								shot[k].front().first.second = j;
//							}
//						}
//
//					}
//
//					
//				}
//			}
//		}
//		attack(); //화살 발사
//		move(); //적을 한칸씩 아래로 이동
//	}
//	
//
//}
//
//void solve(int n, int idx) {
//	//궁수 배치가 끝나면
//	if (n == 3) {
//		cal(); //화살을 발사할 위치 계산
//		answer = max(answer, cnt);
//		init();//맵 초기화
//		return;
//	}
//
//	//조합
//	for (int i = idx; i < M; i++) {
//		//현재칸에 궁수가 없으면
//		if (map[N][i] != 2) {
//			map[N][i] = 2; //궁수 배치
//			v.push_back(i); //궁수의 위치 벡터에 저장
//			solve(n + 1,i+1);
//			//원상 복귀
//			map[N][i] = 0;
//			v.pop_back();
//		}
//	}
//}
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
//
//	cin >> N >> M >> D;
//
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < M; j++) {
//			cin >> map[i][j];
//			temp[i][j] = map[i][j];
//		}
//	}
//
//	solve(0,0);
//
//	cout << answer << "\n";
//	
//	return 0;
//}