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
//			//���� ��ġ���� ������, ������ �밢�� �Ʒ�, �Ʒ��� ��� 1�̸� count ����
//			if (map[i][j] == 1 && map[i + 1][j] == 1 && map[i][j + 1] == 1 && map[i + 1][j + 1] == 1) {
//				answer++;
//			}
//		}
//	}
//}
//
//void cal(int dir) {
//	//������ ��� ���� �̵����� �ش� ��ġ�� 1�� ����
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
//	dir.push_back(d); //���� ������ ���Ϳ� �־���
//	//���븸ŭ ����
//	while (n < g) {
//		int s = dir.size(); //���� ������ �����س��� ������ ũ�� ����
//		for (int i = s - 1; i >= 0; i--) {
//			temp = (dir.at(i) + 1) % 4;  //����Ǿ��ִ� ������� �������� 1�� ���� ���� ���� ���� ��(������ 0~3���� �̹Ƿ� 4�� ���� �������� ����)
//			dir.push_back(temp); //����� ���� ������ ���Ϳ� �߰�
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
//		map[y][x] = 1; //������ġ�� 1�� �ٲ�
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