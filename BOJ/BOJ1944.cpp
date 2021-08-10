//#include<iostream>
//#include<queue>
//#include<vector>
//#include<algorithm>
//
//using namespace std;
//
//typedef struct Edge {
//	int from;
//	int to;
//	int weight;
//}Edge;
//
//int dc[4] = { -1,0,1,0 };
//int dr[4] = { 0,1,0,-1 };
//int parent[251];
//int N, M;
//char map[50][50];
//bool visit[50][50];
//bool flag;
//vector < pair < pair <int, int>, int> > key;
//vector <Edge> edge;
//pair <int, int> p;
//
////���� ����� ��ǥ ã��
//int find(int a) {
//	//��ǥ�� �ڱ��ڽ��̶�� return
//	if (parent[a] == a) {
//		return a;
//	}
//	//�ƴϸ� ��ǥ�� ã�� �� ���� ���
//	return parent[a] = find(parent[a]);
//}
//
//bool Union(int a, int b) {
//	int aroot = find(a);
//	int broot = find(b);
//	//��߰� ���� ����� ��ǥ�� ������ false return
//	if (aroot == broot) {
//		return false;
//	}
//	//�ƴϸ� ���� ����� ��ǥ�� ��߳���� ��ǥ�� ����
//	parent[broot] = aroot;
//	return true;
//}
//
//void make() {
//	for (int i = 0; i < key.size() + 1; i++) {
//		parent[i] = i;
//	}
//}
//
//bool cmp(Edge e1, Edge e2) {
//	return e1.weight < e2.weight;
//}
//
//void init() {
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < N; j++) {
//			visit[i][j] = false;
//		}
//	}
//}
//
//void bfs(int sc, int sr, int ec, int er, int sn, int en) {
//	init(); //visit �迭 �ʱ�ȭ
//	queue < pair <pair <int, int>, int > > q;
//	q.push(make_pair(make_pair(sc, sr), 0));
//	visit[sc][sr] = true;
//	while (!q.empty()) {
//		int c = q.front().first.first;
//		int r = q.front().first.second;
//		int cnt = q.front().second; //���� �Ÿ�
//		q.pop();
//
//		//���� ��ġ�� ���������
//		if (c == ec && r == er) {
//			Edge e;
//			e.from = sn;
//			e.to = en;
//			e.weight = cnt;
//			edge.push_back(e); //���Ϳ� ���� ���� ���� ����
//			return;
//		}
//		//4�� Ž��
//		for (int i = 0; i < 4; i++) {
//			int nc = c + dc[i];
//			int nr = r + dr[i];
//			//Ž���� ��ġ�� �ʾȿ� �ְ� ���� �ƴϰ� �湮���� ���� ���̶��
//			if (nc >= 0 && nr >= 0 && nc < N && nr < N && map[nc][nr] != '1' && visit[nc][nr] == false) {
//				visit[nc][nr] = true; //�湮 ǥ��
//				q.push(make_pair(make_pair(nc, nr), cnt + 1)); //ť�� ���� �Ÿ� + 1 �ؼ� ����
//			}
//		}
//	}
//	flag = true; //�������� �������� �ʰ� ������ �Ұ��� ǥ��
//}
//
//void solve() {
//	//���� ��ġ�� key�� ���� �Ÿ� ���
//	for (int i = 0; i < key.size(); i++)
//	{
//		bfs(p.first, p.second, key[i].first.first, key[i].first.second, 0, key[i].second);
//		//�Ұ������� -1 ���
//		if (flag)
//		{
//			cout << -1 << "\n";
//			return;
//		}
//	}
//	//key�� ������ �Ÿ� ���
//	for (int i = 0; i < key.size(); i++)
//	{
//		int sc = key[i].first.first;
//		int sr = key[i].first.second;
//		int sn = key[i].second;
//		for (int j = i + 1; j < key.size(); j++)
//		{
//			bfs(sc, sr, key[j].first.first, key[j].first.second, sn, key[j].second);
//			//�Ұ������� -1 ���
//			if (flag)
//			{
//				cout << -1 << "\n";
//				return;
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
//	cin >> N >> M;
//	int num = 1;
//
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < N; j++) {
//			cin >> map[i][j];
//			//�κ� ��� ��ġ�� ����
//			if (map[i][j] == 'S') {
//				p.first = i;
//				p.second = j;
//			}
//			//key�� �ִ� ��ġ���� ���Ϳ� ����
//			else if (map[i][j] == 'K') {
//				key.push_back(make_pair(make_pair(i, j), num));
//				num++;
//			}
//		}
//	}
//
//	solve();
//	//�Ұ����̸� ����
//	if (flag) {
//		return 0;
//	}
//	//���� ������ ����ġ�� �������� �������� ����
//	sort(edge.begin(), edge.end(), cmp);
//	make(); //�� ����� ��ǥ ����
//	int result = 0;
//	int count = 0;
//	for (int i = 0; i < edge.size(); i++) {
//		//��� ���� ���� ����� ��ǥ�� ��ġ���� ������
//		if (Union(edge[i].from, edge[i].to)) {
//			result += edge[i].weight; //���� ���� ������ ����ġ�� ����
//			count++; //������ ���� ����
//			//��� ��尡 �� �̾������� Ż��
//			if (count == key.size()) {
//				break;
//			}
//		}
//	}
//
//	cout << result << "\n";
//
//	return 0;
//}