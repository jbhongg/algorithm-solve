//#include<iostream>
//#include<vector>
//#include<algorithm>
//
//using namespace std;
//
//vector <int> v;
//vector <pair <double, int>> vv;
//int N, M, L;;
//
//void solve(double dist, int cnt) {
//	vv.pop_back();
//	double n = (dist * cnt) / (cnt + 1); //������ ���̸� ���� �������� + 1�� ���� 
//	vv.push_back(make_pair(n, cnt + 1)); //���Ӱ� ���� ���� ������ ���Ϳ� �߰�
//}
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
//
//	cin >> N >> M >> L;
//
//	v.push_back(0); //��ӵ����� ������ġ �߰�
//
//	for (int i = 0; i < N; i++) {
//		int r;
//		cin >> r;
//		v.push_back(r);
//	}
//	v.push_back(L); //��ӵ����� ������ ��ġ �߰�
//
//	sort(v.begin(), v.end()); //�������� ����
//
//	//�ްԼҰ� �ִ� ������ ���̸� ���Ϳ� ����, �ι��� ���� ���� ����
//	for (int i = 0; i < v.size()-1; i++) {
//		vv.push_back(make_pair(v[i + 1] - v[i], 1));
//	}
//	//���� ���� �������� ����
//	sort(vv.begin(), vv.end());
//
//
//	for (int i = 0; i < M; i++) {
//		solve(vv.back().first, vv.back().second);
//		sort(vv.begin(), vv.end()); //���� ���� �������� ����
//	}
//	//���� �� ������ ������ ���� �����̸� ���
//	if (vv.back().first == (int)vv.back().first) {
//		cout << (int)vv.back().first << "\n";
//	}
//	//���� �� ������ ������ ���� ������ �ƴϸ� +1�ؼ� ���
//	else {
//		cout << (int)vv.back().first + 1 << "\n";
//	}
//
//	return 0;
//}