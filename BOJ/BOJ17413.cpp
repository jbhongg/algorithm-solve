//#include<iostream>
//#include<string>
//#include<queue>
//
//using namespace std;
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
//
//	string s;
//	char a; 
//	int idx = 0; // �κ� ���ڿ��� �������� �����ϴ� ����
//	queue <pair <int, int>> q;
//
//	getline(cin, s);
//
//	//����� Ư�������� ��ġ�� ����
//	for (int i = 0; i < s.length(); i++) {
//		if (s[i] == '<') {
//			q.push(make_pair(i, 1));
//		}
//		else if (s[i] == '>') {
//			q.push(make_pair(i, 2));
//		}
//		else if (s[i] == ' ') {
//			q.push(make_pair(i, 3));
//		}
//	}
//
//	//<ab cd>fe hg<ij kl>
//	//one1 two2 three3 4fourr 5five 6six
//
//	//�������� �����̳� Ư�����ڷ� ������ �ʴ� ��� �Ǹ������� ������ �߰�
//	if (q.size() == 0 || q.back().first != (s.length()-1)) {
//		q.push(make_pair(s.length(), 3));
//	}
//
//
//	while (!q.empty()) {
//		//�ܾ�� ������� �ϴ°��
//		if (q.front().first != idx) {
//			//�ܾ ������ �ڵ�
//			for (int i = 0; i < ((q.front().first-idx)/2); i++) {
//				a = s[idx + i];
//				s[idx + i] = s[(q.front().first - 1) - i];
//				s[(q.front().first - 1) - i] = a;
//			}
//			//�ܾ� ������ Ư�� ���ڰ� ���� ���
//			if (q.front().second == 1) {
//				goto L;
//			} 
//			idx = q.front().first + 1;
//			q.pop();
//		}
//		//�±��� ��� '>'�� ���ö����� Ž��
//		else {
//			if (q.front().second == 1) {
//				L:q.pop();
//				while (!q.empty()) {
//					//'>'�� ������ ���� �κ� ���ڿ��� �������� ����
//					if (q.front().second == 2) {
//						idx = (q.front().first) + 1;
//						q.pop();
//						break;
//					}
//					q.pop();
//				}
//			}
//		}
//	}
//
//	cout << s << '\n';
//
//	return 0;
//}