//#include <string>
//#include <vector>
//
//using namespace std;
//
//bool visit[30][30];
//
//int solution(int m, int n, vector<string> board) {
//    int answer = 0;
//    while (true) {
//        for (int i = 0; i < m; i++) {
//            for (int j = 0; j < n; j++) {
//                if (board[i][j] != '.') {
//                    //������. ������ �밢�� �Ʒ�, �Ʒ����� �ʾȿ� �ְ� ������ ���� ���� ���̸� visit �迭�� ǥ��
//                    if (i + 1 < m && j + 1 < n && board[i + 1][j] == board[i][j] && board[i][j + 1] == board[i][j] && board[i + 1][j + 1] == board[i][j]) {
//                        visit[i][j] = true;
//                        visit[i + 1][j] = true;
//                        visit[i][j + 1] = true;
//                        visit[i + 1][j + 1] = true;
//                    }
//                }
//            }
//        }
//        int count = 0;
//        //visit �迭�� ���� ��� false�� ����(�νǰ� �ƹ��͵� ���ٴ� ��)
//        for (int i = 0; i < m; i++) {
//            for (int j = 0; j < n; j++) {
//                if (visit[i][j]) {
//                    count++;
//                }
//            }
//        }
//        if (count == 0) {
//            break;
//        }
//        count = 0;
//        //�νǰ� ������ ��� �νð� �ν� ������ count ���ְ� visit �迭 �ʱ�ȭ
//        for (int i = 0; i < m; i++) {
//            for (int j = 0; j < n; j++) {
//                if (visit[i][j]) {
//                    count++;
//                    board[i][j] = '.';
//                    visit[i][j] = false;
//                }
//            }
//        }
//        //����� �ν��� ���� ��ϵ��� �Ʒ��� ����߸���(�Ʒ������� �� Ž��)
//        for (int i = 0; i < n; i++) {
//            for (int j = m - 1; j > 0; j--) {
//                //��ĭ�� �����ϸ�
//                if (board[j][i] == '.') {
//                    int k = j - 1; //���� ��ġ�� ��ĭ ���� ����
//                    //��ĭ�� �ƴ� ���� ���������� ����
//                    while (board[k][i] == '.') {
//                        k--;
//                        //�ε����� ����� Ż��
//                        if (k < 0) {
//                            break;
//                        }
//                    }
//                    //��ĭ�� �ƴ� ���� ������ ���� ��ġ�� �� ���� �־��ְ� ���� �ִ� ��ġ�� ��ĭ���� �ٲ���
//                    if (k >= 0) {
//                        board[j][i] = board[k][i];
//                        board[k][i] = '.';
//                    }
//                    else {
//                        break;
//                    }
//                }
//            }
//        }
//        //�νŰ��� ����
//        answer = answer + count;
//    }
//
//    return answer;
//}