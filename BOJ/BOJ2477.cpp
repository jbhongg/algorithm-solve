//#include<iostream>
//
//using namespace std;
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
//	
//	int K, answer = 0;
//	bool flag = false;
//	pair<int, int> p[6];
//	cin >> K;
//	for (int i = 0; i < 6; i++) {
//		cin >> p[i].first >> p[i].second;
//	}
//	for (int i = 0; i < 3; i++) {
//		//현재 위치와 다다음 위치와의 방향이 같고 다음 위치와 다다다음 위치의 방향이 같다면
//		if (p[i].first == p[i + 2].first && p[i+1].first == p[i+3].first) {
//			//밑의 식이 성립됨
//			answer = ((p[i].second + p[i + 2].second) * (p[i + 1].second + p[i + 3].second)) - (p[i + 1].second * p[i + 2].second);
//			flag = true;
//			break;
//		}
//	}
//
//	//위의 경우에 맞다면 답 출력
//	if (flag) {
//		cout << answer*K << "\n";
//	}
//	//위의 경우가 아니면 3가지 경우로 나뉘어짐 그에 맞는 계산식을 세움
//	else {
//		if (p[0].first == p[2].first) {
//			answer = ((p[0].second + p[2].second) * (p[1].second + p[5].second)) - (p[0].second * p[1].second);
//			cout << answer* K << "\n";
//		}
//		else if(p[0].first == p[4].first && p[1].first == p[5].first){
//			answer = ((p[0].second + p[4].second) * (p[1].second + p[5].second)) - (p[0].second * p[5].second);
//			cout << answer* K << "\n";
//		}
//		else {
//			answer = ((p[0].second + p[4].second) * (p[3].second + p[5].second)) - (p[4].second * p[5].second);
//			cout << answer * K << "\n";
//		}
//	}
//
//	return 0;
//}