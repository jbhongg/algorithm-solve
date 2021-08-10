//#include<iostream>
//#include<vector>
//#include<algorithm>
//
//using namespace std;
//
//vector <int> v;
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
//
//	int N, card, joker = 0, result = 0;
//
//	cin >> N;
//
//	for (int i = 0; i < N; i++) {
//		cin >> card;
//		//조커 카드의 갯수 저장
//		if (card == 0) {
//			joker++;
//		}
//		//일반 카드만 저장
//		else {
//			v.push_back(card);
//		}
//	}
//
//	sort(v.begin(), v.end()); //일반 카드 오름차순 정렬
//
//	for (int i = 0; i < v.size(); i++) {
//		int answer = 1;
//		int temp = joker;
//		for (int j = i; j < v.size(); j++) {
//			//다음 카드 값이 인덱스를 벗어나면 종료
//			if (j + 1 >= v.size()) {
//				break;
//			}
//			//다음 카드와 현재카드가 1차이면 스트레이트 카드 갯수 더함
//			if ((v.at(j + 1) - v.at(j)) == 1) {
//				answer++;
//			}
//			//다음 카드와 현재카드가 같다면 다음 탐색
//			else if ((v.at(j + 1) - v.at(j)) == 0) {
//				continue;
//			}
//			//조커 카드가 0개 아니고 다음 카드와 현재 카드 차이가 조커 카드의 수와 같거나 작다면 스트레이트 카드 갯수에 차이를 더하고 조커 카드를 사용했으므로 사용한만큼 빼줌
//			else if (temp != 0 && ((v.at(j + 1) - v.at(j)) - 1) <= temp) {
//				temp = temp - (v.at(j + 1) - v.at(j)) + 1;
//				answer = answer + (v.at(j + 1) - v.at(j));
//			}
//			//위의 상황들이 아니면 종료
//			else {
//				break;
//			}
//		}
//		//조커 카드가 남았을 경우 그 수 만큼 더해줌
//		if (temp != 0) {
//			answer = answer + temp;
//		}
//		result = max(result, answer); //최댓값 저장
//		//최댓값이 일반카드와 조커 카드를 더한 값이라면 그보다 큰 값은 없으므로 종료
//		if (result == (v.size() + joker)) {
//			break;
//		}
//	}
//
//	//일반카드가 없는경우
//	if (v.size() == 0) {
//		result = result + joker;
//	}
//
//	cout << result << "\n";
//	
//	return 0;
//}