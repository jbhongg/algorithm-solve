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
//		n[i] = s[i-1] - '0'; //입력받은 문자열을 숫자로 바꿔 배열에 저장
//	}
//
//    dp[0] = 1;
//    for (int i = 1; i <= s.length(); i++)
//    {
//        //0이 아니면(한자리)
//        if (n[i] != 0)
//        {
//            dp[i] = dp[i - 1] % 1000000; //이전까지의 갯수가 현재 갯수
//        }
//
//        int temp = n[i] + (n[i - 1] * 10); //두자리로 보기
//
//        //두자리 수가 10이상 26이하면
//        if (temp >= 10 && temp <= 26)
//        {
//            dp[i] = (dp[i - 2] + dp[i]) % 1000000; //현재 값에 두칸 전까지의 암호 갯수를 더해주면 값
//        }
//    }
//
//    cout << dp[s.length()] << "\n";
//
//	return 0;
//}