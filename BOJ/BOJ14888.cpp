//#include<iostream>
//#include<algorithm>
//#include<limits.h>
//
//using namespace std;
//
//int num[101]; //숫자 저장
//int op[4]; //연산자 갯수 저장
//int n;
//int maxn = INT_MIN;
//int minn = INT_MAX;
//
//void solve(int plus, int minus, int mul, int div, int k, int sum) {
//	//각 연산자별로 각각의 입력받은 갯수 보다 수가 많아지면 종료
//	if (op[0] < plus || op[1] < minus || op[2] < mul || op[3] < div) {
//		return;
//	}
//	//연산자를 입력받은 숫자들 사이 갯수 만큼 조합하였으면
//	if (k == n) {
//		//최댓값, 최솟값 저장 후 종료
//		maxn = max(maxn, sum);
//		minn = min(minn, sum);
//		return;
//	}
//	//연산자를 재귀를 통해 조합, 연산자를 추가할 때 마다 연산한 값을 넘겨줌
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