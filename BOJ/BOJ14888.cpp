//#include<iostream>
//#include<algorithm>
//#include<limits.h>
//
//using namespace std;
//
//int num[101]; //���� ����
//int op[4]; //������ ���� ����
//int n;
//int maxn = INT_MIN;
//int minn = INT_MAX;
//
//void solve(int plus, int minus, int mul, int div, int k, int sum) {
//	//�� �����ں��� ������ �Է¹��� ���� ���� ���� �������� ����
//	if (op[0] < plus || op[1] < minus || op[2] < mul || op[3] < div) {
//		return;
//	}
//	//�����ڸ� �Է¹��� ���ڵ� ���� ���� ��ŭ �����Ͽ�����
//	if (k == n) {
//		//�ִ�, �ּڰ� ���� �� ����
//		maxn = max(maxn, sum);
//		minn = min(minn, sum);
//		return;
//	}
//	//�����ڸ� ��͸� ���� ����, �����ڸ� �߰��� �� ���� ������ ���� �Ѱ���
//	solve(plus + 1, minus, mul, div, k + 1,sum + num[k]);
//	solve(plus, minus + 1, mul, div, k + 1,sum - num[k]);
//	solve(plus, minus, mul+1, div, k + 1, sum * num[k]);
//	solve(plus, minus, mul, div+1, k + 1, sum / num[k]);
//}
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
//
//	cin >> n;
//
//	for (int i = 0; i < n; i++) {
//		cin >> num[i];
//	}
//
//	for (int i = 0; i < 4; i++) {
//		cin >> op[i];
//	}
//
//	solve(0,0,0,0,1,num[0]);
//
//	cout << maxn << '\n' << minn << '\n';
//	return 0;
//}