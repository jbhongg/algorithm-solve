//#include <iostream>
//#include <limits.h>
//#include<algorithm>
//
//using namespace std;
//
//int arr[20][20];
//int start[10];
//int link[10];
//int N, answer;
//int minn = INT_MAX;
//
////�ɷ�ġ ���
//void cal() {
//    int sum_start = 0;
//    int sum_link = 0;
//    for (int i = 0; i < N / 2; i++) {
//        for (int j = 0; j < N / 2; j++) {
//            sum_start = sum_start + arr[start[i]][start[j]];
//            sum_link = sum_link + arr[link[i]][link[j]];
//        }
//    }
//    answer = abs(sum_start - sum_link);
//}
//
//void solve(int k, int idx) {
//    if (minn == 0) {
//        return;
//    }
//
//    //��� ���� ������ �̾�����
//    if (k == N / 2) {
//        int j = 0;
//        int r = 0;
//        //������ ���� ������� �ٸ���
//        for (int i = 0; i < N; i++) {
//            if (i != start[j]) {
//                link[r] = i;
//                r++;
//            }
//            else if (i == start[j]) {
//                j++;
//            }
//        }
//        cal();
//        minn = min(answer, minn);
//        return;
//    }
//
//    //����
//    for (int i = idx; i < N; i++) {
//        start[k] = i;
//        solve(k + 1, i + 1);
//    }
//}
//
//int main()
//{
//    ios_base::sync_with_stdio(false);
//    cin.tie(0);
//    cout.tie(0);
//
//    cin >> N;
//
//    for (int i = 0; i < N; i++) {
//        for (int j = 0; j < N; j++) {
//            cin >> arr[i][j];
//        }
//    }
//
//    start[0] = 0; //0�������� ��츸 �ϸ� ��ü�� �� �غ��°Ͱ� ����
//
//    solve(1, 1);
//
//    cout << minn << "\n";
//    return 0;
//}