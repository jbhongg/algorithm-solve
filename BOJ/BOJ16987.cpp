//#include<iostream>
//#include<vector>
//#include<algorithm>
//
//using namespace std;
//
//vector <pair<int, int>> v;
//int temp, N, cnt, answer;
//
//void cal() {
//	cnt = 0;
//	//���� �ް� ����
//	for (int i = 0; i < N; i++) {
//		if (v.at(i).first <= 0) {
//			cnt++;
//		}
//	}
//}
//
//void solve(int idx) {
//	//�� ���� ��Ȳ�� ������ �װ� �ִ��̹Ƿ� ����
//	if (answer == N) {
//		return;
//	}
//	//������ ������� ������
//	if (idx == N) {
//		cal(); //���
//		answer = max(answer, cnt); //�ִ� ����
//		return;
//	}
//	//��� �ִ� ����� �̹� ���� ����̸� ���� ������� �̵�
//	if (v.at(idx).first <= 0) {
//		solve(idx + 1);
//		return;
//	}
//	for (int i = 0; i < N; i++) {
//		//�ڱ� �ڽ��̰ų� ĥ ����� �̹� ���� ����̶��
//		if (i == idx || v.at(i).first <= 0) {
//			//ĥ ����� ������ ����̶��
//			if (i == N - 1) {
//				//��� �ִ� ����� ���� ������� �̵�
//				solve(idx + 1);
//			}
//			//���� ��� Ž��
//			continue;
//		}
//		//ĥ �� �ִٸ�
//		else {
//			v.at(i).first = v.at(i).first - v.at(idx).second;   //ĥ ����� ������ ��ȭ ���
//			v.at(idx).first = v.at(idx).first - v.at(i).second; //��� �ִ� ����� ������ ��ȭ ���
//			solve(idx + 1); //��� �ִ� ����� ���� ������� �̵�
//			//���� ������ ����
//			v.at(i).first = v.at(i).first + v.at(idx).second;
//			v.at(idx).first = v.at(idx).first + v.at(i).second;
//		}
//	}
//}
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
//
//	int S, W;
//
//	cin >> N;
//
//	for (int i = 0; i < N; i++) {
//		cin >> S >> W;
//		v.push_back(make_pair(S, W));
//	}
//	
//	solve(0);
//
//	cout << answer << "\n";
//
//    return 0;
//}