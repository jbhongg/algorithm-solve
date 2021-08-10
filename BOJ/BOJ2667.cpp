//#include<iostream>
//#include<queue>
//#include<vector>
//#include<algorithm>
//
//using namespace std;
//
//int map[25][25], n, cnt; //��ü ���� ���� ���� ���� ����
//bool visit[25][25];
//int dc[4] = {-1,0,1,0};
//int dr[4] = {0,1,0,-1};
//
//queue <pair<int, int>> q;
//vector <int> v; //���������� ���� ���� �����ϱ����� ����
//
//void solve(int num) {
//	v.push_back(0); //�Լ��ȿ� ���Դٴ� ���� ���ο� ������ ����ٴ� ���̹Ƿ� ���Ϳ� ���� ���� �������� �߰�
//	while (!q.empty()) {
//		int c = q.front().first;
//		int r = q.front().second;
//		//4�� Ž��
//		for (int i = 0; i < 4; i++) {
//			int nc = c + dc[i];
//			int nr = r + dr[i];
//			//Ž���� ��ġ�� �� �ȿ� �ְ� �湮���� ���� ���̰� ���� 1�̶�� �湮�ߴٰ� ǥ���ϰ� ť�� �߰�
//			if (nc >= 0 && nc < n && nr >= 0 && nr < n && visit[nc][nr] == false && map[nc][nr] == 1) {
//				visit[nc][nr] = true;
//				q.push(make_pair(nc, nr));
//			}
//		}
//		//���� ��ġ�� ���� num���� �ٲ���(���� ��ȣ)
//		map[c][r] = num;
//		v.at(num-2)++; //������ ���� ���� �������� ������ �� ����
//		q.pop();
//	}
//}
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
//
//	int num = 2; //���� �̸��� 2���� �Ű���
//
//	cin >> n;
//
//	for (int i = 0; i < n; i++) {
//		string s;
//		cin >> s;
//		for (int j = 0; j < s.size(); j++) {
//			map[i][j] = s[j] - '0';
//		}
//	}
//
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < n; j++) {
//			//�ʿ� 1�� �ְ� �湮���� ���� ���̶��
//			if (map[i][j] == 1 && visit[i][j] == false) {
//				//�湮�ߴٰ� ǥ���ϰ� ť�� �߰�
//				visit[i][j] = true;
//				q.push(make_pair(i, j));
//				solve(num);
//				cnt++; //��ü ���� �� ����
//				num++; //���� ���� ��ȣ�� �ű������ �� ����
//			}
//		}
//	}
//
//	sort(v.begin(), v.end()); //����
//
//	cout << cnt << "\n";
//	for (int i = 0; i < v.size(); i++) {
//		cout << v[i] << "\n";
//	}
//
//  return 0;
//}