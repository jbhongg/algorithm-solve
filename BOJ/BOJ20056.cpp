//#include<iostream>
//#include<vector>
//
//using namespace std;
//
//struct fireball
//{
//	int r;
//	int c;
//	int m;
//	int s;
//	int d;
//};
//
//int N, M, K, answer = 0;
//int dc[8] = {-1,-1,0,1,1,1,0,-1};
//int dr[8] = {0,1,1,1,0,-1,-1,-1};
//int dir1[4] = { 0,2,4,6 };
//int dir2[4] = { 1,3,5,7 };
//
//vector <fireball> v; //파이어볼을 저장할 벡터 변수
//vector <fireball> temp; //이전 파이어볼의 정보를 보기 위한 변수
//vector <int> map[51][51];
//
//void init() {
//	//맵 초기화
//	for (int i = 1; i <= N; i++) {
//		for (int j = 1; j <= N; j++) {
//			map[i][j].clear();
//		}
//	}
//}
//
//bool dir(int c, int r) {
//	int count = 0;
//	for (int i = 0; i < map[c][r].size(); i++) {
//		//현재 맵에 있는 파이어볼들의 방향이 짝수이면 count 증가
//		if (temp[map[c][r][i]].d % 2 == 0) {
//			count++;
//		}
//	}
//	//count가 0이면 모두 홀수이고 count가 파이어볼의 갯수와 같으면 모두 짝수라는 뜻이므로 true 반환
//	if (count == 0 || count == map[c][r].size()) {
//		return true;
//	}
//	//아니면 false 반환
//	else {
//		return false;
//	}
//}
//
//int speed(int c, int r) {
//	int s = 0;
//	//현재 맵에 있는 파이어볼들의 속도을 모두 더하기
//	for (int i = 0; i < map[c][r].size(); i++) {
//		s = s + temp[map[c][r][i]].s;
//	}
//
//	return (s / map[c][r].size()); //계산한 속도를 현재 맵에 있는 파이어볼의 수로 나눈 값을 반환
//}
//
//int weight(int c, int r) {
//	int w = 0;
//	//현재 맵에 있는 파이어볼들의 질량을 모두 더하기
//	for (int i = 0; i < map[c][r].size(); i++) {
//		w = w + temp[map[c][r][i]].m;
//	}
//
//	return (w / 5); //계산한 질량을 5로 나눈 값을 반환
//} 
//
//void solve() {
//	fireball f; //파이어볼의 정보를 담을 구조체 변수
//	for (int i = 1; i <= N; i++) {
//		for (int j = 1; j <= N; j++) {
//			//해당 맵에 파이어볼이 하나만 있으면 
//			if (map[i][j].size() == 1) {
//				f.r = i; //현재 행 저장
//				f.c = j; //현재 열 저장
//				f.m = temp[map[i][j][0]].m; //현재 파이어볼의 원래 질량 저장
//				f.s = temp[map[i][j][0]].s; //현재 파이어볼의 원래 속도 저장
//				f.d = temp[map[i][j][0]].d; //현재 파이어볼의 원래 방향 저장
//				v.push_back(f); //벡터에 저장
//			}
//			//해당 맵에 파이어볼이 두개 이상이면 
//			else if (map[i][j].size() >= 2) {
//				f.r = i; //현재 행 저장
//				f.c = j; //현재 열 저장
//				f.m = weight(i,j); //질량 구한후 저장(2-3-1단계)
//				f.s = speed(i,j); //속력 구한 후 저장(2-3-2단계)
//				//(2-3-3단계)
//				if (dir(i, j)) {  //기존 파이어볼들의 방향이 모두 홀수이거나 짝수이면
//					for (int k = 0; k < 4; k++) {
//						f.d = dir1[k]; //0,2,4,6 순서대로 방향 저장
//						//질량이 0이면 삭제
//						if (f.m == 0) {
//							break;
//						}
//						//질량이 0이 아니면 벡터에 파이어볼 저장
//						else {
//							v.push_back(f);
//						}
//					}
//				}
//				else { //아닌 경우
//					for (int k = 0; k < 4; k++) {
//						f.d = dir2[k]; //1,3,5,6 순서대로 방향 저장
//						//질량이 0이면 삭제
//						if (f.m == 0) {
//							break;
//						}
//						//질량이 0이 아니면 벡터에 파이어볼 저장
//						else {
//							v.push_back(f);
//						}
//					}
//				}
//			}
//		}
//	}
//}
//
//void move() {
//	for (int i = 0; i < v.size(); i++) {
//		//속력 만큼 진행
//		for (int j = 0; j < v[i].s; j++) {
//			//각 방향으로 행과 열 한칸씩 이동
//			v[i].r = v[i].r + dc[v[i].d];
//			v[i].c = v[i].c + dr[v[i].d];
//			//이동한 위치가 맵을 벗어나는 경우 이어진곳으로 이동
//			if (v[i].r == N+1) {
//				v[i].r = 1;
//			}
//			else if (v[i].r == 0) {
//				v[i].r = N;
//			}
//			if (v[i].c == N+1) {
//				v[i].c = 1;
//			}
//			else if (v[i].c == 0) {
//				v[i].c = N;
//			}
//		}
//		//이동한 후 해당 위치에 현재 파이어볼의 인덱스를 저장
//		map[v[i].r][v[i].c].push_back(i);
//	}
//	v.clear(); //파이어볼 정보 삭제
//}
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
//
//	cin >> N >> M >> K;
//	
//	for (int i = 0; i < M; i++) {
//		fireball f;
//		cin >> f.r >> f.c >> f.m >> f.s >> f.d;
//		v.push_back(f);
//		temp.push_back(f);
//	}
//	//시작
//	for (int i = 0; i < K; i++) {
//		move(); //1단계
//		solve(); //2단계
//		temp.clear(); //이전 파이어볼의 정보는 필요 없으면 temp 벡터 clear
//		init(); //맵 초기화
//		temp.assign(v.begin(), v.end()); //temp 벡터에 새로운 파이어볼들이 담긴 v 벡터를 복사
//	}
//
//	//현재 남아있는 파이어볼들의 질량을 모두 더하기
//	for (int i = 0; i < v.size(); i++) {
//		answer = answer + v[i].m;
//	}
//
//	cout << answer << "\n";
//	
//	return 0;
//}