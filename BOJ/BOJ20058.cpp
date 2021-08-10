//#include<iostream>
//#include<math.h>
//#include<queue>
//#include<limits.h>
//#include<algorithm>
//
//using namespace std;
//
//int N, Q, answer, cnt, s;
//int map[65][65];
//queue <int> q;
//queue <int> rq;
//bool check[65][65];
//bool visit[65][65];
//int dc[4] = { -1,0,1,0 };
//int dr[4] = { 0,1,0,-1 };
//
//void dfs(int c, int r) {
//    visit[c][r] = true;
//    for (int i = 0; i < 4; i++) {
//        int nc = c + dc[i];
//        int nr = r + dr[i];
//        if (nc < 0 || nc >= s || nr < 0 || nr >= s || map[nc][nr] <= 0 || visit[nc][nr])
//        {
//            continue;
//        }
//        else {
//            cnt++;
//            dfs(nc, nr);
//        }
//    }
//}
//
//void ice_delete() {
//    for (int i = 0; i < s; i++)
//    {
//        for (int j = 0; j < s; j++)
//        {
//            int count = 0;
//            for (int k = 0; k < 4; k++) {
//                int nc = i + dc[k];
//                int nr = j + dr[k];
//                if (nc < 0 || nc >= s || nr < 0 || nr >= s) {
//                    count++;
//                }
//                else {
//                    if (map[nc][nr] <= 0) {
//                        count++;
//                    }
//                }
//                if (count >= 2) {
//                    check[i][j] = false;
//                    break;
//                }
//            }
//        }
//    }
//    for (int i = 0; i < s; i++)
//    {
//        for (int j = 0; j < s; j++)
//        {
//            if (!check[i][j]) {
//                map[i][j]--;
//            }
//        }
//    }
//}
//
//void rotate(int c, int r, int div, int size, int count) {
//    if (count == div / 2) {
//        return;
//    }
//    for (int i = r; i < r + size; i++) {
//        rq.push(map[c][i]);
//    }
//    for (int i = c + 1; i < c + size; i++) {
//        rq.push(map[i][r + size - 1]);
//    }
//    for (int i = r + size - 2; i >= r; i--) {
//        rq.push(map[c + size - 1][i]);
//    }
//    for (int i = c + size - 2; i > c; i--) {
//        rq.push(map[i][r]);
//    }
//    for (int i = c; i < c + size; i++) {
//        map[i][r + size - 1] = rq.front();
//        rq.pop();
//    }
//    for (int i = r + size - 2; i >= r; i--) {
//        map[c + size - 1][i] = rq.front();
//        rq.pop();
//    }
//    for (int i = c + size - 2; i >= c; i--) {
//        map[i][r] = rq.front();
//        rq.pop();
//    }
//    for (int i = r + 1; i <= r + size - 2; i++) {
//        map[c][i] = rq.front();
//        rq.pop();
//    }
//    rotate(c + 1, r + 1, div, size - 2, count + 1);
//}
//
//void init() {
//    for (int i = 0; i < s; i++)
//    {
//        for (int j = 0; j < s; j++)
//        {
//            check[i][j] = true;
//        }
//    }
//}
//
//void solve(int l) {
//    int div = pow(2, l);
//    for (int i = 0; i < s / div; i++)
//    {
//        for (int j = 0; j < s / div; j++)
//        {
//            rotate(0 + (div * i), 0 + (div * j), div, div, 0);
//        }
//    }
//}
//
//int main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(0);
//    cout.tie(0);
//
//    int total = 0;
//
//    cin >> N >> Q;
//
//    s = pow(2, N);
//
//    for (int i = 0; i < s; i++) {
//        for (int j = 0; j < s; j++) {
//            cin >> map[i][j];
//        }
//    }
//
//    for (int i = 0; i < Q; i++) {
//        int L;
//        cin >> L;
//        q.push(L);
//    }
//
//    while (!q.empty()) {
//        int l = q.front();
//        q.pop();
//        init();
//        if (l != 0) {
//            solve(l);
//        }
//        ice_delete();
//    }
//    int ice = 0;
//    for (int i = 0; i < s; i++)
//    {
//        for (int j = 0; j < s; j++)
//        {
//            if (map[i][j] > 0) {
//                ice++;
//                total += map[i][j];
//            }
//        }
//    }
//
//    for (int i = 0; i < s; i++)
//    {
//        for (int j = 0; j < s; j++)
//        {
//            if (!visit[i][j] && map[i][j] > 0) {
//                cnt = 1;
//                dfs(i, j);
//                answer = max(answer, cnt);
//                if (answer == ice) {
//                    goto L;
//                }
//            }
//        }
//    }
//
//L:cout << total << "\n" << answer << "\n";
//
//    return 0;
//}