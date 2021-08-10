//#include<iostream>
//#include<algorithm>
//#include<limits.h>
//
//using namespace std;
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
//	
//	int N, H, cnt = 0, answer = INT_MAX;
//	int s[100000]; //����
//	int j[100000]; //������
//
//	cin >> N >> H;
//
//	//������ �������� ���� ����
//	for (int i = 0; i < N/2; i++) {
//		cin >> s[i] >> j[i];
//	}
//
//	//������ ������ �������� ����
//	sort(s, s + (N / 2));
//	sort(j, j + (N / 2));
//	
//	//1���� H���� ��� Ž��
//	for (int i = 1; i <= H; i++) {
//		//lower_bound(arr, arr+N, k) - arr -> k�̻��� ���� ó�� �����ϴ� �ε��� ��ȯ
//		//upper_bound(arr, arr+N, k) - arr -> k�ʰ��� ���� ó�� �����ϴ� �ε��� ��ȯ
//
//		int s_idx = lower_bound(s, s + (N / 2), i) - s; //�ش� �������� �������� �ε����� ������ ���� ���
//		int sum = (N / 2) - s_idx;
//		int j_idx = upper_bound(j, j + (N / 2), H - i) - j;  //�ش� �������� �������� �ε����� �������� ���� ���
//		sum += (N / 2) - j_idx;; //�ε����� �������� ������ �� 
//
//		//���� ����Ǿ� �ִ� ��� ���� �������� ������ �� �ε����� �������� ������ ���� ������
//		if (answer == sum) {
//			cnt++; // ������ ���� ����
//		}
//		//���� ����Ǿ� �ִ� �亸�� ���� �������� ������ �� �ε����� �������� ������ ���� ������
//		else if (answer > sum) {
//			answer = sum; //�信 ���� �������� ������ �� �ε����� �������� ������ �� ����
//			cnt = 1; //������ ���� 1�� �ʱ�ȭ
//		}
//	}
//
//	cout << answer << " " << cnt << "\n";
//
//	return 0;
//}