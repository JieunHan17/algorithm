#include <iostream>
#include <algorithm>

using namespace std;

#define MAXN (20)
#define INF (MAXN * (int)1e6)

int N, B;
int H[MAXN + 10];
bool visited[MAXN + 10];
int ans;

void InputData(){
    cin >> N >> B;
    for (int i=0; i<N; i++){
        cin >> H[i];
    }
}

void DFS(int start, int cnt, int total)
{
    if (total >= B)
    {
        ans = min(ans, total - B);
        return;
    }

    if (cnt == N)
    {
        return;
    }
    
    for (int i = start + 1; i < N; i++)
    {
        DFS(i, cnt + 1, total + H[i]);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;
    for (int t=1; t<=T; t++){
        InputData();//입력받는 부분

        //여기서부터 작성
        ans = INF;
        for (int i = 0; i < N; i++)
        {
            DFS(i, 1, H[i]);
        }

        cout << ans << "\n";
    }
    return 0;
}