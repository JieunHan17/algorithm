#include <stdio.h>
#include <algorithm>

#define MAXN (100)

int A;
int N;
int W[MAXN+10];
int ans;

void InputData(void){
    scanf("%d %d", &A, &N);
    for (int i=1; i<=N; i++){
        scanf("%d", &W[i]);
    }
}

void DFS(int cnt, int sz, int skill, bool deleted)
{
    if (skill > ans)
    {
        return; //가지치기
    }
    if (cnt == N)
    {
        ans = std::min(ans, skill);
        return;
    }
    if (sz > W[cnt + 1])
    {
        DFS(cnt + 1, sz + W[cnt + 1], skill, deleted);
    }
    else
    {
        if (!deleted && sz != 1)
        {
            DFS(cnt, 2 * sz - 1, skill + 1, deleted); //물방울 생성
        }
        
        DFS(cnt + 1, sz, skill + 1, true); //물방울 삭제
    }
}
// 2번 생성
// 1번 삭제하면 그 뒤로는 생성할 필요 X (삭제만 가능)

int main(void){
    int t, T;
    scanf("%d", &T);
    for (t=1; t<=T; t++){
        InputData();//입력받는 부분

        //여기서부터 작성
        std::sort(W + 1, W + N + 1);
        ans = N;
        DFS(0, A, 0, false);

        printf("Case #%d: %d\n", t, ans);//출력하는 부분
    }
    return 0;
}