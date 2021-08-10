//#include<iostream>
//#include<vector>
//#include<algorithm>
//
//using namespace std;
//
//bool cmp(pair <int, pair <int, int> > p1, pair <int, pair <int, int> > p2) {
//	return p1.second.second < p2.second.second;
//}
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
//
//	int N;
//	vector <pair <int, pair <int, int> > > room;
//	vector <int> answer;
//
//	cin >> N;
//
//	for (int i = 0; i < N; i++) {
//		int num, start, end;
//
//		cin >> num >> start >> end;
//		room.push_back(make_pair(num, make_pair(start, end)));
//	}
//
//	sort(room.begin(), room.end(), cmp); //종료시간을 기준으로 오름차순 정렬
//	
//	int idx = 0; //맨 처음 회의의 index 번호
//	answer.push_back(room.at(0).first); //맨 처음 회의를 넣어줌
//	for (int i = 1; i < N; i++) {
//		//앞 회의의 종료시간과 같거나 큰 시작시간을 가졌으면
//		if (room.at(idx).second.second <= room.at(i).second.first) {
//			answer.push_back(room.at(i).first); //회의의 번호를 넣어줌
//			idx = i; //회의의 인덱스 번호를 저장
//		}
//	}
//
//	cout << answer.size() << "\n";
//
//	for (int i = 0; i < answer.size(); i++) {
//		cout << answer.at(i) << " ";
//	}
//	cout << "\n";
//	return 0;
//}