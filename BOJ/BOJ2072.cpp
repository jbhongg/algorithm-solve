//#include<iostream>
//#include<queue>
//
//using namespace std;
//
//char map[20][20];
//int dc[8] = {-1,-1,0,1,1,1,0,-1};
//int dr[8] = {0,1,1,1,0,-1,-1,-1};
//bool flag;
//bool visit[8];
//
//queue <pair <pair <int, int>, char> > q;
//
////���� Ž�� �Ϸ� ǥ�� �迭 �ʱ�ȭ
//void init() {
//	for (int i = 0; i < 8; i++) {
//		visit[i] = false;
//	}
//}
//
//void check(int c, int r, int dir, char s) {
//	int cnt = 1; //���� ������ ���� ���� ����
//	int nc = c + dc[dir]; 
//	int nr = r + dr[dir];
//
//	//���ڷ� �Ѿ�� Ž�� �������� Ž�� ����
//	while (true) {
//		//Ž���� ���� ��ġ�� �ٵ��� �ȿ� �ְ� �� ��ġ�� ���� ���� �ٵϾ��� ������
//		if (nc >= 1 && nc < 20 && nr >= 1 && nr < 20 && map[nc][nr] == s) {
//			cnt++; //�ٵϵ� ���� ����
//		}
//		//�ƴ϶�� ����
//		else {
//			break;
//		}
//		nc = nc + dc[dir];
//		nr = nr + dr[dir];
//	}
//
//	//Ž���� ������ �ݴ���⵵ �Բ� Ž���� ������ϹǷ� ���� �缳��
//	if (dir > 3) {
//		dir = dir - 4;
//	}
//	else {
//		dir = dir + 4;
//	}
//	nc = c + dc[dir];
//	nr = r + dr[dir];
//
//	//Ž���� ���� ���� �����̶�� Ž�� ����
//	while (!visit[dir]) {
//		//Ž���� ���� ��ġ�� �ٵ��� �ȿ� �ְ� �� ��ġ�� ���� ���� �ٵϾ��� ������
//		if (nc >= 1 && nc < 20 && nr >= 1 && nr < 20 && map[nc][nr] == s) {
//			cnt++; //�ٵϵ� ���� ����
//		}
//		//�ƴ϶�� ����
//		else {
//			break;
//		}
//		nc = nc + dc[dir];
//		nr = nr + dr[dir];
//	}
//	//������ Ž���ߴٰ� ǥ��
//	visit[dir] = true;
//
//	//������ 5����� 5����� ǥ��
//	if (cnt == 5) {
//		flag = true;
//	}
//}
//
//void solve(char s) {
//	int c = q.front().first.first;
//	int r = q.front().first.second;
//	map[c][r] = s; //�ٵ��ǿ� ���� �Է�
//	init();
//	//8�� Ž��
//	for (int i = 0; i < 8; i++) {
//		int nc = c + dc[i];
//		int nr = r + dr[i];
//		//Ž���� ��ġ�� �ٵ��Ǿȿ� �ְ� �̹� Ž���ߴ� ������ �ƴ϶��
//		if (nc >= 1 && nc < 20 && nr >= 1 && nr < 20 && map[nc][nr] == s && visit[i] == false) {
//			visit[i] = true; //������ Ž���ߴٰ� ǥ��
//			check(c, r, i, s);
//		}
//	}
//}
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
//
//	int N, count = 0; //���°�� ������ �������� �������� ����
//	
//	cin >> N;
//
//	//ť�� ���� ��ġ�� �� ����
//	for (int i = 1; i <= N; i++) {
//		int c, r;
//		cin >> c >> r;
//		if (i % 2 == 1) {
//			q.push(make_pair(make_pair(c, r), 'B'));
//		}
//		else {
//			q.push(make_pair(make_pair(c, r), 'W'));
//		}
//	}
//
//	while (!q.empty()) {
//		//���� 5���� �Ǹ� ���
//		if (flag) {
//			cout << count <<"\n";
//			return 0;
//		}
//		count++;
//		solve(q.front().second);
//		q.pop();
//	}
//
//	cout << -1 << "\n";
//
//  return 0;
//}