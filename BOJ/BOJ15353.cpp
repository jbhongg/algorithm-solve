//#include<iostream>
//#include <string>
//#include<algorithm>
//
//using namespace std;
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
//
//	int num, next = 0;
//	string A, B, answer = "";
//
//	cin >> A >> B;
//
//	reverse(A.begin(), A.end()); //�ڸ����� ���߱� ���� ��������
//	reverse(B.begin(), B.end()); //�ڸ����� ���߱� ���� ��������
//
//	int a_len = A.length(); 
//	int b_len = B.length();
//
//	//B�� A���� ũ��
//	if (A.length() < B.length()) {
//		for (int i = 0; i < (b_len - a_len); i++) {
//			A += '0'; //A�� �ڿ� 0�� ����
//		}
//	}
//	//A�� B���� ũ��
//	else if (A.length() > B.length()) {
//		for (int i = 0; i < (a_len - b_len); i++) {
//			B += '0'; //B�� �ڿ� 0�� ����
//		}
//	}
//
//	for (int i = 0; i < A.length(); i++) {
//		num = (A[i] - '0' + B[i] - '0' + next) % 10; //��� 
//		answer += to_string(num); //����� ���� �� ��Ʈ���� �־���
//		next = (A[i] - '0' + B[i] - '0' + next) / 10; //�ڸ� �ø��� ����
//	}
//
//	//�ڸ� �ø����� ����������
//	if (next != 0) {
//		answer += to_string(next); //�ڸ��ø����� �ٿ���
//	}
//
//	reverse(answer.begin(), answer.end()); //�ٽ� ��Ʈ���� ��������
//
//	cout << answer << "\n";
//	
//	return 0;
//}