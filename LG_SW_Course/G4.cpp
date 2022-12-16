#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
  
int N;
int sm[100000 + 10];
int sd[100000 + 10];
int em[100000 + 10];
int ed[100000 + 10];
  
int Solve() {
    vector <pair<int, int>> A;
    for (int i = 0; i < N; i++) {
        A.push_back({ sm[i] * 100 + sd[i], em[i] * 100 + ed[i] });
    }
    sort(A.begin(), A.end());
    int cnt = 0, i = 0, e = 301;
    for (;;) {
        int maxv = 0;
        while ((i < A.size()) && (A[i].first <= e)) {
            if (maxv < A[i].second) maxv = A[i].second;
            i++;
        }
        if (maxv <= e) return 0; //전에 피는 꽃이 지는 날보다 더 늦게까지 피어 있어야 함
        cnt++;
        if (maxv > 1130) return cnt;
        e = maxv;
    }
}
  
void InputData() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> sm[i] >> sd[i] >> em[i] >> ed[i];
    }
}
  
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int ans = -1;
  
    InputData();// 입력받는 부분
  
    ans = Solve();// 여기서부터 작성
  
    cout << ans << "\n";// 출력하는 부분
    return 0;
}