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
////현재 노드의 대표 찾기
//int find(int a) {
//	//대표가 자기자신이라면 return
//	if (parent[a] == a) {
//		return a;
//	}
//	//아니면 대표를 찾을 때 까지 재귀
//	return parent[a] = find(parent[a]);
//}
//
//bool Union(int a, int b) {
//	int aroot = find(a);
//	int broot = find(b);
//	//출발과 도착 노드의 대표가 같으면 false return
//	if (aroot == broot) {
//		return false;
//	}
//	//아니면 도착 노드의 대표를 출발노드의 대표로 변경
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
//	init(); //visit 배열 초기화
//	queue < pair <pair <int, int>, int > > q;
//	q.push(make_pair(make_pair(sc, sr), 0));
//	visit[sc][sr] = true;
//	while (!q.empty()) {
//		int c = q.front().first.first;
//		int r = q.front().first.second;
//		int cnt = q.front().second; //현재 거리
//		q.pop();
//
//		//현재 위치가 목적지라면
//		if (c == ec && r == er) {
//			Edge e;
//			e.from = sn;
//			e.to = en;
//			e.weight = cnt;
//			edge.push_back(e); //벡터에 현재 간선 정보 저장
//			return;
//		}
//		//4방 탐색
//		for (int i = 0; i < 4; i++) {
//			int nc = c + dc[i];
//			int nr = r + dr[i];
//			//탐색할 위치가 맵안에 있고 벽이 아니고 방문하지 않은 곳이라면
//			if (nc >= 0 && nr >= 0 && nc < N && nr < N && map[nc][nr] != '1' && visit[nc][nr] == false) {
//				visit[nc][nr] = true; //방문 표시
//				q.push(make_pair(make_pair(nc, nr), cnt + 1)); //큐에 현재 거리 + 1 해서 저장
//			}
//		}
//	}
//	flag = true; //목적지에 도착하지 않고 끝나면 불가능 표시
//}
//
//void solve() {
//	//시작 위치와 key들 사이 거리 계산
//	for (int i = 0; i < key.size(); i++)
//	{
//		bfs(p.first, p.second, key[i].first.first, key[i].first.second, 0, key[i].second);
//		//불가능히면 -1 출력
//		if (flag)
//		{
//			cout << -1 << "\n";
//			return;
//		}
//	}
//	//key들 사이의 거리 계산
//	for (int i = 0; i < key.size(); i++)
//	{
//		int sc = key[i].first.first;
//		int sr = key[i].first.second;
//		int sn = key[i].second;
//		for (int j = i + 1; j < key.size(); j++)
//		{
//			bfs(sc, sr, key[j].first.first, key[j].first.second, sn, key[j].second);
//			//불가능히면 -1 출력
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
//			//로봇 출발 위치를 저장
//			if (map[i][j] == 'S') {
//				p.first = i;
//				p.second = j;
//			}
//			//key가 있는 위치들을 벡터에 저장
//			else if (map[i][j] == 'K') {
//				key.push_back(make_pair(make_pair(i, j), num));
//				num++;
//			}
//		}
//	}
//
//	solve();
//	//불가능이면 종료
//	if (flag) {
//		return 0;
//	}
//	//간선 정보를 가중치를 기준으로 오름차순 정렬
//	sort(edge.begin(), edge.end(), cmp);
//	make(); //각 노드의 대표 설정
//	int result = 0;
//	int count = 0;
//	for (int i = 0; i < edge.size(); i++) {
//		//출발 노드와 도착 노드의 대표가 일치하지 않으면
//		if (Union(edge[i].from, edge[i].to)) {
//			result += edge[i].weight; //현재 간선 정보의 가중치를 더함
//			count++; //간선의 갯수 증가
//			//모든 노드가 다 이어졌으면 탈출
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