//#include<iostream>
//#include<algorithm>
//
//using namespace std;
//
//long long X[1000001];
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
//
//	long long N, K, ans;
//
//	cin >> N >> K;
//
//	for (int i = 0; i < N; i++) {
//		cin >> X[i];
//	}
//	sort(X, X+N);
//	while (true) {
//		long long minn = X[0]; //���� �ּڰ�
//		long long count = upper_bound(X, X+N, minn) - X; //���� �ּڰ��� ���� �� ����
//		long long diff = X[count] - minn; //�ּڰ� ���� ���� �ּڰ��� ����
//
//		//��δ� ���� �����
//		if (count == N)
//		{
//			ans = minn + (K / count); //���� ���
//			break;
//		}
//
//		//������ ��ų �� ������
//		if (diff * count <= K)
//		{
//			X[0] = X[0] + diff; //�ּڰ��� �ٲ���
//			K = K - (diff * count); //������ ��Ų ��ŭ K������ ����
//		}
//		//������ ��ų �� ������
//		else
//		{ 
//			ans = minn + (K / count); //���� ���
//			break;
//		}
//	}
//	
//	cout << ans << "\n";
//
//	return 0;
//}