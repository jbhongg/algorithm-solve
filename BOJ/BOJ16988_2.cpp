//#include <cstdio>
//#include<map>
//#include<vector>
//#include<algorithm>
//
//using namespace std;
//
//int N, M, die, answer;
//int board[1000][1000];
//bool visit[1000][1000];
//vector <pair <int, int> > emp; //빈칸의 행과 열 정보를 저장할 벡터 
//map <pair <int, int>, int> m1; //돌을 하나만 놓아도 상대방 돌을 잡을 수 있는 경우를 저장할 map(key: 놓을 돌의 위치, value : 죽는 돌의 갯수)
//map <pair <pair <int, int >, pair <int, int> >, int > m2; //돌을 2개 놓아서 상대방 돌을 잡을 수 있는 경우를 저장할 map(key: 놓을 돌의 위치 2개, value : 죽는 돌의 갯수)
//
//void init() {
//	for (int i = 0; i < emp.size(); i++) {
//		visit[emp.at(i).first][emp.at(i).second] = false;
//	}
//}
//
//void cal() {
//	//m2의 정보를 순서대로 탐색(m2는 ( key : ((c, r), (c, r)), vlaue : 돌의 갯수) ) 형식으로 이루어져 있기 때문에 temp변수 역시 그 형식에 맞게 만들어줌
//	for (auto & temp : m2) {
//		pair <int, int> p1 = temp.first.first;  //key의 첫번째 행과 열을 저장
//		pair <int, int> p2 = temp.first.second; //key의 두번째 행과 열을 저장
//		//이 두곳에 놓았을 때 죽는 돌은 -> 돌을 2개 놓았을 때 죽는 돌의 갯수 + 둘 중 하나만 놓았을 때 죽는 돌의 갯수 + 둘 중 다른 하나만 놓았을 때 죽는 돌의 갯수
//		answer = max(answer, temp.second + m1[p1] + m1[p2]); 
//	}
//	//m1의 크기가 1이상이면(돌을 하나씩 다른 곳에 놓았을 때가 더 많이 잡을 수도 있기 때문에 비교해줘야함)
//	if (m1.size() >= 1) {
//		vector <int> v;
//		//m1의 정보를 순서대로 탐색(m1는 ( key : (c, r), vlaue : 돌의 갯수) ) 형식으로 이루어져 있기 때문에 temp변수 역시 그 형식에 맞게 만들어줌
//		for (auto& temp : m1) {
//			v.push_back(temp.second); //벡터에 잡히는 돌의 갯수를 넣어줌
//		}
//		//벡터의 크기가 1이면
//		if (v.size() == 1) {
//			//그 값과 바로 비교
//			answer = max(answer, v.at(0));
//		}
//		//벡터의 크기가 2 이상이면
//		else {
//			sort(v.rbegin(), v.rend()); //내림차순 정렬(어차피 돌이 많이 잡히는 경우만 보면 되므로 정렬해서 첫번째와 두번째 값을 더해서 비교하면 됨)
//			answer = max(answer, v.at(0) + v.at(1));
//		}
//	}
//}
//
//void dfs(int c, int r) {
//	int dc[4] = { -1,0,1,0 };
//	int dr[4] = { 0,1,0,-1 };
//	//4방 탐색
//	for (int i = 0; i < 4; i++) {
//		int nc = c + dc[i];
//		int nr = r + dr[i];
//		//탐색할 위치가 맵안에 있고 나의 돌이 아니고 방문하지 않았다면
//		if (nc >= 0 && nc < N && nr >= 0 && nr < M && board[nc][nr] != 1 && visit[nc][nr] == false) {
//			//만약 빈칸이라면
//			if (board[nc][nr] == 0) {
//				visit[nc][nr] = true; //방문 표시
//				emp.push_back(make_pair(nc, nr)); //빈칸의 정보 저장
//			}
//			//만약 상대방 돌이라면
//			else if (board[nc][nr] == 2) {
//				visit[nc][nr] = true; //방문 표시
//				die++; //죽는 돌의 갯수 증가
//				dfs(nc, nr);
//			}
//		}
//	}
//}
//
//void solve() {
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < M; j++) {
//			//상대방돌을 발견했고 방문하지 않았다면
//			if (board[i][j] == 2 && visit[i][j] == false) {
//				emp.clear(); //빈칸 정보 저장 벡터 초기화
//				die = 1; //죽는 돌의 갯수 1로 초기화
//				visit[i][j] = true; //현재 위치 방문 표시
//				dfs(i,j);
//				//빈칸의 갯수가 1개이면(돌을 하나만 놓아도 죽는다는 의미) 
//				if (emp.size() == 1) {
//					m1[emp.at(0)] += die; //돌을 하나만 놓아도 상대방 돌을 잡을 수 있는 경우이므로 m1에 저장(key: 빈칸의 위치 value : 죽는 돌의 갯수)
//				}
//				//빈칸의 갯수가 2개이면(돌을 2개 놓아야 죽는다는 의미) 
//				else if (emp.size() == 2) {
//					//순서를 통일시키기 위해 처리
//					if (emp.at(0) > emp.at(1)) {
//						swap(emp.at(0), emp.at(1));
//					}
//					m2[{emp.at(0), emp.at(1)}] += die; //돌을 2개 놓아서 상대방 돌을 잡을 수 있는 경우이므로 m2에 저장(key: ((빈칸의 위치), (빈칸의 위치)) value : 죽는 돌의 갯수)
//				}
//				init(); //visit 초기화(빈칸을 방문했다는 표시만 초기화)
//			}
//		}
//	}
//
//	cal();
//}
//int main() {
//	scanf("%d%d", &N, &M);
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < M; j++) {
//			scanf("%d", &board[i][j]);
//		}
//	}
//	solve();
//
//	printf("%d", answer);
//	return 0;
//}