//#include<iostream>
//
//using namespace std;
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
//
//	int test_case, T;
//	cin >> T;
//
//	for (test_case = 1; test_case <= T; ++test_case)
//	{
//		string s;
//		int N, sum = 0, w = 0;
//		cin >> N;
//		for (int i = 0; i < N; i++) {
//			cin >> s;
//			//�� ���� ����� ���� �׻� ����
//			sum = sum + s[N / 2] - '0';
//			for (int j = 1; j <= w; j++) {
//				sum = sum + (s[N / 2 - j] - '0') + (s[N / 2 + j] - '0');
//			}
//			//�ٽ� ���ԵǴ� ���� �������� �ϳ��� �پ��� �κ�
//			if (i >= N / 2) {
//				w--;
//			}
//			//���ԵǴ� ���� �������� �ϳ��� �þ� ���� �κ�
//			else {
//				w++;
//			}
//		}
//
//		cout << "#" << test_case << " " << sum << "\n";
//	}
//
//	return 0;
//}