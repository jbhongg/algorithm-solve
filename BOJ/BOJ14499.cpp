//#include<iostream>
//
//using namespace std;
//
//int N, M, x, y, k, command;
//bool skip;
//int map[20][20];
//int temp[6];
//int dice[6] = { 0,0,0,0,0,0 }; //위, 앞, 오옆, 왼옆, 뒤, 아래
//
//void check() {
//	//이동한 칸의 값이 0이면
//	if (map[x][y] == 0) {
//		map[x][y] = dice[5]; //맵에 주사위 바닥면을 복사
//	}
//	//이동한 칸의 값이 0이 아니라면
//	else {
//		dice[5] = map[x][y]; //주사위 바닥에 맵에 있는 값을 복사
//		map[x][y] = 0; //맵은 0으로 바뀜
//	}
//}
//
//void init() {
//	for (int i = 0; i < 6; i++) {
//		temp[i] = dice[i];
//	}
//}
//
//void solve(int command) {
//	switch (command) {
//	case 1:
//	{
//		//이동할 칸이 맵을 벗어나면
//		if (y + 1 >= M) {
//			skip = true; //스킵
//			return;
//		}
//		init(); //temp 배열에 주사위 복사
//		dice[0] = temp[3]; //왼옆 -> 위
//		dice[2] = temp[0]; //위 -> 오옆
//		dice[3] = temp[5]; //아래 -> 왼옆
//		dice[5] = temp[2]; //오옆 -> 아래
//		y = y + 1; //오른쪽으로 한칸 이동
//		check(); //주사위 굴린 결과 확인
//		break;
//	}
//	case 2:
//	{
//		//이동할 칸이 맵을 벗어나면
//		if (y - 1 < 0) {
//			skip = true; //스킵
//			return;
//		}
//		init(); //temp 배열에 주사위 복사
//		dice[0] = temp[2]; //오옆 -> 위
//		dice[2] = temp[5]; //아래 -> 오옆
//		dice[3] = temp[0]; //위 -> 왼옆
//		dice[5] = temp[3]; //왼옆 -> 아래
//		y = y - 1; //왼쪽으로 한칸 이동
//		check(); //주사위 굴린 결과 확인
//		break;
//	}
//	case 3:
//	{
//		//이동할 칸이 맵을 벗어나면
//		if (x - 1 < 0) {
//			skip = true; //스킵
//			return;
//		}
//		init(); //temp 배열에 주사위 복사
//		dice[0] = temp[1]; //앞 -> 위
//		dice[1] = temp[5]; //아래 -> 앞
//		dice[4] = temp[0]; //위 -> 뒤
//		dice[5] = temp[4]; //뒤 -> 아래
//		x = x - 1; //위로 한칸 이동
//		check(); //주사위 굴린 결과 확인
//		break;
//	}
//	case 4:
//	{
//		//이동할 칸이 맵을 벗어나면
//		if (x + 1 >= N) {
//			skip = true; //스킵
//			return;
//		}
//		init(); //temp 배열에 주사위 복사
//		dice[0] = temp[4]; //뒤 -> 위
//		dice[1] = temp[0]; //위 -> 앞
//		dice[4] = temp[5]; //아래 -> 뒤
//		dice[5] = temp[1]; //앞 -> 아래
//		x = x + 1; //아래로 한칸 이동
//		check(); //주사위 굴린 결과 확인
//		break;
//	}
//	}
//}
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
//
//	cin >> N >> M >> x >> y >> k;
//
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < M; j++) {
//			cin >> map[i][j];
//		}
//	}
//	for (int i = 0; i < k; i++) {
//		cin >> command;
//		skip= false;
//		solve(command);
//		//스킵이 false이면 주사위 위의 값 출력
//		if (!skip) {
//			cout << dice[0] << "\n";
//		}
//	}
//	return 0;
//}