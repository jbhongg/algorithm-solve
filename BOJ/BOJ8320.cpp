//#include<iostream>
//
//using namespace std;
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
//
//	int n;
//	int cnt = 0;
//
//	cin >> n;
//
//	//1. �� ���� ������ �������� ���������� ������������
//
//	//2. ���� ����    3. ������ ������
//	//   ���� ����       ������ ������
//	//        ����       ������ ������
//	//                          ������
//	for (int i = 1; i <= n; i++) {
//		for (int j = i; i * j <= n; j++) {
//			cnt++;
//		}
//	}
//
//	cout << cnt <<'\n';
//
//	return 0;
//}