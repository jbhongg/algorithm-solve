//#include<iostream>
//#include<vector>
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
//	int N, K;
//	int low = 0;
//	int high = 0;
//
//	cin >> N >> K;
//
//	for (int i = 0; i < N; i++) {
//		int num;
//		cin >> num;
//		high = high + num; //초기 최댓값은 맞은 문제 갯수의 전체 합
//		v.push_back(num);
//	}
//
//	while (low <= high) {
//		int temp = 0;
//		int cnt = 0; //나눈 그룹수
//		int mid = (low + high) / 2; //중간값 계산
//		for (int i = 0; i < v.size(); i++) {
//			temp = temp + v.at(i); //현재 그롭의 맞은 문제 갯수 합 저장
//			//만약 현재까지의 맞은 문제 갯수 합이 중간값보다 크거나 같으면 
//			if (temp >= mid) {
//				cnt++; //그룹을 나눔(그룹 수 증가) 
//				temp = 0; //다음 그룹의 맞은 문제 갯수 합을 구하기 위해 초기화
//			}
//		}
//		//그룹의 수가 K보다 크거나 같으면(최솟값이 mid보다 더 크다는 의미이므로 low값을 mid+1로 바꿔줌)
//		if (cnt >= K) {
//			low = mid+1;
//		}
//		//그룹의 수가 K보다 작으면(최솟값이 mid보다 더 작다는 의미이므로 high값을 mid-1로 바꿔줌)
//		else {
//			high = mid - 1;
//		}
//	}
//
//	cout << high << "\n";
//	
//	return 0;
//}