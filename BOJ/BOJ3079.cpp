//#include<iostream>
//#include <string>
//#include <algorithm>
//#include <vector>
//
//using namespace std;
//
//long long solution(int m, vector<int> times) {
//    int s = times.size(); //
//    sort(times.begin(), times.end()); //시간을 오름차순 정렬
//    long long min = 1; 
//    long long max = (long long)(times[s - 1]) * m; //모든 사람이 가장 늦게 걸리는 검색대에서 검사를 받은 것이 최대
//    long long answer = max;
//
//    //최솟값이 최댓값보다 커지면 종료
//    while (min <= max) {
//        long long mid = (min + max) / 2; //중간값 계산(시간)
//        long long sum = 0;
//        //현재 시간에서 각 심사대에서 검사할수 있는 사람의 수 계산
//        for (int i = 0; i < s; i++) {
//            sum += mid / times[i];
//        }
//        //검사할 수 있는 사람의 수가 실제 사람의 수보다 적으면 
//        if (m > sum) {
//            min = mid + 1; //최솟값을 현재 시간+1로 바꾸어줌
//        }
//        //검사할 수 있는 사람의 수가 실제 사람의 수보다 크거나 같으면
//        else {
//            //answer가 현재시간보다 크면
//            if (mid <= answer) {
//                answer = mid; //answer에 현재 시간을 넣어줌
//            }
//            max = mid - 1; //최댓값을 현재 시간 - 1로 바꿔줌
//        }
//    }
//    return answer;
//}
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
//
//    int n, m;
//    vector<int> t;
//
//    cin >> n >> m;
//    for (int i = 0; i < n; i++) {
//        int time;
//        cin >> time;
//        t.push_back(time);
//    }
//
//    cout << solution(m, t) << "\n";
//
//    return 0;
//}