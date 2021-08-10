//#include<iostream>
//#include<vector>
//#include<algorithm>
//
//using namespace std;
//
//bool cmp(pair <int, pair <int, int> > p1, pair <int, pair <int, int> > p2) {
//	return p1.second.second < p2.second.second;
//}
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
//
//	int N;
//	vector <pair <int, pair <int, int> > > room;
//	vector <int> answer;
//
//	cin >> N;
//
//	for (int i = 0; i < N; i++) {
//		int num, start, end;
//
//		cin >> num >> start >> end;
//		room.push_back(make_pair(num, make_pair(start, end)));
//	}
//
//	sort(room.begin(), room.end(), cmp); //����ð��� �������� �������� ����
//	
//	int idx = 0; //�� ó�� ȸ���� index ��ȣ
//	answer.push_back(room.at(0).first); //�� ó�� ȸ�Ǹ� �־���
//	for (int i = 1; i < N; i++) {
//		//�� ȸ���� ����ð��� ���ų� ū ���۽ð��� ��������
//		if (room.at(idx).second.second <= room.at(i).second.first) {
//			answer.push_back(room.at(i).first); //ȸ���� ��ȣ�� �־���
//			idx = i; //ȸ���� �ε��� ��ȣ�� ����
//		}
//	}
//
//	cout << answer.size() << "\n";
//
//	for (int i = 0; i < answer.size(); i++) {
//		cout << answer.at(i) << " ";
//	}
//	cout << "\n";
//	return 0;
//}