//#include<iostream>
//#include<vector>
//#include<algorithm>
//
//using namespace std;
//
//vector <pair <int, int>> v;
//
//bool cmp(pair <int, int> p1, pair <int, int> p2) {
//	return p1.second < p2.second;
//}
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
//	
//	int N, x, y;
//
//	cin >> N;
//
//	for (int i = 0; i < N; i++) {
//		cin >> x >> y;
//		v.push_back(make_pair(x, y));
//	}
//
//	sort(v.begin(), v.end(), cmp); //�ְ����µ��� �������� �������� ����
//
//	int idx = 0, count = 1; //����, ������� ����
//	for (int i = 1; i < N; i++) {
//		//���� ȭ�� ������ �����°� ������ �Ǵ� ȭ�й����� �ְ� �µ����� ũ��
//		if (v.at(i).first > v.at(idx).second) {
//			idx = i; //������ ���� ȭ�й����� �ٲ���
//			count++; //����� ���� �ϳ� ����
//		}
//	}
//
//	cout << count << "\n";
//	
//	return 0;
//}