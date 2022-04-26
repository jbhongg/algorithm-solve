#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>

using namespace std;

long long N, K, M;
vector <int> v1;
vector <int> v2;
long long fac[2001];

//pow 함수 만들기
long long self_pow(long long x, long long y) {
	long long res = 1;
	x = x % M;

	while (y > 0) {
		if (y % 2 == 1) {
			res = (res * x) % M;
		}
		y >>= 1;
		x = (x * x) % M;
	}
	return res;
}

long long solve(int n, int r) {
	if (r == 0) {
		return 1;
	}
	if (n < r) {
		return 0;
	}
	fac[0] = 1;
	for (long long i = 1; i <= n; i++) {
		fac[i] = fac[i - 1] * i % M;
	}

	//페르마의 소정리
	return (fac[n] * self_pow(fac[n - r], M - 2) % M * self_pow(fac[r], M - 2) % M) % M;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> K >> M;

	int answer = 1;
	while (N != 0 || K!=0) {
		answer = answer * solve(N % M, K % M) % M;
		N /= M;
		K /= M;
	}

	cout << answer << "\n";

	return 0;
}