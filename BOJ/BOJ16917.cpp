//#include<iostream>
//#include<algorithm>
//
//using namespace std;
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
//
//	int A, B, C, X, Y, minn, sum = 0;
//
//	cin >> A >> B >> C >> X >> Y;
//
//	//반반 치킨을 사서 양념 치킨과 후라이드 치킨을 각각 1마리씩 만든는 것이 싼 경우
//	if ((A + B) > 2 * C) {
//		minn = min(X, Y);
//		sum = minn * 2 * C;              // 양념 치킨과 후라이드 치킨의 갯수가 같은 만큼 반반 치킨을 사서 1마리씩 만들어준다
//		X = X - minn;
//		Y = Y - minn;
//		if (X == 0) {                    //후라이드 치킨의 최소 갯수가 양념 치킨보다 많은 경우
//			if (B <= (2 * C)) {          //후라이드 치킨의 1마리 가격이 반반치킨 2개의 가격보다 싼 경우
//				sum = sum + (Y * B);     //남은 후라이드 치킨의 수만큼 후라이드 치킨의 가격으로 구매
//			}
//			else {                       //후라이드 치킨의 1마리 가격이 반반치킨 2개의 가격보다 비싼 경우
//				sum = sum + (Y * 2 * C); //남은 후라이드 치킨의 수를 반반 치킨으로 구매
//			}
//		}  
//		else {                           //양념 치킨의 최소 갯수가 후라이드 치킨보다 많은 경우
//			if (A <= (2 * C)) {
//				sum = sum + (X * A);
//			}
//			else {
//				sum = sum + (X * 2 * C);
//			}
//		}
//	}
//	//양념치킨과 후라이드 치킨을 따로따로 사는게 더 싼 경우
//	else {
//		sum = (A * X) + (B * Y);
//	}
//
//	printf("%d\n", sum);
//	return 0;
//}