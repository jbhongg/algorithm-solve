//#include<iostream>
//#include<math.h>
//#include<vector>
//
//using namespace std;
//
//int last, K, node;
//int num[1024]; //�湮�� ��� ����
//vector <int> v[11]; //������ ��带 �����ϱ� ���� ����
//
//void solve(int s, int e, int l) { //����, ��, ����
//	//��� ������ ������ ũ�� ����
//	if (s > e) {
//		return;
//	}
//	//���۰� ���� ������ ������ ����̹Ƿ� �����ϰ� ����
//	if (s == e) {
//		v[l].push_back(num[s]);
//		return;
//	}
//	//�߰���� ����
//	int mid = (s + e) / 2;
//	v[l].push_back(num[mid]);
//	//Ʈ���� ����
//	solve(s, mid - 1, l + 1);
//	//Ʈ���� ������
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
//	last = pow(2, K) - 1; //����� ���� -> ������ ����� ��ȣ
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