#include <iostream>
#include <stdio.h>
#include <utility>
#include <algorithm>

using namespace std;

int N;//마을 수
int A[100000+10];//마을 위치
int B[100000+10];//잡힌 물고기 양

void InputData(){
    scanf("%d", &N);
    for (int i=0; i<N; i++){
        scanf("%d %d", &A[i], &B[i]);
    }
}

bool Check(int K)
{
    long long need = 0;
    for (int i = 0; i < N - 1; i++)
    {
        need += (B[i] - K);
        if (need < 0)
        {
            need -= (A[i + 1] - A[i]);
        }
        else
        {
            need -= (A[i + 1] - A[i]);
            if (need < 0)
            {
                need = 0;
            }
        }
    }
    return (need + B[N - 1] - K) >= 0;
}

int BS(int low, int high) // Upper Bound
{
    if (low > high)
    {
        return high;
    }
    int mid = (low + high) / 2;
    if (Check(mid))
    {
        return BS(mid + 1, high);
    }
    else
    {
        return BS(low, mid - 1);
    }
}

int main(){
    int ans = -1;
    InputData();//입력받는 부분

    //여기서부터 작성
    ans = BS(0, *max_element(B, B + N));

    cout << ans << endl;//출력하는 부분
    return 0;
}