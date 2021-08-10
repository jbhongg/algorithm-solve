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
//	int n, w, L, a, answer = 0, sum = 0;
//
//	cin >> n >> w >> L;
//
//	queue <int> q; //다리를 큐로 만듬
//
//	for (int i = 0; i < n; i++) {
//		cin >> a;
//		while (true) {
//			//다리에 트럭이 꽉찬 경우
//			if (q.size() == w) {
//				//맨앞 트럭의 무게를 빼주고 큐에서 pop해준다
//				sum = sum - q.front();
//				q.pop();
//			}
//			//다음 트럭의 무게를 더해도 다리의 최대하중보다 작거나 같은 경우
//			if ((sum + a) <= L) {
//				break;
//			}
//			//다리에 다음 트럭이 올라올 수 경우 트럭을 이동시키는 의미로 큐에 0을 넣어준다
//			q.push(0);
//			//이동할 때 마다 count
//			answer++;
//		}
//		//다리에 올라올 트럭을 큐에 넣어준다
//		q.push(a);
//		//다리위에 있는 트럭들의 무게에 추가해준다
//		sum = sum + a;
//		//이동했으니까 count
//		answer++;
//	}
//
//	//마지막 트럭의 경우 다리 시작부분에 올라온 것만 count 했기 때문에 다리를 다 지나가는 것 까지 추가해서 출력
//	cout << (answer+w) << "\n";
//
//	return 0;
//}