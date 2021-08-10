//#include<iostream>
//#include<vector>
//
//using namespace std;
//
//int N, P, E;
//bool flag = false;
//vector < pair <int, int> > v;
//vector <int> sel;
//int answer[20];
//
//void solve(int idx) {
//	//한번이라도 줄수 있으면 종료
//	if (flag) {
//		return;
//	}
//	//다뽑았으면
//	if (sel.size() == P) {
//		int minn = 0, maxn = 0;
//		for (int i = 0; i < P; i++) {
//			minn = v[sel[i]].first + minn; //현재 조합된 사람들의 x값을 더함
//			maxn = v[sel[i]].second + maxn; //현재 조합된 사람들의 y값을 더함
//		}
//		int n = E - minn;
//		//현재 조합된 사람들의 x값과 y값 사이에 E가 있으면 줄 수 있음
//		if (E >= minn && E <= maxn) {
//			//일단 각각 최솟값 만큼 배분하고 나머지 값을 배분
//			for (int i = 0; i < P; i++) {
//				answer[sel[i]] = v[sel[i]].first;
//				while (true) {
//					if (n == 0) {
//						break;
//					}
//					if (answer[sel[i]] == v[sel[i]].second) {
//						break;
//					}
//					else {
//						answer[sel[i]]++;
//						n--;
//					}
//
//				}
//			}
//			flag = true;
//		}
//		else {
//			return;
//		}
//	}
//
//	//조합
//	for (int i = idx; i < N; i++) {
//		sel.push_back(i);
//		solve(i + 1);
//		sel.pop_back();
//	}
//}
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
//	
//	cin >> N >> P >> E;
//
//	for (int i = 0; i < N; i++) {
//		int x, y;
//		cin >> x >> y;
//		v.push_back(make_pair(x, y));
//	}
//	
//	solve(0);
//
//	if (!flag) {
//		cout << -1 << "\n";
//	}
//	else {
//		for (int i = 0; i < N; i++) {
//			cout << answer[i] << " ";
//		}
//		cout << "\n";
//	}
//
//	return 0;
//}