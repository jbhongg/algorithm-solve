//#include<iostream>
//#include<math.h>
//#include<vector>
//
//using namespace std;
//
//int last, K, node;
//int num[1024]; //방문한 노드 저장
//vector <int> v[11]; //레벨별 노드를 저장하기 위한 벡터
//
//void solve(int s, int e, int l) { //시작, 끝, 레벨
//	//노드 시작이 끝보다 크면 종료
//	if (s > e) {
//		return;
//	}
//	//시작과 끝이 같으면 마지막 노드이므로 저장하고 종료
//	if (s == e) {
//		v[l].push_back(num[s]);
//		return;
//	}
//	//중간노드 저장
//	int mid = (s + e) / 2;
//	v[l].push_back(num[mid]);
//	//트리의 왼쪽
//	solve(s, mid - 1, l + 1);
//	//트리의 오른쪽
//	solve(mid + 1, e, l+1);
//}
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
//
//	cin >> K;
//	
//	last = pow(2, K) - 1; //노드의 갯수 -> 마지막 노드의 번호
//
//	for (int i = 0; i < last; i++) {
//		cin >> num[i];
//	}
//
//	solve(0,last,1);
//
//	for (int i = 1; i <= K; i++) {
//		for (int j = 0; j < v[i].size(); j++) {
//			cout << v[i][j] << " ";
//		}
//		cout << "\n";
//	}
//	
//	return 0;
//}