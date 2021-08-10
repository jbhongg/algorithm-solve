//#include<iostream>
//#include<vector>
//#include<limits.h>
//#include<queue>
//#include<math.h>
//
//using namespace std;
//
//long long N, M, A, B, C;
//vector < pair < long long, long long> > edge[100001];
//long long dist[100001];
//
//bool solve(long long s, long long cost) {
//	for (int i = 1; i <= N; i++) {
//		dist[i] = LONG_MAX;
//	}
//	priority_queue < pair < long long, long long>, vector< pair < long long, long long> >, greater< pair < long long, long long> > > pq;
//	pq.push(make_pair(0, s));
//	dist[s] = 0;
//	while (!pq.empty())
//	{
//		long long c = pq.top().first;
//		long long node = pq.top().second;
//		pq.pop();
//
//		if (dist[node] < c) {
//			continue;
//		}
//
//		for (long long i = 0; i < edge[node].size(); i++) {
//			long long ne = edge[node][i].first;
//			long long nc = edge[node][i].second;
//			if (cost >= nc && dist[ne] > dist[node] + nc) {
//				dist[ne] = dist[node] + nc;
//				pq.push(make_pair(dist[ne], ne));
//			}
//		}
//	}
//	if (dist[B] <= C) {
//		return true;
//	}
//	return false;
//}
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
//
//	cin >> N >> M >> A >> B >> C;
//
//	for (long long i = 0; i < M; i++) {
//		long long s, e, w;
//		cin >> s >> e >> w;
//		edge[s].push_back(make_pair(e, w));
//		edge[e].push_back(make_pair(s, w));
//	}
//	long long left = 0;
//	long long right = 1000000001;
//	while (left <= right) {
//		long long mid = (left + right) >> 1;
//		if (!solve(A, mid)) {
//			left = mid + 1;
//		}
//		else {
//			right = mid - 1;
//		}
//	}
//
//	if (right == 1000000001) {
//		right = -2;
//	}
//
//	cout << right+1 << "\n";
//	
//	return 0;
//}