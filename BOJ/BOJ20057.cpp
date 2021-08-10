//#include<iostream>
//
//using namespace std;
//
//int map[499][499];
//int N, c, r, answer;
//흩뿌릴 위치를 탐색하기 위한 배열 각 배열의 마지막은 알파의 위치
//int dc[4][10] = { {-2,-1,-1,-1,0,1,1,1,2,0}, {-1,-1,0,0,0,0,1,1,2,1}, {-2,-1,-1,-1,0,1,1,1,2,0}, {-2,-1,-1,0,0,0,0,1,1,-1} };
//int dr[4][10] = { {0,-1,0,1,-2,-1,0,1,0,-1}, {-1,1,-2,-1,1,2,-1,1,0,0}, {0,-1,0,1,2,-1,0,1,0,1}, {0,-1,1,-2,-1,1,2,-1,1,0} };
////흩뿌릴 위치의 비율 저장
//float rate[4][9] = { {0.02, 0.1, 0.07, 0.01, 0.05, 0.1, 0.07, 0.01, 0.02}, {0.01, 0.01, 0.02, 0.07, 0.07, 0.02, 0.1, 0.1, 0.05}, {0.02, 0.01, 0.07, 0.1, 0.05, 0.01, 0.07, 0.1, 0.02}, {0.05, 0.1, 0.1, 0.02, 0.07, 0.07, 0.02, 0.01, 0.01} };
//
//void sand(int dir) {
//	int sand = map[c][r]; //현재 칸의 모래의 전체양을 저장
//	int temp = sand;      //현재 모래량을 저장하기 위한 변수
//
//	switch (dir) {
//	//왼쪽 방향일 경우
//	case 0: {
//		//흩뿌릴 위치 탐색
//		for (int i = 0; i < 10; i++) {
//			int nc = c + dc[0][i];
//			int nr = r + dr[0][i];
//			//탐색한 위치가 알파 위치면
//			if (i == 9) {
//				//탐색한 위치가 맵안에 있으면
//				if (nc >= 0 && nc < N && nr >= 0 && nr < N) {
//					map[nc][nr] = map[nc][nr] + temp; //남은 현재 모래양을 탐색 위치에 더해줌
//					map[c][r] = 0; //현재 위치를 0으로 바꿔주고 종료
//					break;
//				}
//				//탐색한 위치가 맵 바깥에 있으면
//				else {
//					answer = answer + temp; //남은 현재 모래양을 격자 밖으로 나간 모래 합을 저장한 변수에 더해줌
//					map[c][r] = 0; //현재 위치를 0으로 바꿔주고 종료
//					break;
//				}
//			}
//			//탐색한 위치가 맵안에 있으면
//			if (nc >= 0 && nc < N && nr >= 0 && nr < N) {
//				temp = temp - (int)(sand * rate[0][i]); //해당 위치의 비율만큼 모래를 계산해서 현재 모래량에서 빼줌
//				map[nc][nr] = map[nc][nr] + (int)(sand * rate[0][i]); //탐색한 위치에 비율만큼 모래를 계산해서 더해줌
//			}
//			//탐색한 위치가 맵 바깥에 있으면
//			else {
//				temp = temp - (int)(sand * rate[0][i]);       //해당 위치의 비율만큼 모래를 계산해서 현재 모래량에서 빼줌
//				answer = answer + (int)(sand * rate[0][i]);   //해당 위치의 비율만큼 모래를 계산해서 격자 밖으로 나간 모래 합을 저장한 변수에 더해줌
//			}
//		}
//		break;
//	}
//	//아래쪽 방향일 경우
//	case 1: {
//		for (int i = 0; i < 10; i++) {
//			int nc = c + dc[1][i];
//			int nr = r + dr[1][i];
//			if (i == 9) {
//				if (nc >= 0 && nc < N && nr >= 0 && nr < N) {
//					map[nc][nr] = map[nc][nr] + temp;
//					map[c][r] = 0;
//					break;
//				}
//				else {
//					answer = answer + temp;
//					map[c][r] = 0;
//					break;
//				}
//			}
//			if (nc >= 0 && nc < N && nr >= 0 && nr < N) {
//				temp = temp - (int)(sand * rate[1][i]);
//				map[nc][nr] = map[nc][nr] + (int)(sand * rate[1][i]);
//			}
//			else {
//				temp = temp - (int)(sand * rate[1][i]);
//				answer = answer + (int)(sand * rate[1][i]);
//			}
//		}
//		break;
//	}
//	//오른쪽 방향일 경우
//	case 2: {
//		for (int i = 0; i < 10; i++) {
//			int nc = c + dc[2][i];
//			int nr = r + dr[2][i];
//			if (i == 9) {
//				if (nc >= 0 && nc < N && nr >= 0 && nr < N) {
//					map[nc][nr] = map[nc][nr] + temp;
//					map[c][r] = 0;
//					break;
//				}
//				else {
//					answer = answer + temp;
//					map[c][r] = 0;
//					break;
//				}
//			}
//			if (nc >= 0 && nc < N && nr >= 0 && nr < N) {
//				temp = temp - (int)(sand * rate[2][i]);
//				map[nc][nr] = map[nc][nr] + (int)(sand * rate[2][i]);
//			}
//			else {
//				temp = temp - (int)(sand * rate[2][i]);
//				answer = answer + (int)(sand * rate[2][i]);
//			}
//		}
//		break;
//	}
//	//위쪽 방향일 경우
//	case 3: {
//		for (int i = 0; i < 10; i++) {
//			int nc = c + dc[3][i];
//			int nr = r + dr[3][i];
//			if (i == 9) {
//				if (nc >= 0 && nc < N && nr >= 0 && nr < N) {
//					map[nc][nr] = map[nc][nr] + temp;
//					map[c][r] = 0;
//					break;
//				}
//				else {
//					answer = answer + temp;
//					map[c][r] = 0;
//					break;
//				}
//			}
//			if (nc >= 0 && nc < N && nr >= 0 && nr < N) {
//				temp = temp - (int)(sand * rate[3][i]);
//				map[nc][nr] = map[nc][nr] + (int)(sand * rate[3][i]);
//			}
//			else {
//				temp = temp - (int)(sand * rate[3][i]);
//				answer = answer + (int)(sand * rate[3][i]);
//			}
//		}
//		break;
//	}
//	}
//
//}
//
//void move(int dir, int num) {
//	//왼쪽 방향이면
//	if (dir == 0) {
//		for (int i = 0; i < num; i++) {
//			r = r - 1; //열 이동
//			//행이 0인데 열이 -1이면 열을 0으로 초기화 하고 종료
//			if (c == 0 && r == -1) {
//				r = 0;
//				return;
//			}
//			else {
//				//이동할 위치가 빈칸이아니면
//				if (map[c][r] != 0) {
//					sand(dir);
//				}
//			}
//		}
//	}
//	//아래쪽 방향이면
//	else if (dir == 1) {
//		for (int i = 0; i < num; i++) {
//			c = c + 1; //행 이동
//			//이동할 위치가 빈칸이아니면
//			if (map[c][r] != 0) {
//				sand(dir);
//			}
//		}
//	}
//	//오른쪽 방향이면
//	else if (dir == 2) {
//		for (int i = 0; i < num; i++) {
//			r = r + 1; //열 이동
//			//이동할 위치가 빈칸이아니면
//			if (map[c][r] != 0) {
//				sand(dir);
//			}
//		}
//	}
//	//위쪽 방향이면
//	else if (dir == 3) {
//		for (int i = 0; i < num; i++) {
//			c = c - 1; //행 이동
//			//이동할 위치가 빈칸이아니면
//			if (map[c][r] != 0) {
//				sand(dir);
//			}
//		}
//	}
//
//}
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
//
//	cin >> N;
//
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < N; j++) {
//			cin >> map[i][j];
//		}
//	}
//	//토네이도의 시작 위치(정가운데)
//	c = N / 2;
//	r = N / 2;
//	//뱡향(시작은 왼쪽)
//	int dir = 0;
//
//	int num1 = 1; //왼쪽과 아래쪽 방향의 진행해야할 횟수를 나타낼 변수
//	int num2 = 2; //오른쪽과 위쪽 방향의 진행해야할 횟수를 나타낼 변수
//	
//	while (true) {
//		//토네이도가 0,0에 도착하면 종료
//		if (c == 0 && r == 0) {
//			break;
//		}
//		//왼쪽 방향이면
//		if (dir == 0) {
//			move(dir, num1);
//			dir = 1; //다음방향은 아래쪽
//		}
//		//아래쪽 방향이면
//		else if (dir == 1) {
//			move(dir, num1);
//			dir = 2; //다음방향은 오른쪽
//			num1 = num1 + 2; //다음번 왼쪽과 아래쪽 방향의 진행해야할 횟수 계산
//		}
//		//오른쪽 방향이면
//		else if (dir == 2) {
//			move(dir, num2);
//			dir = 3; //다음방향은 위쪽
//		}
//		//위쪽 방향이면
//		else if (dir == 3) {
//			move(dir, num2);
//			dir = 0; //다음방향은 왼쪽
//			num2 = num2 + 2; //다음번 오른쪽과 위쪽 방향의 진행해야할 횟수 계산
//		}
//	}
//	cout << answer << "\n";
//
//	return 0;
//}