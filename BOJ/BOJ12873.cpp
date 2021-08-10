//#include<iostream>
//#include<queue>
//
//using namespace std;
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
//
//	int N;
//	queue <int> q; //번호를 저장할 큐
//
//	cin >> N;
//
//	//큐에 1부터 N까지 번호 순서대로 저장
//	for (int i = 1; i <= N; i++) {
//		q.push(i);
//	}
//
//	long long count = 1; //num^3은 int형을 넘어가므로 long long형을 사용
//	long long num = 1;
//
//	//큐에 값이 하나만 있을때까지 반복
//	while (q.size() != 1) {
//		//큐의 크기만큼 돌면 원상복귀이므로 큐의 크기로 나눈 나머지 값만큼 반복 진행하며 현재 사람을 큐의 맨뒤로 보냄
//		for (int i = 1; i <= ((count-1)%q.size()); i++) {
//			int temp = q.front();
//			q.push(temp);
//			q.pop();
//		}
//		//큐의 맨앞 삭제
//		q.pop();
//		num++;
//		count = num * num * num;
//	}
//	cout << q.front() << '\n';
//
//	return 0;
//}