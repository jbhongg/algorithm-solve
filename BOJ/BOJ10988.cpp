//#include<iostream>
//#include<string>
//
//using namespace std;
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
//
//	string s; 
//
//	cin >> s;
//	//�Է°��� �ѱ��� �϶�
//	if (s.length() == 1) {
//		cout << 1 << '\n';
//		goto L;
//	}
//	//���� ��
//	for (int i = 0; i < (s.length() / 2); i++) {
//		if (s.at(0+i) != s.at(s.length() - 1-i)) {
//			cout << 0 << '\n';
//			break;
//		}
//		if (i == ((s.length() / 2) - 1)) {
//			cout << 1 << '\n';
//		}
//	}
//
//	L : return 0;
//}