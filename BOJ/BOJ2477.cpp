//#include<iostream>
//
//using namespace std;
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
//	
//	int K, answer = 0;
//	bool flag = false;
//	pair<int, int> p[6];
//	cin >> K;
//	for (int i = 0; i < 6; i++) {
//		cin >> p[i].first >> p[i].second;
//	}
//	for (int i = 0; i < 3; i++) {
//		//���� ��ġ�� �ٴ��� ��ġ���� ������ ���� ���� ��ġ�� �ٴٴ��� ��ġ�� ������ ���ٸ�
//		if (p[i].first == p[i + 2].first && p[i+1].first == p[i+3].first) {
//			//���� ���� ������
//			answer = ((p[i].second + p[i + 2].second) * (p[i + 1].second + p[i + 3].second)) - (p[i + 1].second * p[i + 2].second);
//			flag = true;
//			break;
//		}
//	}
//
//	//���� ��쿡 �´ٸ� �� ���
//	if (flag) {
//		cout << answer*K << "\n";
//	}
//	//���� ��찡 �ƴϸ� 3���� ���� �������� �׿� �´� ������ ����
//	else {
//		if (p[0].first == p[2].first) {
//			answer = ((p[0].second + p[2].second) * (p[1].second + p[5].second)) - (p[0].second * p[1].second);
//			cout << answer* K << "\n";
//		}
//		else if(p[0].first == p[4].first && p[1].first == p[5].first){
//			answer = ((p[0].second + p[4].second) * (p[1].second + p[5].second)) - (p[0].second * p[5].second);
//			cout << answer* K << "\n";
//		}
//		else {
//			answer = ((p[0].second + p[4].second) * (p[3].second + p[5].second)) - (p[4].second * p[5].second);
//			cout << answer * K << "\n";
//		}
//	}
//
//	return 0;
//}