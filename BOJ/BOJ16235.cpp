//#include<iostream>
//#include<vector>
//#include<algorithm>
//
//using namespace std;
//
//int add_food[10][10]; //겨울에 추가할 양분
//int food[10][10]; //현재 양분
//vector <int> map[10][10]; //나무를 저장할 맵
//int N, M, K, answer;
//int dc[8] = {-1,-1,0,1,1,1,0,-1};
//int dr[8] = {0,1,1,1,0,-1,-1,-1};
//
//void cal() {
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < N; j++) {
//			answer = answer + map[i][j].size(); //칸의 사이즈가 나무의 갯수
//		}
//	}
//}
//
//void winter() {
//	//각 칸에 해당하는 추가 양분을 추가 
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < N; j++) {
//			food[i][j] = food[i][j] + add_food[i][j];
//		}
//	}
//}
//
//void autumn() {
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < N; j++) {
//			//현재 칸에 나무가 있다면
//			if (map[i][j].size() != 0) {
//				//나무 갯수 만큼 진행
//				for (int k = 0; k < map[i][j].size(); k++) {
//					//현재 나무의 나이가 5의 배수라면
//					if (map[i][j].at(k) % 5 == 0) {
//						//8방 탐색
//						for (int r = 0; r < 8; r++) {
//							int nc = i + dc[r];
//							int nr = j + dr[r];
//							//탐색한 칸이 맵안에 있다면
//							if (nc >= 0 && nc < N && nr >= 0 && nr < N) {
//								map[nc][nr].push_back(1); //탐색한 칸에 나이 1짜리 나무를 넣어줌
//							}
//						}
//					}
//				}
//			}
//		}
//	}
//}
//
//void spring_and_summer() {
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < N; j++) {
//			//칸에 나무가 하나라면
//			if (map[i][j].size() == 1) {
//				//칸의 양분보다 나무의 나이가 크면
//				if (food[i][j] < map[i][j].front()) {
//					//여름 진행
//					food[i][j] = food[i][j] + (map[i][j].front() / 2); //칸에 양분으로 주고
//					map[i][j].pop_back(); //나무 삭제
//				}
//				//칸의 양분보다 나무의 나이가 작거나 같으면
//				else {
//					food[i][j] = food[i][j] - map[i][j].front(); //칸의 양분을 나무의 나이만큼 제거
//					map[i][j].front() = map[i][j].front() + 1; //나무의 나이 한살 증가
//				}
//			}
//			//칸에 나무가 여러개라면
//			else if (map[i][j].size() > 1) {
//				sort(map[i][j].begin(), map[i][j].end()); //나이순으로 오름차순 정렬
//				for (int k = 0; k < map[i][j].size(); k++) {
//					//칸의 양분보다 현재 나무의 나이가 크면
//					if (food[i][j] < map[i][j].at(k)) {
//						//마지막 나무부터 현재 나무까지 여름 진행 후 탈출
//						for (int q = map[i][j].size() - 1; q >= k; q--) {
//							food[i][j] = food[i][j] + (map[i][j].at(q) / 2); //칸에 양분으로 주고
//							map[i][j].pop_back(); //나무 삭제
//						}
//						break;
//					}
//					//칸의 양분보다 현재 나무의 나이가 작거나 같으면
//					else {
//						food[i][j] = food[i][j] - map[i][j].at(k); //칸의 양분을 현재 나무의 나이만큼 제거
//						map[i][j].at(k) = map[i][j].at(k) + 1; //현재 나무의 나이 한살 증가
//					}
//				}
//			}
//		}
//	}
//}
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
//
//	cin >> N >> M >> K;
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < N; j++) {
//			cin >> add_food[i][j]; //겨울에 추가할 양분 저장
//			food[i][j] = 5; //초기 양분은 5
//		}
//	}
//
//	for (int i = 0; i < M; i++) {
//		int c, r, age;
//		cin >> c >> r >> age;
//		map[c-1][r-1].push_back(age); //나무 나이를 맵에 저장
//	}
//
//	int count = 0;
//
//	//K년이 지나면 종료
//	while (count != K) {
//		spring_and_summer(); //봄과 여름
//		autumn(); //가을
//		winter(); //겨울
//		count++; //년 증가
//	}
//
//	cal(); //남은 나무 계산
//	
//	cout << answer << "\n";
//
//	return 0;
//}