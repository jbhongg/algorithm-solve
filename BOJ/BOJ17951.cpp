//#include<iostream>
//#include<vector>
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
//	int N, K;
//	int low = 0;
//	int high = 0;
//
//	cin >> N >> K;
//
//	for (int i = 0; i < N; i++) {
//		int num;
//		cin >> num;
//		high = high + num; //�ʱ� �ִ��� ���� ���� ������ ��ü ��
//		v.push_back(num);
//	}
//
//	while (low <= high) {
//		int temp = 0;
//		int cnt = 0; //���� �׷��
//		int mid = (low + high) / 2; //�߰��� ���
//		for (int i = 0; i < v.size(); i++) {
//			temp = temp + v.at(i); //���� �׷��� ���� ���� ���� �� ����
//			//���� ��������� ���� ���� ���� ���� �߰������� ũ�ų� ������ 
//			if (temp >= mid) {
//				cnt++; //�׷��� ����(�׷� �� ����) 
//				temp = 0; //���� �׷��� ���� ���� ���� ���� ���ϱ� ���� �ʱ�ȭ
//			}
//		}
//		//�׷��� ���� K���� ũ�ų� ������(�ּڰ��� mid���� �� ũ�ٴ� �ǹ��̹Ƿ� low���� mid+1�� �ٲ���)
//		if (cnt >= K) {
//			low = mid+1;
//		}
//		//�׷��� ���� K���� ������(�ּڰ��� mid���� �� �۴ٴ� �ǹ��̹Ƿ� high���� mid-1�� �ٲ���)
//		else {
//			high = mid - 1;
//		}
//	}
//
//	cout << high << "\n";
//	
//	return 0;
//}