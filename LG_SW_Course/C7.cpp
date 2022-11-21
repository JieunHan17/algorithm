#include <iostream>
#include <algorithm>
#include <stack>
#include <utility>
 
using namespace std;
 
int N;//히스토그램수
int H[100000+10];//히스토그램 높이
 
bool InputData() {
    cin >> N;
    if (N == 0) return false;
     
    for (int i=0; i<N; i++){
        cin >> H[i];
    }
    return true;
}
 
int main() {
    while(InputData()){//입력받는 부분
        long long ans = -1;
        //여기서부터 작성
        stack<pair<int, int> > s; // (높이, 인덱스)
        s.push(make_pair(H[0], 0));
        for (int i = 1; i < N; i++)
        {
            if (H[i] < s.top().first)
            {
                int idx;
                while (!s.empty() && H[i] < s.top().first)
                {
                    ans = max(ans, (long long)s.top().first * (i - s.top().second));
                    idx = s.top().second;
                    s.pop();
                }
                s.push(make_pair(H[i], idx));
            }
            else
            {
                s.push(make_pair(H[i], i));
            }
        }
         
        while (!s.empty())
        {
            ans = max(ans, (long long)s.top().first * (N - s.top().second));
            s.pop();
        }
         
        cout << ans << "\n";//출력하는 부분
    }
    return 0;
}