//#include<iostream>
//#include<algorithm>
//
//using namespace std;
//
//long long X[1000001];
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
//
//	long long N, K, ans;
//
//	cin >> N >> K;
//
//	for (int i = 0; i < N; i++) {
//		cin >> X[i];
//	}
//	sort(X, X+N);
//	while (true) {
//		long long minn = X[0]; //현재 최솟값
//		long long count = upper_bound(X, X+N, minn) - X; //현재 최솟값과 같은 수 세기
//		long long diff = X[count] - minn; //최솟값 다음 수와 최솟값의 차이
//
//		//모두다 같은 수라면
//		if (count == N)
//		{
//			ans = minn + (K / count); //정답 계산
//			break;
//		}
//
//		//레벨업 시킬 수 있으면
//		if (diff * count <= K)
//		{
//			X[0] = X[0] + diff; //최솟값을 바꿔줌
//			K = K - (diff * count); //레벨없 시킨 만큼 K값에서 빼줌
//		}
//		//레벨업 시킬 수 없으면
//		else
//		{ 
//			ans = minn + (K / count); //정답 계산
//			break;
//		}
//	}
//	
//	cout << ans << "\n";
//
//	return 0;
//}