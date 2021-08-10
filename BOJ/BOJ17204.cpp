//#include<iostream>
//#include<vector>
//
//using namespace std;
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
//
//	int N, K, a, answer = 0;
//	vector <int> v;
//
//	cin >> N >> K;
//	for (int i = 0; i < N; i++) {
//		cin >> a;
//		v.push_back(a);
//	}
//	int i = 0;
//
//	while (true) {
//		answer++;
//		i = v.at(i); //i는 현재 사람이 가르킨 번호
//	    //i가 K(보성이의 번호)와 같으면 종료
//		if (i == K) {
//			break;
//		}
//		//참여 사람만큼 순서가 돌았는데 보성의 번호가 나오지 않았다면 보성이가 걸릴 수 없음
//		else if (answer >= N) {
//			answer = -1;
//			break;
//		}
//	}
//
//	cout << answer << "\n";
//	return 0;
//}