#include <iostream>

using namespace std;

int N;
int A[100+10];
int B[100+10];
int paper[100+10][100+10];

int dy[4] = {0, -1, 0, 1};
int dx[4] = {1, 0, -1, 0};

void InputData(){
    cin >> N;
    for (int i=0; i<N; i++){
        cin >> A[i] >> B[i];
    }
}

int GetOutline(int y, int x)
{
    int cnt = 0;
    
    int curY = y;
    int curX = x;
    for (int i = 0; i < 4; i++)
    {
        int nextY = curY + dy[i];
        int nextX = curX + dx[i];
        if (nextY < 0 || nextY > 100 || nextX < 0 || nextX > 100)
        {
            continue;
        }
        if (paper[nextY][nextX] == 0)
        {
            cnt++;
        }
    }
    
    return cnt;
}

int main(){
    int ans = 0;

    InputData();// 입력받는 부분

    // 여기서부터 작성
    for (int k = 0; k < N; k++)
    {
        for (int i = B[k]; i < B[k] + 10; i++)
        {
            for (int j = A[k]; j < A[k] + 10; j++)
            {
                paper[i][j]++;
            }
        }
    }
    
    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            if (paper[i][j] > 0)
            {
                ans += GetOutline(i, j);
            }
        }
    }

    cout << ans << endl;// 출력하는 부분
    return 0;
}