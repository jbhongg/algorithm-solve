//#include<iostream>
//#include<algorithm>
//#include<limits.h>
//
//using namespace std;
//
//int light[100001];
//int ans = INT_MAX;
//int cnt;
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
//	
//	int N, K, B;
//
//	cin >> N >> K >> B;
//
//	//���峭 ��ȣ���� 1�� ǥ��
//	for (int i = 0; i < B; i++) {
//		int x;
//		cin >> x;
//		light[x] = 1;
//	}
//
//	//1�� ��ȣ�� ���� K�� ��ȣ�� ������ ���峭 ��ȣ�� ���� ����
//	for (int i = 1; i <= K; i++) {
//		cnt = cnt + light[i];
//	}
//
//	int idx = 1;
//	//K+1�� ��ȣ����� �ϳ��� ���峭 ��ȣ�� ���� �����ְ� 1�� ��ȣ�� ���� ���ʷ� ���峭 ��ȣ�� ���� ����
//	for (int i = K+1; i <= N; i++) {
//		cnt = cnt + light[i];
//		cnt = cnt - light[idx];
//		idx++;
//		ans = min(ans, cnt);
//	}
//
//	cout << ans << "\n";
//
//	return 0;
//}