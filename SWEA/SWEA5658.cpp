//#include<iostream>
//#include<deque>
//#include<vector>
//#include<algorithm>
//
//using namespace std;
//
//deque <char> d; //���ڿ��� ���� �ϳ��� ����
//vector <string> v; //���ڸ� ���ļ� �����ϴ� ����
//vector <int> v2; //������ 16���� ���ڸ� 10������ �ٲپ� ����
//int N;
//
////�������� ����
//bool cmp(int a, int b) {
//	return a > b;
//}
//
//
//void change() {
//	for (int i = 0; i < v.size(); i++) {
//		v2.push_back(strtol(v.at(i).c_str(), NULL, 16));
//	}
//}
//
////���������� ��й�ȣ�� �����ϴ� �Լ�
//void check() {
//	string temp;
//	for (int i = 0; i <= N; i++) {
//		if (i != 0 && i % (N / 4) == 0) {
//			v.push_back(temp);
//			temp.clear();
//			if (i == N) {
//				return;
//			}
//		}
//		temp.push_back(d.at(i));
//	}
//
//}
//
////��ĭ�� ȸ���ϴ� �Լ�
//void rotate() {
//	char c = d.back();
//	d.pop_back();
//	d.push_front(c);
//}
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
//
//	int test_case, T;
//	cin >> T;
//
//	for (test_case = 1; test_case <= T; ++test_case)
//	{
//		//�ʱ�ȭ
//		d.clear();
//		v.clear();
//		v2.clear();
//		int K;
//		cin >> N >> K;
//		string s;
//		cin >> s;
//		for (int i = 0; i < s.length(); i++) {
//			d.push_back(s[i]); //�Է¹��� ���ڿ��� �����ϳ��� ����
//		}
//		check();
//		for (int i = 1; i < N / 4; i++) {
//			rotate();
//			check();
//		}
//
//		//�ߺ��Ǵ� ��й�ȣ�� ����
//		sort(v.begin(), v.end());
//		v.erase(unique(v.begin(), v.end()), v.end());
//
//		//16���� ���ڸ� 10������ �ٲ�
//		change();
//
//		//�������� ����
//		sort(v2.begin(), v2.end(), cmp);
//
//		cout << "#" << test_case << " " << v2[K - 1] << "\n";
//	}
//
//	return 0;
//}