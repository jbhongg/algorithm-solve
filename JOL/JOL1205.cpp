//#include<iostream>
//#include<vector>
//#include<algorithm>
//
//using namespace std;
//
//vector <int> v;
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
//
//	int N, card, joker = 0, result = 0;
//
//	cin >> N;
//
//	for (int i = 0; i < N; i++) {
//		cin >> card;
//		//��Ŀ ī���� ���� ����
//		if (card == 0) {
//			joker++;
//		}
//		//�Ϲ� ī�常 ����
//		else {
//			v.push_back(card);
//		}
//	}
//
//	sort(v.begin(), v.end()); //�Ϲ� ī�� �������� ����
//
//	for (int i = 0; i < v.size(); i++) {
//		int answer = 1;
//		int temp = joker;
//		for (int j = i; j < v.size(); j++) {
//			//���� ī�� ���� �ε����� ����� ����
//			if (j + 1 >= v.size()) {
//				break;
//			}
//			//���� ī��� ����ī�尡 1���̸� ��Ʈ����Ʈ ī�� ���� ����
//			if ((v.at(j + 1) - v.at(j)) == 1) {
//				answer++;
//			}
//			//���� ī��� ����ī�尡 ���ٸ� ���� Ž��
//			else if ((v.at(j + 1) - v.at(j)) == 0) {
//				continue;
//			}
//			//��Ŀ ī�尡 0�� �ƴϰ� ���� ī��� ���� ī�� ���̰� ��Ŀ ī���� ���� ���ų� �۴ٸ� ��Ʈ����Ʈ ī�� ������ ���̸� ���ϰ� ��Ŀ ī�带 ��������Ƿ� ����Ѹ�ŭ ����
//			else if (temp != 0 && ((v.at(j + 1) - v.at(j)) - 1) <= temp) {
//				temp = temp - (v.at(j + 1) - v.at(j)) + 1;
//				answer = answer + (v.at(j + 1) - v.at(j));
//			}
//			//���� ��Ȳ���� �ƴϸ� ����
//			else {
//				break;
//			}
//		}
//		//��Ŀ ī�尡 ������ ��� �� �� ��ŭ ������
//		if (temp != 0) {
//			answer = answer + temp;
//		}
//		result = max(result, answer); //�ִ� ����
//		//�ִ��� �Ϲ�ī��� ��Ŀ ī�带 ���� ���̶�� �׺��� ū ���� �����Ƿ� ����
//		if (result == (v.size() + joker)) {
//			break;
//		}
//	}
//
//	//�Ϲ�ī�尡 ���°��
//	if (v.size() == 0) {
//		result = result + joker;
//	}
//
//	cout << result << "\n";
//	
//	return 0;
//}