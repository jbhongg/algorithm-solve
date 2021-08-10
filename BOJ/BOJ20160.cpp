//#include <iostream>
//#include <vector>
//#include<queue>
//#include <limits.h>
//#include<algorithm>
//
//using namespace std;
//
//int V, E;
//vector< pair <int, int> > node[10001];
//priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
//int arr[10];
//long long dis[10001];
//int answer = INT_MAX;
//
//
//long long solve(int start, int end) {
//    //거리 초기화
//    for (int i = 1; i <= V; i++) {
//        dis[i] = LLONG_MAX;
//    }
//
//    //현재 위치 거리 0
//    dis[start] = 0;
//    pq.push(make_pair(0, start)); //(거리, 현재 위치)
//
//    while (!pq.empty()) {
//        int n = pq.top().second; //현재 위치
//        long long d = pq.top().first; //현재 거리
//        pq.pop();
//        //현재 위치까지의 거리가 현재 거리보다 작으면 다음 진행
//        if (dis[n] < d) {
//            continue;
//        }
//        //현재 위치에서 갈 수 있는 노드 탐색
//        for (int i = 0; i < node[n].size(); i++) {
//            int nn = node[n][i].first; //다음 위치
//            long long nd = d + node[n][i].second; //다음 위치까지의 거리
//            //계산한 다음 위치까지의 거리가 저장되어 있는 다음 위치까지의 거리보다 작으면
//            if (nd < dis[nn]) {
//                dis[nn] = nd; //거리 바꿔주기
//                pq.push(make_pair(nd, nn)); //큐에 저장
//            }
//        }
//    }
//    return dis[end];
//}
//
//int main()
//{
//    ios_base::sync_with_stdio(false);
//    cin.tie(0);
//    cout.tie(0);
//
//    cin >> V >> E;
//
//    for (int i = 0; i < E; i++) {
//        int u, v, w;
//        cin >> u >> v >> w;
//        node[u].push_back(make_pair(v, w));
//        node[v].push_back(make_pair(u, w));
//    }
//
//    //요구르트 판매 장소 저장
//    for (int i = 0; i < 10; i++) {
//        cin >> arr[i];
//    }
//
//    int pos = arr[0]; //요구르트 판매 시작 위치 저장
//    int start; //내 시작 위치
//
//    cin >> start;
//
//    long long ydis = 0; //요구르트 아줌마 거리
//    long long now_dis;
//    long long mdis;
//
//    for (int i = 0; i < 10; i++) {
//
//        now_dis = solve(pos, arr[i]); //현재 위치에서 다음 판매 위치까지의 거리 계산
//        //거리가 최댓값이면 못간다는 의미 다음 진행
//        if (now_dis == LLONG_MAX) {
//            continue;
//        }
//        //요구르트 아줌마 현재 거리 최신화
//        ydis += now_dis;
//        pos = arr[i]; //현재 요구르트 판매 위치 저장
//        //다음 판매 위치가 현재 저장되어 있는 답보다 크거나 같으면 할 필요 없음
//        if (answer <= arr[i]) {
//            continue;
//        }
//        mdis = solve(start, arr[i]); //현재 위치에서 다음 판매 위치까지의 거리 계산
//        //거리가 최댓값이면 못간다는 의미 다음 진행
//        if (mdis == LLONG_MAX) {
//            continue;
//        }
//        //현재 요구르트 아줌마 거리보다 내 거리가 작거나 같으면 그 위치 저장
//        if (ydis >= mdis) {
//            answer = arr[i];
//        }
//    }
//
//    //저장되어 있는 값이 최댓값이면 -1 출력
//    if (answer == INT_MAX) {
//        cout << "-1" << "\n";
//        return 0;
//    }
//    cout << answer << "\n";
//
//    return 0;
//}