//#include<iostream>
//#include<algorithm>
//#include<vector>
//
//using namespace std;
//
//char vowel[5] = { 'a', 'e', 'i', 'o', 'u' };
//char c[15];
//vector <char> v;
//int L, C;
//
//void print() {
//	for (int i = 0; i < L; i++) {
//		cout << v[i];
//	}
//	cout << "\n";
//}
//
//bool check() {
//	int count = 0;
//	//���� ���� ����
//	for (int i = 0; i < L; i++) {
//		for (int j = 0; j < 5; j++) {
//			if (v[i] == vowel[j]) {
//				count++;
//			}
//		}
//	}
//	//���������� 0���̰ų� L-1�� �̻�(������ 2�� �̸��̶�� ��)�̸�
//	if (count == 0 || count >= L - 1) {
//		return false; //false ��ȯ
//	}
//	return true;
//}
//
//void solve(int k, int idx) {
//	//�ٻ̾�����
//	if (k == L) {
//		//���� ���� ���� Ȯ��
//		//�������ϸ�
//		if (!check()) {
//			return;
//		}
//		//�����ϸ� ���
//		else {
//			print();
//		}
//		return;
//	}
//
//	//����
//	for (int i = idx; i < C; i++){
//		v.push_back(c[i]);
//		solve(k + 1, i+1);
//		v.pop_back();
//	}
//}
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
//
//	cin >> L >> C;
//
//	for (int i = 0; i < C; i++) {
//		cin >> c[i];
//	}
//
//	sort(c, c+C); //�������� ����
//	solve(0,0);
//
//	return 0;
//}