//#include<iostream>
//#include<limits.h>
//#include<queue>
//
//using namespace std;
//
//int dc[4] = { -1,0,1,0 };
//int dr[4] = { 0,1,0,-1 };
//int map[125][125];
//int dist[125][125];
//int N;
//void solve() {
//	//�켱���� ť ����(���� ������ ������)
//	priority_queue < pair < int, pair < int, int> > , vector< pair < int, pair < int, int> > >, greater< pair < int, pair < int, int> > > > pq;
//	pq.push(make_pair(map[0][0], make_pair(0, 0)));
//	while (!pq.empty()) {
//		int c = pq.top().second.first;
//		int r = pq.top().second.second;
//		int cost = pq.top().first; //���� ��ġ������ ���
//		pq.pop();
//		//4�� Ž��
//		for (int i = 0; i < 4; i++) {
//			int nc = c + dc[i];
//			int nr = r + dr[i];
//			//Ž���� ���� �ʾȿ� ������
//			if (nc >= 0 && nr >= 0 && nc < N && nr < N) {
//				//���� ��ġ�� ��뿡 ����ĭ�� ����� ���Ѱ��� Ž��ĭ������ ��뺸�� ������
//				if (dist[nc][nr] > cost + map[nc][nr]) {
//					dist[nc][nr] = cost + map[nc][nr]; //Ž��ĭ������ ����� ����ĭ�� ���� ���� ������� �ٲ��� 
//					pq.push(make_pair(dist[nc][nr], make_pair(nc, nr))); //ť�� ����
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
//	int num = 1;
//
//	while (true) {
//		cin >> N;
//		//�Է°��� 0�� ������ �׽�Ʈ ���̽� ����
//		if (N == 0) {
//			break;
//		}
//		for (int i = 0; i < N; i++) {
//			for (int j = 0; j < N; j++) {
//				cin >> map[i][j];
//				dist[i][j] = INT_MAX; //��ĭ ������ ����� �ִ밪���� �ʱ�ȭ
//			}
//		}
//		dist[0][0] = map[0][0];
//		solve();
//		cout << "Problem " << num << ": " << dist[N-1][N-1] << "\n";
//		num++;
//	}
//
//	return 0;
//}