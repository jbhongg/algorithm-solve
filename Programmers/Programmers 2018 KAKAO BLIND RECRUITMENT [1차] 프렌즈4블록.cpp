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
//                    //오른쪽. 오른쪽 대각석 아래, 아래쪽이 맵안에 있고 현재의 값과 같은 값이면 visit 배열에 표시
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
//        //visit 배열의 값이 모두 false면 종료(부실게 아무것도 없다는 뜻)
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
//        //부실게 있으면 모두 부시고 부신 갯수를 count 해주고 visit 배열 초기화
//        for (int i = 0; i < m; i++) {
//            for (int j = 0; j < n; j++) {
//                if (visit[i][j]) {
//                    count++;
//                    board[i][j] = '.';
//                    visit[i][j] = false;
//                }
//            }
//        }
//        //블록을 부신후 남은 블록들을 아래로 떨어뜨리기(아래서부터 열 탐색)
//        for (int i = 0; i < n; i++) {
//            for (int j = m - 1; j > 0; j--) {
//                //빈칸이 존재하면
//                if (board[j][i] == '.') {
//                    int k = j - 1; //현재 위치의 한칸 위를 저장
//                    //빈칸이 아닌 값을 만날때까지 진행
//                    while (board[k][i] == '.') {
//                        k--;
//                        //인덱스를 벗어나면 탈출
//                        if (k < 0) {
//                            break;
//                        }
//                    }
//                    //빈칸이 아닌 값이 있으면 현재 위치에 그 값을 넣어주고 값이 있던 위치를 빈칸으로 바꿔줌
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
//        //부신갯수 저장
//        answer = answer + count;
//    }
//
//    return answer;
//}