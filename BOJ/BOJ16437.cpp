//#include<iostream>
//#include<vector>
//
//using namespace std;
//
//vector <pair <char, long long> > info[123456];
//vector <long long> node[123456];
//
//long long solve(int n) {
//	long long cnt = 0;
//	//dfs
//	for (int i = 0; i < node[n].size(); i++) {
//		cnt = cnt + solve(node[n][i]);
//	}
//	//���� ���� �ִ� ������ ���̸�
//	if (info[n].front().first == 'S') {
//		return cnt + info[n].front().second; //��������� ���� ������ ���� ���� ���� ������ ���ؼ� ��ȯ
//	}
//	//���� ���� �ִ� ������ �����̸�
//	else {
//		cnt = cnt - info[n].front().second; //��������� ���� �������� ������ ���� ����
//		//���� ���� ������ �����̸� �ش� �������� ���� ������ 0���� �ʱ�ȭ(���� ���� �����ؼ� �� ���� ��ġ�� ������ ���� ����)
//		if (cnt < 0) {
//			return 0;
//		}
//		//���� ���� ������ ����̸� ���� ���� �� ��ȯ
//		else {
//			return cnt;
//		}
//	}
//}
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
//
//	int N;
//
//	cin >> N;
//
//	for (int i = 2; i <= N; i++) {
//		char t;
//		long long a, p;
//		cin >> t >> a >> p;
//		info[i].push_back(make_pair(t, a)); //�� ���� ������ ������ ���� ����
//		node[p].push_back(i); //�� ���� ����Ǿ� �ִ� �� ����
//	}
//
//	info[1].push_back(make_pair('S', 0)); //1�� ���� ���� ����
//
//	cout << solve(1) << "\n";
//	
//	return 0;
//}