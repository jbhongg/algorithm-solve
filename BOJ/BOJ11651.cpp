//#include<iostream>
//#include<vector>
//#include<algorithm>
//
//using namespace std;
//
//bool cmp(pair <int, int> p1, pair <int, int> p2) {
//	if (p1.second == p2.second) {    //y���� ���ٸ�
//		return p1.first < p2.first;  //x�� ������ �������� ����
//	}
//
//	return p1.second < p2.second;   //y������ �������� ����
//}
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
//
//	vector <pair <int, int>> v;  //��ǥ���� �ѹ��� �ޱ����� ����
//	int N, x, y;
//	 
//	cin >> N;
//
//	//��ǥ �Է°� �ޱ�
//	for (int i = 0; i < N; i++) {
//		cin >> x >> y;
//		v.push_back(make_pair(x, y));
//	}
//	
//	//����
//	sort(v.begin(), v.end(), cmp);
//
//	//���
//	for (int i = 0; i < N; i++) {
//		cout << v[i].first << " " << v[i].second << '\n';
//	}
//	return 0;
//}