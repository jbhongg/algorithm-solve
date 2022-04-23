#include<iostream>
#include<math.h>

using namespace std;

int N, W, H;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> W >> H;

	for (int i = 0; i < N; i++) {
		int len;
		cin >> len;

		double cal = sqrt((W * W) + (H * H));

		if (len <= W || len <= H || len <= cal) {
			cout << "DA" << "\n";
		}
		else {
			cout << "NE" << "\n";
		}
	}


	return 0;
}