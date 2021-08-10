//#include<iostream>
//#include<vector>
//
//using namespace std;
//
//vector <pair <char, long long> > info[123456];
//vector <long long> node[123456];
//
//long long solve(int n) {
//	long long cnt = 0;
//	//dfs
//	for (int i = 0; i < node[n].size(); i++) {
//		cnt = cnt + solve(node[n][i]);
//	}
//	//현재 섬에 있는 동물이 양이면
//	if (info[n].front().first == 'S') {
//		return cnt + info[n].front().second; //현재까지의 양의 갯수에 현재 섬의 양의 갯수를 더해서 반환
//	}
//	//현재 섬에 있는 동물이 늑대이면
//	else {
//		cnt = cnt - info[n].front().second; //현재까지의 양의 갯수에서 늑대의 수를 빼기
//		//남은 양의 갯수가 음수이면 해당 섬까지의 양의 갯수를 0으로 초기화(현재 섬을 포함해서 이 섬을 거치는 섬들은 가지 않음)
//		if (cnt < 0) {
//			return 0;
//		}
//		//남은 양의 갯수가 양수이면 남은 양의 수 반환
//		else {
//			return cnt;
//		}
//	}
//}
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
//
//	int N;
//
//	cin >> N;
//
//	for (int i = 2; i <= N; i++) {
//		char t;
//		long long a, p;
//		cin >> t >> a >> p;
//		info[i].push_back(make_pair(t, a)); //각 섬의 동물의 종류와 갯수 저장
//		node[p].push_back(i); //각 섬과 연결되어 있는 섬 저장
//	}
//
//	info[1].push_back(make_pair('S', 0)); //1번 섬의 정보 저장
//
//	cout << solve(1) << "\n";
//	
//	return 0;
//}