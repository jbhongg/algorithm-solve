#include <iostream>
#include <queue>
#include<vector>
#include <cstring>

using namespace std;

int N, K;
queue < pair <int, int> > q;
int visit[100001];
int dir[2] = { -1,1 };
vector <int> v;

void solve() {
    while (!q.empty()) {
        int cur = q.front().first;
        int cnt = q.front().second;

        q.pop();

        if (cur == K) {
            cout << cnt << "\n";
            return;
        }

        for (int i = 0; i < 3; i++) {
            int next;
            //순간이동 경우
            if (i == 2) {
                next = cur * 2;
            }
            else {
                next = cur + dir[i];
            }

            if (next < 0 || next >100000 || visit[next] != -1) {
                continue;
            }
            visit[next] = cur;
            q.push(make_pair(next, cnt + 1));
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    memset(visit, -1, sizeof(visit));

    cin >> N >> K;

    q.push(make_pair(N, 0));
    visit[N] = 0;
    solve();

    if (N == K) {
        cout << N << "\n";
    }
    else {
        v.push_back(K);
        int temp = visit[K];

        while (true) {
            v.push_back(temp);
            if (temp == N) {
                break;
            }
            temp = visit[temp];
        }

        for (int i = v.size() - 1; i >= 0; i--) {
            cout << v[i] << " ";
        }
    }

    return 0;
}