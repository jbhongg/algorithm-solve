//#include<iostream>
//#include<string>
//
//using namespace std;
//char temp[1000001];
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
//
//	string s, bomb;
//	int idx = 0;
//	cin >> s >> bomb;
//	//���� ���ڿ��� ��Ÿ���ڿ��� �ϳ��� ������ ���� ���ڿ� ��� �� ����
//	if (s.find(bomb) == -1) {
//		cout << s << "\n";
//		return 0;
//	}
//	else {
//		for (int i = 0; i < s.length(); i++) {
//			temp[idx] = s[i]; //���ڿ��� ������� ����
//			//������ ���� ��Ÿ ���ڿ��� ������ ���� ������
//			if (temp[idx] == bomb[bomb.length() - 1]) {
//				//���� ����� ���ڿ��� ���̰� ��ź ���ڿ��� ���̺��� ũ�ų� ������
//				if ((idx+1) - bomb.length() >= 0) {
//					bool flag = true; //��ź ���ڿ��� �����ߴ����� �˷��ִ� flag
//					for (int j = 1; j < bomb.length(); j++) {
//						//����� ���ڿ��� ��ź ���ڿ��� �ڿ������� ���ؼ� ���� �ٸ��� 
//						if (temp[idx - j] != bomb[bomb.length() - 1 - j]) {
//							flag = false; //��ź ���ڿ��� �������� �ʾҴٰ� ǥ�� �� Ż��
//							break;
//						}
//					}
//					//���� ��ź���ڿ��� ������
//					if (flag) {
//						idx = idx - bomb.length(); //���� ���ڿ��� �ε����� ��ź ���ڿ��� ���� ��ŭ ���ɷ� �ٲپ���
//					}
//				}
//			}
//			idx++; //�ε��� ����
//		}
//	}
//	//�ε����� 0�̶�� ���ڰ� �ϳ��� ���ٴ� �ǹ��̹Ƿ� FRULA���
//	if (idx == 0) {
//		cout << "FRULA" << "\n";
//	}
//	//�ƴϸ� �ε������� ���
//	else {
//		for (int i = 0; i < idx; i++) {
//			cout << temp[i];
//		}
//		cout << "\n";
//	}
//
//	return 0;
//}