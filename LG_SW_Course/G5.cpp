#include <iostream>
#include <stdlib.h>
#include <algorithm>

using namespace std;

#define MAXN ((int)1e5)
#define INF 987654321

int N;
int X[MAXN + 10];
int Y[MAXN + 10];
int presum[MAXN + 10];
int ans = INF;

void InputData(){
    cin >> N;
    for (int i=0; i<N; i++){
        cin >> X[i] >> Y[i];
    }
}

void GetPresum()
{
    presum[0] = 0;
    for (int i = 1; i < N; i++)
    {
        presum[i] = presum[i - 1] + abs(X[i] - X[i - 1]) + abs(Y[i] - Y[i - 1]);
    }
}

void Solve()
{
    for (int i = 1; i < N - 1; i++)
    {
        int sum = (presum[N - 1] - presum[i + 1]) + presum[i - 1] + abs(X[i + 1] - X[i - 1]) + abs(Y[i + 1] - Y[i - 1]);
        ans = min(ans, sum);
    }
}

int main(){
    InputData();//입력받는 부분

    //여기서부터 작성
    GetPresum();
    Solve();

    cout << ans << endl;//출력하는 부분
    return 0;
}