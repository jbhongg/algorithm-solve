//#include<iostream>
//#include<vector>
//#include<algorithm>
//
//using namespace std;
//
//typedef struct Edge
//{
//	int from;
//	int to;
//	int wight;
//}Edge;
//
//vector <Edge> edge;
//int m, n;
//int parent[200000];
//
//void make() {
//	for (int i = 0; i < m; i++) {
//		parent[i] = i;
//	}
//}
//
////현재 노드의 대표 찾기
//int find(int a) {
//	//대표가 자기자신이라면 return
//	if (parent[a] == a) {
//		return a;
//	}
//	//아니면 대표를 찾을 때까지 재귀
//	return parent[a] = find(parent[a]);
//}
//
//bool Union(int a, int b) {
//	int aroot = find(a); //출발 노드의 대표 찾기
//	int broot = find(b); //도착 노드의 대표 찾기
//	//출발 노드와 도착 노드의 대표가 일치하면 false return
//	if (aroot == broot) {
//		return false;
//	}
//	//아니면 도착노드의 대표를 출발노드의 대표로 변경
//	parent[broot] = aroot;
//	return true;
//}
//
//bool cmp(Edge e1, Edge e2) {
//	return e1.wight < e2.wight;
//}
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
//
//	while (true) {
//		int total = 0;
//		edge.clear();
//		cin >> m >> n;
//		//입력값에 0 0이 들어오면 탈출
//		if (m == 0 && n == 0) {
//			break;
//		}
//
//		for (int i = 0; i < n; i++) {
//			Edge e;
//			cin >> e.from >> e.to >> e.wight;
//			edge.push_back(e); //간선 정보 저장
//			total += edge[i].wight; //전체 가중치의 합 저장
//		}
//		//간선 정보를 가중치를 기준으로 오름차순 정렬
//		sort(edge.begin(), edge.end(), cmp);
//		make(); //각 노드의 대표 지정
//		int result = 0;
//		int count = 0;
//
//		for (int i = 0; i < edge.size(); i++) {
//			//출발 노드와 도착 노드의 대표가 일치하지 않으면
//			if (Union(edge[i].from, edge[i].to)) {
//				result += edge[i].wight; //현재 간선 정보의 가중치를 더함
//				count++; //간선 갯수 증가
//				//모든 노드를 연결했으면 탈출
//				if (count == m - 1) {
//					break;
//				}
//			}
//		}
//
//		cout << total - result << "\n";
//	}
//
//	return 0;
//}