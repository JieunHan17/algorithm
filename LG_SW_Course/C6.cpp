#include <iostream>
#include <string>
#include <queue>
 
using namespace std;
 
#define MAX_N (300000)
 
int N, K;
string name[MAX_N + 10];
queue<int> q[20 + 10];
 
void Input_Data(void) {
    string str;
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        cin >> name[i];
    }
}
 
int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
 
    long long sol = 0;
 
    // 입력 받는 부분
    Input_Data();
 
    // 여기서부터 작성
    for (int i = 0; i < N; i++)
    {
        while (1)
        {
            if (q[name[i].length()].empty())
            {
                break;
            }
             
            if (i - q[name[i].length()].front() > K)
            {
                q[name[i].length()].pop();
            }
            else
            {
                break;
            }
        }
        sol += q[name[i].length()].size();
        q[name[i].length()].push(i);
    }
 
    // 출력하는 부분
    cout << sol << '\n';
 
    return 0;
}