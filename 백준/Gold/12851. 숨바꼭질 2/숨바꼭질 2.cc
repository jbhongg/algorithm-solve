#include <iostream>
#include <queue>

using namespace std;

int N, K, num, t= -1;
queue < pair <int, int> > q;
bool visit[100001];
int dir[2] = { -1,1 };

void solve() {
    while (!q.empty()) {
        int cur = q.front().first;
        int cnt = q.front().second;

        q.pop();

        if (t !=-1 && t < cnt) {
            return;
        }

        visit[cur] = true;

        if (num != 0 && cur == K && t == cnt) {
            num++;
        }

        if (num == 0 && cur == K) {
            t = cnt;
            num++;
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

            if (next < 0 || next >100000 || visit[next]) {
                continue;
            }

            q.push(make_pair(next, cnt + 1));
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> K;

    q.push(make_pair(N, 0));
    visit[N] = true;
    solve();
    cout << t << "\n" << num << "\n";

    return 0;
}