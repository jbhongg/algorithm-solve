//#include<iostream>
//
//using namespace std;
//
//int n[5000];
//int dp[5000];
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
//
//	string s;
//
//	cin >> s;
//
//	for (int i = 1; i <= s.length(); i++) {
//		n[i] = s[i-1] - '0'; //�Է¹��� ���ڿ��� ���ڷ� �ٲ� �迭�� ����
//	}
//
//    dp[0] = 1;
//    for (int i = 1; i <= s.length(); i++)
//    {
//        //0�� �ƴϸ�(���ڸ�)
//        if (n[i] != 0)
//        {
//            dp[i] = dp[i - 1] % 1000000; //���������� ������ ���� ����
//        }
//
//        int temp = n[i] + (n[i - 1] * 10); //���ڸ��� ����
//
//        //���ڸ� ���� 10�̻� 26���ϸ�
//        if (temp >= 10 && temp <= 26)
//        {
//            dp[i] = (dp[i - 2] + dp[i]) % 1000000; //���� ���� ��ĭ �������� ��ȣ ������ �����ָ� ��
//        }
//    }
//
//    cout << dp[s.length()] << "\n";
//
//	return 0;
//}