//#include<iostream>
//#include<vector>
//#include<queue>
//#include<limits.h>
//#include<algorithm>
//
//using namespace std;
//
//vector <int> v[101];
//vector <int> answer;
//int ans[2];
//int dist[101][101];
//int N, M;
//int dis = INT_MAX;
//
//void bfs(int idx) {
//	queue < pair <int, int> > q;
//	q.push(make_pair(idx,0));
//	while (!q.empty()) {
//		int n = q.front().first;
//		int cnt = q.front().second;
//		q.pop();
//		for (int i = 0; i < v[n].size(); i++) {
//			int nn = v[n][i];
//			if (nn !=idx && dist[idx][nn] == 0) {
//				q.push(make_pair(nn, cnt + 1));
//				dist[idx][nn] = cnt+1; //��� ������ �Ÿ� ����
//			}
//		}
//	}
//}
//
//void solve(int idx) {
//	//�� �̾�����
//	if (answer.size() == 2) {
//		int cnt = 0;
//		//���� ��忡�� ����� ġŲ�������� �Ÿ��� ��� ��忡���� �Ÿ� ���
//		for (int i = 1; i <= N; i++) {
//			cnt += min(dist[answer[0]][i], dist[answer[1]][i]);
//		}
//		//��� ��忡���� �պ� �Ÿ��� ������
//		if ((cnt*2) == dis) {
//			//�ǹ� ��ȣ �� ���� �� �� ���� ���� ����
//			if (ans[0] > answer[0]) {
//				ans[0] = answer[0];
//				ans[1] = answer[1];
//			}
//			//�ǹ� ��ȣ �� ���� �͵� ������
//			else if (ans[0] == answer[0]) {
//				//ū ��ȣ�� �� ���� �� ����
//				if (ans[1] > answer[1]) {
//					ans[0] = answer[0];
//					ans[1] = answer[1];
//				}
//			}
//		}
//		//��� ��忡���� �պ� �Ÿ��� �� ���� �� ����
//		else if((cnt * 2) < dis){
//			dis = cnt * 2;
//			ans[0] = answer[0];
//			ans[1] = answer[1];
//		}
//		return;
//	}
//
//	//����(ġŲ���� �� �ǹ� �̱�)
//	for (int i = idx; i <= N; i++) {
//		answer.push_back(i);
//		solve(i + 1);
//		answer.pop_back();
//	}
//}
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
//	
//	cin >> N >> M;
//
//	//���� ����Ʈ �����
//	for (int i = 0; i < M; i++) {
//		int A, B;
//		cin >> A >> B;
//		v[A].push_back(B);
//		v[B].push_back(A);
//	}
//	//�� ��忡�� �ٸ� �������� �Ÿ� ���ϱ�
//	for (int i = 1; i <= N; i++) {
//		bfs(i);
//	}
//	solve(1);
//
//	cout << ans[0] << " " << ans[1] << " " << dis << "\n";
//	 
//	return 0;
//}