//#include<iostream>
//#include<vector>
//
//using namespace std;
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
//
//	int N, K, a, answer = 0;
//	vector <int> v;
//
//	cin >> N >> K;
//	for (int i = 0; i < N; i++) {
//		cin >> a;
//		v.push_back(a);
//	}
//	int i = 0;
//
//	while (true) {
//		answer++;
//		i = v.at(i); //i�� ���� ����� ����Ų ��ȣ
//	    //i�� K(�������� ��ȣ)�� ������ ����
//		if (i == K) {
//			break;
//		}
//		//���� �����ŭ ������ ���Ҵµ� ������ ��ȣ�� ������ �ʾҴٸ� �����̰� �ɸ� �� ����
//		else if (answer >= N) {
//			answer = -1;
//			break;
//		}
//	}
//
//	cout << answer << "\n";
//	return 0;
//}