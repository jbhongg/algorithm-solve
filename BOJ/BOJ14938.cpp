//#include<iostream>
//#include<vector>
//#include<limits.h>
//#include<queue>
//#include<algorithm>
//
//using namespace std;
//
//int t[101];
//vector<pair<int, int>> v[111];
//int dist[101];
//int n, m, r, answer;
//
//void solve(int s) {
//	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
//	dist[s] = 0;
//	pq.push(make_pair(0, s));
//	while (!pq.empty()) {
//		int c = pq.top().first;
//		int node = pq.top().second;
//		pq.pop();
//		for (int i = 0; i < v[node].size(); i++) {
//			int nc = v[node][i].first;
//			int nnode = v[node][i].second;
//			//���� �������� �Ÿ��� m���� ũ�� �����ϱ� ����
//			if (dist[node] + nc > m) {
//				continue;
//			}
//			//���� ��忡 ����Ǿ� �ִ� �Ÿ��� �̹� ��带 ���� ���� �Ÿ����� ũ�� 
//			if (dist[nnode] > dist[node] + nc) {
//				dist[nnode] = dist[node] + nc; // �̹� ��带 ���� ���� �Ÿ��� ����
//				pq.push(make_pair(dist[nnode], nnode)); //ť�� ����
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
//	cin >> n >> m >> r;
//
//	for (int i = 1; i <= n; i++) {
//		cin >> t[i];
//	}
//
//	//��������Ʈ �����
//	for (int i = 1; i <= r; i++) {
//		int a, b, l;
//		cin >> a >> b >> l;
//		v[a].push_back(make_pair(l, b));
//		v[b].push_back(make_pair(l, a));
//	}
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= n; j++) {
//			dist[j] = INT_MAX;
//		}
//		solve(i);
//		int item = 0;
//		for (int j = 1; j <= n; j++) {
//			//���� ������ ���� �Ÿ��� m���� �۰ų� ������
//			if (dist[j] <= m) {
//				item += t[j]; //�� ��忡 �ִ� ������ ���� ����
//			}
//		}
//		answer = max(answer, item); //������ ���� ���� �ִ��� ���� ����
//	}
//
//	cout << answer << "\n";
//	
//	return 0;
//}