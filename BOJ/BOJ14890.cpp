//#include <iostream>
//#include <utility>
//#include <queue>
//
//using namespace std;
//
//int N, L;
//int e, p = 0;
//int map[100][100], temp[100], runway[100];
//queue <int> q;
//
//int solve() {
//	int i = 0;
//
//	while (i < N) {
//		for (int j = 0; j < N; j++) {
//			temp[j] = map[i][j];
//			runway[j] = 0;
//		}
//		for (int j = 0; j < N - 1; j++) {
//			if (temp[j] == temp[j + 1]) {
//				if (j == N - 2) {
//					p++;
//				}
//				continue;
//			}
//			else if (abs(temp[j] - temp[j + 1]) == 1) {
//				if (temp[j] > temp[j + 1]) {
//					if ((N - 1) - j < L) {
//						break;
//					}
//					else {
//						int k = j + 1;
//						int cnt = 0;
//						if (L == 1) {
//							if (runway[k] == 0) {
//								runway[k] = 1;
//							}
//							else {
//								break;
//							}
//						}
//						else {
//							while (cnt < L - 1) {
//								if (temp[k] == temp[k + 1]) {
//									cnt++;
//									if (runway[k] == 0) {
//										runway[k] = 1;
//									}
//									else {
//										e = 1;
//										break;
//									}
//									if (cnt == L - 1 && runway[k + 1] == 0) {
//										runway[k + 1] = 1;
//									}
//									else  if (cnt == L - 1 && runway[k + 1] == 1) {
//										e = 1;
//										break;
//									}
//									k++;
//								}
//								else {
//									e = 1;
//									break;
//								}
//							}
//							j = j + L - 1;
//						}
//					}
//				}
//				else {
//					if (j - (L - 1) < 0) {
//						break;
//					}
//					else {
//						int k = j;
//						int cnt = 0;
//						if (L == 1) {
//							if (runway[k] == 0) {
//								runway[k] = 1;
//							}
//							else {
//								break;
//							}
//						}
//						else {
//							while (cnt < L - 1) {
//								if (temp[k] == temp[k - 1]) {
//									cnt++;
//									if (runway[k] == 0) {
//										runway[k] = 1;
//									}
//									else {
//										e = 1;
//										break;
//									}
//									if (cnt == L - 1 && runway[k - 1] == 0) {
//										runway[k - 1] = 1;
//									}
//									else  if (cnt == L - 1 && runway[k - 1] == 1) {
//										e = 1;
//										break;
//									}
//									k--;
//								}
//								else {
//									e = 1;
//									break;
//								}
//							}
//						}
//					}
//				}
//			}
//			else {
//				break;
//			}
//			if (e == 1) {
//				e = 0;
//				break;
//			}
//			if (j == N - 2) {
//				p++;
//			}
//		}
//		i++;
//	}
//
//	i = 0;
//	while (i < N) {
//		for (int j = 0; j < N; j++) {
//			temp[j] = map[j][i];
//			runway[j] = 0;
//		}
//		for (int j = 0; j < N - 1; j++) {
//			if (temp[j] == temp[j + 1]) {
//				if (j == N - 2) {
//					p++;
//				}
//				continue;
//			}
//			else if (abs(temp[j] - temp[j + 1]) == 1) {
//				if (temp[j] > temp[j + 1]) {
//					if ((N - 1) - j < L) {
//						break;
//					}
//					else {
//						int k = j + 1;
//						int cnt = 0;
//						if (L == 1) {
//							if (runway[k] == 0) {
//								runway[k] = 1;
//							}
//							else {
//								break;
//							}
//						}
//						else {
//							while (cnt < L - 1) {
//								if (temp[k] == temp[k + 1]) {
//									cnt++;
//									if (runway[k] == 0) {
//										runway[k] = 1;
//									}
//									else {
//										e = 1;
//										break;
//									}
//									if (cnt == L - 1 && runway[k + 1] == 0) {
//										runway[k + 1] = 1;
//									}
//									else  if (cnt == L - 1 && runway[k + 1] == 1) {
//										e = 1;
//										break;
//									}
//									k++;
//								}
//								else {
//									e = 1;
//									break;
//								}
//							}
//							j = j + L - 1;
//						}
//					}
//				}
//				else {
//					if (j - (L - 1) < 0) {
//						break;
//					}
//					else {
//						int k = j;
//						int cnt = 0;
//						if (L == 1) {
//							if (runway[k] == 0) {
//								runway[k] = 1;
//							}
//							else {
//								break;
//							}
//						}
//						else {
//							while (cnt < L - 1) {
//								if (temp[k] == temp[k - 1]) {
//									cnt++;
//									if (runway[k] == 0) {
//										runway[k] = 1;
//									}
//									else {
//										e = 1;
//										break;
//									}
//									if (cnt == L - 1 && runway[k - 1] == 0) {
//										runway[k - 1] = 1;
//									}
//									else  if (cnt == L - 1 && runway[k - 1] == 1) {
//										e = 1;
//										break;
//									}
//									k--;
//								}
//								else {
//									e = 1;
//									break;
//								}
//							}
//						}
//					}
//				}
//			}
//			else {
//				break;
//			}
//			if (e == 1) {
//				e = 0;
//				break;
//			}
//			if (j == N - 2) {
//				p++;
//			}
//		}
//		i++;
//	}
//
//	return p;
//}
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
//
//	cin >> N >> L;
//
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < N; j++) {
//			cin >> map[i][j];
//		}
//	}
//
//	solve();
//	cout << p << "\n";
//
//	return 0;
//}