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
//    //�Ÿ� �ʱ�ȭ
//    for (int i = 1; i <= V; i++) {
//        dis[i] = LLONG_MAX;
//    }
//
//    //���� ��ġ �Ÿ� 0
//    dis[start] = 0;
//    pq.push(make_pair(0, start)); //(�Ÿ�, ���� ��ġ)
//
//    while (!pq.empty()) {
//        int n = pq.top().second; //���� ��ġ
//        long long d = pq.top().first; //���� �Ÿ�
//        pq.pop();
//        //���� ��ġ������ �Ÿ��� ���� �Ÿ����� ������ ���� ����
//        if (dis[n] < d) {
//            continue;
//        }
//        //���� ��ġ���� �� �� �ִ� ��� Ž��
//        for (int i = 0; i < node[n].size(); i++) {
//            int nn = node[n][i].first; //���� ��ġ
//            long long nd = d + node[n][i].second; //���� ��ġ������ �Ÿ�
//            //����� ���� ��ġ������ �Ÿ��� ����Ǿ� �ִ� ���� ��ġ������ �Ÿ����� ������
//            if (nd < dis[nn]) {
//                dis[nn] = nd; //�Ÿ� �ٲ��ֱ�
//                pq.push(make_pair(nd, nn)); //ť�� ����
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
//    //�䱸��Ʈ �Ǹ� ��� ����
//    for (int i = 0; i < 10; i++) {
//        cin >> arr[i];
//    }
//
//    int pos = arr[0]; //�䱸��Ʈ �Ǹ� ���� ��ġ ����
//    int start; //�� ���� ��ġ
//
//    cin >> start;
//
//    long long ydis = 0; //�䱸��Ʈ ���ܸ� �Ÿ�
//    long long now_dis;
//    long long mdis;
//
//    for (int i = 0; i < 10; i++) {
//
//        now_dis = solve(pos, arr[i]); //���� ��ġ���� ���� �Ǹ� ��ġ������ �Ÿ� ���
//        //�Ÿ��� �ִ��̸� �����ٴ� �ǹ� ���� ����
//        if (now_dis == LLONG_MAX) {
//            continue;
//        }
//        //�䱸��Ʈ ���ܸ� ���� �Ÿ� �ֽ�ȭ
//        ydis += now_dis;
//        pos = arr[i]; //���� �䱸��Ʈ �Ǹ� ��ġ ����
//        //���� �Ǹ� ��ġ�� ���� ����Ǿ� �ִ� �亸�� ũ�ų� ������ �� �ʿ� ����
//        if (answer <= arr[i]) {
//            continue;
//        }
//        mdis = solve(start, arr[i]); //���� ��ġ���� ���� �Ǹ� ��ġ������ �Ÿ� ���
//        //�Ÿ��� �ִ��̸� �����ٴ� �ǹ� ���� ����
//        if (mdis == LLONG_MAX) {
//            continue;
//        }
//        //���� �䱸��Ʈ ���ܸ� �Ÿ����� �� �Ÿ��� �۰ų� ������ �� ��ġ ����
//        if (ydis >= mdis) {
//            answer = arr[i];
//        }
//    }
//
//    //����Ǿ� �ִ� ���� �ִ��̸� -1 ���
//    if (answer == INT_MAX) {
//        cout << "-1" << "\n";
//        return 0;
//    }
//    cout << answer << "\n";
//
//    return 0;
//}