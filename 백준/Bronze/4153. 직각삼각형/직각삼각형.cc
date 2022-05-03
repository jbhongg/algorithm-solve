#include<iostream>

using namespace std;

int A, B, C;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	while (true) {
		cin >> A >> B >> C;
		if (A == 0 && B == 0 && C == 0) {
			break;
		}
		int A2 = A * A;
		int B2 = B * B;
		int C2 = C * C;

		if (((A2 + B2) == C2) || ((A2 + C2) == B2) || ((B2 + C2) == A2)) {
			cout << "right\n";
		}
		else {
			cout << "wrong\n";
		}
	}

	return 0;
}