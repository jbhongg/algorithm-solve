//#include<iostream>
//#include<queue>
//#include<vector>
//#include<algorithm>
//
//using namespace std;
//
//int map[25][25], n, cnt; //전체 단지 수를 세기 위한 변수
//bool visit[25][25];
//int dc[4] = {-1,0,1,0};
//int dr[4] = {0,1,0,-1};
//
//queue <pair<int, int>> q;
//vector <int> v; //단지마다의 집의 수를 저장하기위한 변수
//
//void solve(int num) {
//	v.push_back(0); //함수안에 들어왔다는 것은 새로운 단지가 생긴다는 뜻이므로 벡터에 집의 수를 세기위해 추가
//	while (!q.empty()) {
//		int c = q.front().first;
//		int r = q.front().second;
//		//4방 탐색
//		for (int i = 0; i < 4; i++) {
//			int nc = c + dc[i];
//			int nr = r + dr[i];
//			//탐색할 위치가 맵 안에 있고 방문하지 않은 곳이고 값이 1이라면 방문했다고 표시하고 큐에 추가
//			if (nc >= 0 && nc < n && nr >= 0 && nr < n && visit[nc][nr] == false && map[nc][nr] == 1) {
//				visit[nc][nr] = true;
//				q.push(make_pair(nc, nr));
//			}
//		}
//		//현재 위치의 값을 num으로 바꿔줌(단지 번호)
//		map[c][r] = num;
//		v.at(num-2)++; //단지별 집의 수를 세기위해 벡터의 값 증가
//		q.pop();
//	}
//}
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
//
//	int num = 2; //단지 이름을 2부터 매겨줌
//
//	cin >> n;
//
//	for (int i = 0; i < n; i++) {
//		string s;
//		cin >> s;
//		for (int j = 0; j < s.size(); j++) {
//			map[i][j] = s[j] - '0';
//		}
//	}
//
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < n; j++) {
//			//맵에 1이 있고 방문하지 않은 곳이라면
//			if (map[i][j] == 1 && visit[i][j] == false) {
//				//방문했다고 표시하고 큐에 추가
//				visit[i][j] = true;
//				q.push(make_pair(i, j));
//				solve(num);
//				cnt++; //전체 단지 수 증가
//				num++; //다음 단지 번호를 매기기위해 값 증가
//			}
//		}
//	}
//
//	sort(v.begin(), v.end()); //정렬
//
//	cout << cnt << "\n";
//	for (int i = 0; i < v.size(); i++) {
//		cout << v[i] << "\n";
//	}
//
//  return 0;
//}