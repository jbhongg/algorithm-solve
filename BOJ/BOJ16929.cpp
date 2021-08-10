//#include<iostream>
//
//using namespace std;
//
//int N, M;
//char map[50][50];
//bool visit[50][50];
//int dc[4] = { -1,0,1,0 };
//int dr[4] = { 0,1,0,-1 };
//bool flag;
//
////������ġ, Ž�� Ƚ��, ���� ��ġ
//void solve(int c, int r, int cnt, int bc, int br) {
//	//����Ŭ�� ������ ����
//	if (flag) {
//		return;
//	}
//
//	visit[c][r] = true; //���� ��ġ �湮 ǥ��
//
//	//4�� Ž��
//	for(int i = 0; i < 4; i++) {
//		int nc = c + dc[i];
//		int nr = r + dr[i];
//		//Ž���� ��ġ�� �ʾȿ� ������
//		if (nc >=0 && nr >= 0 && nc < N && nr < M) {
//			//Ž����ġ�� ���� ���� ��ġ�� ���� �ٸ��� ���� ����
//			if (map[c][r] != map[nc][nr]) {
//				continue;
//			}
//			//Ž����ġ�� ���� ���� ��ġ�� ���� ���� �湮���� �ʾ�����
//			if (!visit[nc][nr]) {
//				solve(nc, nr, cnt + 1, c, r); //���
//
//			}
//			//Ž����ġ�� ���� ���� ��ġ�� ���� ������ �湮�ߴ� ���̰� Ž��Ƚ���� 4�̻��̸�
//			else if (visit[nc][nr] && cnt >= 4) {
//				//Ž�� ��ġ�� �ٷ������� �湮�� ��ġ�� ���� ����
//				if (nc == bc && nr == br) {
//					continue;
//				}
//				//�ƴϸ� ����Ŭ ���� ǥ�� �� ����
//				flag = true;
//				return;
//			}
//		}
//	}
//}
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
//
//	cin >> N >> M;
//
//	string answer = "No";
//
//	for (int i = 0; i < N; i++) {
//		string s;
//		cin >> s;
//		for (int j = 0; j < s.size(); j++) {
//			map[i][j] = s[j];
//		}
//	}
//
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < M; j++) {
//			//�湮���� �ʾ�����
//			if (!visit[i][j]) {
//				solve(i, j, 1, i, j);
//				//����Ŭ�� ������ "Yes" ��� �� ����
//				if (flag) {
//					answer = "Yes";
//					cout << answer << "\n";
//					return 0;
//				}
//			}
//		}
//	}
//
//	cout << answer << "\n"; //����Ŭ�� ������ "No" ���
//
//	return 0;
//}