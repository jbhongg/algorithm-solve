//#include<iostream>
//#include <string>
//#include <algorithm>
//#include <vector>
//
//using namespace std;
//
//long long solution(int m, vector<int> times) {
//    int s = times.size(); //
//    sort(times.begin(), times.end()); //�ð��� �������� ����
//    long long min = 1; 
//    long long max = (long long)(times[s - 1]) * m; //��� ����� ���� �ʰ� �ɸ��� �˻��뿡�� �˻縦 ���� ���� �ִ�
//    long long answer = max;
//
//    //�ּڰ��� �ִ񰪺��� Ŀ���� ����
//    while (min <= max) {
//        long long mid = (min + max) / 2; //�߰��� ���(�ð�)
//        long long sum = 0;
//        //���� �ð����� �� �ɻ�뿡�� �˻��Ҽ� �ִ� ����� �� ���
//        for (int i = 0; i < s; i++) {
//            sum += mid / times[i];
//        }
//        //�˻��� �� �ִ� ����� ���� ���� ����� ������ ������ 
//        if (m > sum) {
//            min = mid + 1; //�ּڰ��� ���� �ð�+1�� �ٲپ���
//        }
//        //�˻��� �� �ִ� ����� ���� ���� ����� ������ ũ�ų� ������
//        else {
//            //answer�� ����ð����� ũ��
//            if (mid <= answer) {
//                answer = mid; //answer�� ���� �ð��� �־���
//            }
//            max = mid - 1; //�ִ��� ���� �ð� - 1�� �ٲ���
//        }
//    }
//    return answer;
//}
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
//
//    int n, m;
//    vector<int> t;
//
//    cin >> n >> m;
//    for (int i = 0; i < n; i++) {
//        int time;
//        cin >> time;
//        t.push_back(time);
//    }
//
//    cout << solution(m, t) << "\n";
//
//    return 0;
//}