//#include<iostream>
//#include<queue>
//
//using namespace std;
//int mov[101];
//queue <int> q;
//int visit[101];
//
//void solve() {
//	while (!q.empty()) {
//		int k = q.front();
//		//�ֻ���
//		for (int i = 1; i <= 6; i++) {
//			//���� ��ġ ����
//			int nk = k + i;
//			//���� ��ġ�� 100�� ������ Ż��(�� ��Ȳ���� �ֻ����� ���� �� ū ���� �� �ʿ� ����)
//			if (nk > 100) {
//				break;
//			}
//
//			//���� ��ġ�� ���̳� ��ٸ��� ������ ��ġ�� �׿� �ش��ϴ� ������ ����
//			if (mov[nk] != 0) {
//				nk = mov[nk];
//			}
//
//			//�湮���� ���� ��ġ��� ť�� �߰��ϰ� visit �迭�� �Ÿ� �Է�
//			if (visit[nk] == -1) {
//				q.push(nk);
//				visit[nk] = visit[k]+1;
//			}
//		}
//		q.pop();
//		
//	}
//}
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
//
//	int N, M;
//
//	cin >> N >> M;
//
//	//��ٸ� ����
//	for (int i = 0; i < N; i++) {
//		int go, to;
//		cin >> go >> to;
//		mov[go] = to;
//	}
//
//	//�� ����
//	for (int i = 0; i < M; i++) {
//		int go, to;
//		cin >> go >> to;
//		mov[go] = to;
//	}
//
//	//visit �迭 �ʱ�ȭ
//	fill(visit, visit+101, -1);
//	//1�� �����ϹǷ� ť�� �߰�
//	q.push(1);
//	//1������ �����ϹǷ� 1���� Ƚ���� 0��
//	visit[1] = 0;
//	solve();
//
//	cout << visit[100] << "\n";
//
//  return 0;
//}