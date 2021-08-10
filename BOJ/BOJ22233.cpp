//#include <iostream>
//#include <vector>
//#include <cstring>
//#include <cstdlib>
//
//using namespace std;
//
//int N, M;
//vector<pair<string, int>> v;
//
//int cmp(const void* a, const void* b)    // 오름차순 비교 함수 구현
//{
//    pair <string, int> p1, p2;
//    p1 = *(pair <string, int>*)a;    // void 포인터를 int 포인터로 변환한 뒤 역참조하여 값을 가져옴
//    p2 = *(pair <string, int>*)b;    // void 포인터를 int 포인터로 변환한 뒤 역참조하여 값을 가져옴
//
//    if (p1.first < p2.first) {
//        return -1;
//    }     
//    else if (p1.first > p2.first) {
//        return 1;
//    }
//    else {
//        return 0;
//    }
//}
//
//int check(char* ptr)
//{
//    int min = 0;
//    int max = N-1;
//    int answer = max;
//
//    while (min <= max) {
//        int mid = (min + max) / 2;
//        if (ptr == v.at(mid).first) {
//            answer = mid;
//            break;
//        }
//        else if (ptr < v.at(mid).first) {
//            max = mid - 1;
//        }
//        else {
//            min = mid + 1;
//        }
//    }
//
//    return answer;
//}
//
//int main()
//{
//    ios_base::sync_with_stdio(false);
//    cin.tie(0);
//    cout.tie(0);
//
//    cin >> N >> M;
//
//    int cnt = N;
//
//    for (int i = 0; i < N; i++)
//    {
//        string temp;
//        cin >> temp;
//        v.push_back(make_pair(temp, 0));
//    }
//    qsort(&v[0], v.size(), sizeof(pair <string, int>), cmp);
//    for (int i = 0; i < M; i++)
//    {
//        char temp[110];
//        char* ptr;
//        cin >> temp;
//        ptr = strtok(temp, ",");
//        while (ptr != NULL)
//        {
//            int pos = check(ptr);
//            if (v.at(pos).first == ptr && v.at(pos).second == 0)
//            {
//                cnt--;
//                v.at(pos).second = 1;
//            }
//
//            ptr = strtok(NULL, ",");
//        }
//        cout << cnt << "\n";
//    }
//
//    return 0;
//}