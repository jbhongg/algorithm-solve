//#include<iostream>
//#include<string>
//
//using namespace std;
//
//bool check[988]; //������ ���� �Ǻ��ϱ� ���� �迭
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
//
//	int N, num, strike, ball;
//	fill_n(check, 988, true); //boolean �迭 true�� �ʱ�ȭ
//
//	cin >> N;
//
//	for (int i = 0; i < N; i++) {
//		cin >> num >> strike >> ball;
//		string talk = to_string(num); //�Է� ���� ���� ���ڿ��� ��ȯ 
//		//123~987 ���� Ž��
//		for (int j = 123; j <= 987; j++) {
//			string answer = to_string(j); //Ž���� ���� ���ڿ��� ��ȯ
//			//���� ���ڰ� �ְų� 0�� �� �ִ� ���� Ž�� x
//			if (answer[0] != answer[1] && answer[0] != answer[2] && answer[1] != answer[2] && answer[0] != '0' && answer[1] != '0' && answer[2] != '0') {
//				int count_s = 0, count_b = 0; //�Է� ���� ���ڿ� Ž���� ���� ������ ��Ʈ����ũ�� ���� ������ ���� ���� ����
//				for (int k = 0; k < 3; k++) {
//					for (int r = 0; r < 3; r++) {
//						//���� �ڸ��ε� ���� �����̸� ��Ʈ����ũ ���� ����
//						if (k == r && answer[k] == talk[r]) {
//							count_s++;
//						}
//						//�ٸ� �ڸ��ε� ���� �����̸� �� ���� ����
//						else if (k != r && answer[k] == talk[r]) {
//							count_b++;
//						}
//					}
//				}
//				//�Է¹��� ��Ʈ����ũ�� ���� ������ �ٸ��� �ش� ���� ���� �� �� �����Ƿ� �ش� �迭 false�� ��ȯ
//				if (count_s != strike || count_b != ball) {
//					check[j] = false;
//				}
//			}
//			else {
//				check[j] = false; //���� �� �� ���� �� �̹Ƿ� �ش� �迭 false�� ��ȯ
//			}
//		}
//	}
//
//	int answer = 0;
//
//	//true�� ���� ������ ���� ���
//	for (int i = 123; i <= 987; i++) {
//		if (check[i]) {
//			answer++;
//		}
//	}
//
//	cout << answer << '\n';
//
//	return 0;
//}