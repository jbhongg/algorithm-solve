//#include<iostream>
//#include<vector>
//
//using namespace std;
//
//int map[101][101];
//int N, x, y, d, g;
//int answer = 0;
//vector <int> dir;
//
//void count() {
//	for (int i = 0; i < 100; i++) {
//		for (int j = 0; j < 100; j++) {
//			//현재 위치에서 오른쪽, 오른쪽 대각선 아래, 아래가 모두 1이면 count 증가
//			if (map[i][j] == 1 && map[i + 1][j] == 1 && map[i][j + 1] == 1 && map[i + 1][j + 1] == 1) {
//				answer++;
//			}
//		}
//	}
//}
//
//void cal(int dir) {
//	//방향대로 행과 열을 이동시켜 해당 위치를 1로 저장
//	switch (dir) {
//	case 0:
//	{
//		x++;
//		map[y][x] = 1;
//		break;
//	}
//	case 1:
//	{
//		y--;
//		map[y][x] = 1;
//		break;
//	}
//	case 2:
//	{
//		x--;
//		map[y][x] = 1;
//		break;
//	}
//	case 3:
//	{
//		y++;
//		map[y][x] = 1;
//		break;
//	}
//	}
//}
//
//void draw() {
//	for (int i = 0; i < dir.size(); i++) {
//		cal(dir.at(i));
//	}
//}
//
//void solve() {
//	int n = 0, temp = 0;
//	dir.push_back(d); //시작 방향을 벡터에 넣어줌
//	//세대만큼 진행
//	while (n < g) {
//		int s = dir.size(); //현재 방향을 저장해놓은 벡터의 크기 저장
//		for (int i = s - 1; i >= 0; i--) {
//			temp = (dir.at(i) + 1) % 4;  //저장되어있는 방향들의 역순으로 1을 더한 값이 다음 방향 값(방향은 0~3까지 이므로 4로 나눈 나머지를 저장)
//			dir.push_back(temp); //계산한 다음 방향을 벡터에 추가
//		}
//		n++;
//	}
//
//	draw();
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
//		cin >> x >> y >> d >> g;
//		map[y][x] = 1; //시작위치를 1로 바꿈
//		dir.clear();  
//		solve();
//	}
//
//	count();
//
//	cout << answer << "\n";
//
//	return 0;
//}