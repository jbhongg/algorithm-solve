//#include<iostream>
//#include<vector>
//#include<algorithm>
//#include<queue>
//
//using namespace std;
//
//bool visit[201][201][201];
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
//
//	vector <int> answer;
//	queue < pair <pair <int, int>, int>> q;
//	int A, B, C;
//
//	cin >> A >> B >> C;
//
//	q.push(make_pair(make_pair(0, 0), C));
//
//	while (!q.empty()) {
//		int a = q.front().first.first;
//		int b = q.front().first.second;
//		int c = q.front().second;
//		q.pop();
//
//		if (visit[a][b][c]) {
//			continue;
//		}
//
//		visit[a][b][c] = true;
//
//		if (a == 0) {
//			answer.push_back(c);
//		}
//
//		if (c + a - A > 0) {
//			q.push(make_pair(make_pair(A, b), c + a - A));
//		}
//		else {
//			q.push(make_pair(make_pair(c + a, b), 0));
//		}
//
//		if (c + b - B > 0) {
//			q.push(make_pair(make_pair(a, B), c + b - B));
//		}
//		else {
//			q.push(make_pair(make_pair(a, b + c), 0));
//		}
//
//		if (a + b - B > 0) {
//			q.push(make_pair(make_pair(a + b - B, B), c));
//		}
//		else {
//			q.push(make_pair(make_pair(0, a + b), c));
//		}
//
//		if (a + c - C > 0) {
//			q.push(make_pair(make_pair(a + c - C, b), C));
//		}
//		else {
//			q.push(make_pair(make_pair(0, b), a + c));
//		}
//
//		if (b + a - A > 0) {
//			q.push(make_pair(make_pair(A, b + a - A), c));
//		}
//		else {
//			q.push(make_pair(make_pair(b + a, 0), c));
//		}
//
//		if (b + c - C > 0) {
//			q.push(make_pair(make_pair(a, b + c - C), C));
//		}
//		else {
//			q.push(make_pair(make_pair(a, 0), b + c));
//		}
//	}
//
//	sort(answer.begin(), answer.end());
//
//	for (int i = 0; i < answer.size(); i++) {
//		cout << answer.at(i) << " ";
//	}
//	cout << "\n";
//
//	return 0;
//}