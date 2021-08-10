//#include<iostream>
//#include<vector>
//#include<algorithm>
//
//using namespace std;
//
//typedef struct Edge
//{
//	int from;
//	int to;
//	int wight;
//}Edge;
//
//vector <Edge> edge;
//int m, n;
//int parent[200000];
//
//void make() {
//	for (int i = 0; i < m; i++) {
//		parent[i] = i;
//	}
//}
//
////���� ����� ��ǥ ã��
//int find(int a) {
//	//��ǥ�� �ڱ��ڽ��̶�� return
//	if (parent[a] == a) {
//		return a;
//	}
//	//�ƴϸ� ��ǥ�� ã�� ������ ���
//	return parent[a] = find(parent[a]);
//}
//
//bool Union(int a, int b) {
//	int aroot = find(a); //��� ����� ��ǥ ã��
//	int broot = find(b); //���� ����� ��ǥ ã��
//	//��� ���� ���� ����� ��ǥ�� ��ġ�ϸ� false return
//	if (aroot == broot) {
//		return false;
//	}
//	//�ƴϸ� ��������� ��ǥ�� ��߳���� ��ǥ�� ����
//	parent[broot] = aroot;
//	return true;
//}
//
//bool cmp(Edge e1, Edge e2) {
//	return e1.wight < e2.wight;
//}
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
//
//	while (true) {
//		int total = 0;
//		edge.clear();
//		cin >> m >> n;
//		//�Է°��� 0 0�� ������ Ż��
//		if (m == 0 && n == 0) {
//			break;
//		}
//
//		for (int i = 0; i < n; i++) {
//			Edge e;
//			cin >> e.from >> e.to >> e.wight;
//			edge.push_back(e); //���� ���� ����
//			total += edge[i].wight; //��ü ����ġ�� �� ����
//		}
//		//���� ������ ����ġ�� �������� �������� ����
//		sort(edge.begin(), edge.end(), cmp);
//		make(); //�� ����� ��ǥ ����
//		int result = 0;
//		int count = 0;
//
//		for (int i = 0; i < edge.size(); i++) {
//			//��� ���� ���� ����� ��ǥ�� ��ġ���� ������
//			if (Union(edge[i].from, edge[i].to)) {
//				result += edge[i].wight; //���� ���� ������ ����ġ�� ����
//				count++; //���� ���� ����
//				//��� ��带 ���������� Ż��
//				if (count == m - 1) {
//					break;
//				}
//			}
//		}
//
//		cout << total - result << "\n";
//	}
//
//	return 0;
//}