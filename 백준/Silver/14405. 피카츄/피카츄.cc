#include<iostream>

using namespace std;

string s;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> s;

	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 'p') {
			if (i == s.size()-1) {
				cout << "NO" << "\n";
				break;
			}
			else {
				if (s[i + 1] != 'i') {
					cout << "NO" << "\n";
					break;
				}
				i++;
			}
		}
		else if (s[i] == 'k') {
			if (i == s.size() - 1) {
				cout << "NO" << "\n";
				break;
			}
			else {
				if (s[i + 1] != 'a') {
					cout << "NO" << "\n";
					break;
				}
				i++;
			}
		}
		else if (s[i] == 'c') {
			if (i == s.size() - 2) {
				cout << "NO" << "\n";
				break;
			}
			else {
				if (s[i + 1] != 'h' || s[i+2] != 'u') {
					cout << "NO" << "\n";
					break;
				}
				i= i+2;
			}

		}
		else {
			cout << "NO" << "\n";
			break;
		}
		if (i == s.size() - 1) {
			cout << "YES" << "\n";
			break;
		}
	}

	return 0;
}