#include<iostream>

using namespace std;

int N;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	int answer = 0;
	int change = 1000 - N;

	answer += (change / 500);
	change %= 500;
	answer += (change / 100);
	change %= 100;
	answer += (change / 50);
	change %= 50;
	answer += (change / 10);
	change %= 10;
	answer += (change / 5);
	change %= 5;
	answer += change;

	cout << answer << "\n";

	return 0;
}