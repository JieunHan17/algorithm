#include <cstdio>
#include <cmath>

using namespace std;

void recur(int startIdx, int finishIdx, int cnt)
{
    if (cnt == 1)
    {
        printf("%d %d\n", startIdx, finishIdx);
        return;
    }
    recur(startIdx, 6-startIdx-finishIdx, cnt-1);
    printf("%d %d\n", startIdx, finishIdx);
    recur(6-startIdx-finishIdx, finishIdx, cnt-1);
}

int main()
{
    int K;
    scanf("%d", &K);
    printf("%d\n", int(pow(2, K))-1);
    recur(1, 3, K);
    return 0;
}