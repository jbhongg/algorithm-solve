//#include<iostream>
//#include<algorithm>
//
//using namespace std;
//
//int N;
//int start[10], link[10], tmp[20];
//int skill[20][20];
//int min_diff = 1000000000;
//
//int cal() {
//	int start_sum = 0;
//	int link_sum = 0;
//	int diff = 0;
//	for (int i = 0; i < N / 2; i++) {
//		for (int j = 0; j < N / 2; j++) {
//			start_sum = start_sum + skill[start[i]][start[j]];
//			link_sum = link_sum + skill[link[i]][link[j]];
//		}
//	}
//
//	diff = abs(start_sum - link_sum);
//	min_diff = min(min_diff, diff);
//
//	return min_diff;
//}
//
//int team(int x, int cnt) {
//	int p, k;
//	if (cnt == (N / 2)) {
//		p = 0;
//		k = 0;
//		for (int j = 0; j < N; j++) {
//			if (tmp[j] == 1) {
//				start[p++] = j;
//			}
//			else if (tmp[j] == 0) {
//				link[k++] = j;
//			}
//		}
//		cal();
//		return 0;
//	}
//
//	for (int i = x; i < N; i++) {
//		if (tmp[i] == 0) {
//			tmp[i] = 1;
//			team(i + 1, cnt + 1);
//			tmp[i] = 0;
//		}
//	}
//
//	return 0;
//}
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
//
//	cin >> N;
//
//	for (int i = 0; i < N; i++) {
//		tmp[i] = 0;
//	}
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < N; j++) {
//			cin >> skill[i][j];
//		}
//	}
//
//	team(0, 0);
//
//	printf("%d\n", min_diff);
//	return 0;
//}