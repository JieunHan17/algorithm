#include <iostream>
#include <stdlib.h>
#include <algorithm>

#define MAX 100

using namespace std;

int w, h, n;
int dir[100+10]; // 1: 북, 2: 남, 3: 서, 4: 동
int dirPair[5] = {0, 2, 1, 4, 3};
int len[100+10];
int y[MAX+10];
int x[MAX+10];
int sol[MAX+10];

void InputData(){
    cin >> w >> h;
    cin >> n;
    for (int i=0; i<=n; i++){
        cin >> dir[i] >> len[i];
        if (dir[i] == 1)
        {
            y[i] = 0;
            x[i] = len[i];
        }
        else if (dir[i] == 2)
        {
            y[i] = h;
            x[i] = len[i];
        }
        else if (dir[i] == 3)
        {
            y[i] = len[i];
            x[i] = 0;
        }
        else if (dir[i] == 4)
        {
            y[i] = len[i];
            x[i] = w;
        }
    }
}

int main(){
    int ans = 0;

    InputData();// 입력받는 부분

    // 여기서부터 작성
    int outline = 2 * (w + h);
    for (int i = 0; i < n; i++)
    {
        if (dir[i] == dir[n])
        {
            sol[i] = abs(len[i] - len[n]);
        }
        else if (dirPair[dir[n]] != dir[i])
        {
            int temp = abs(y[i] - y[n]) + abs(x[i] - x[n]);
            sol[i] = min(temp, outline - temp);
        }
        else
        {
            int temp;
            if (dir[n] == 1 || dir[n] == 2)
            {
                temp = h + x[i] + x[n];
            }
            else
            {
                temp = w + y[i] + y[n];
            }
            sol[i] = min(temp, outline - temp);
        }
    }

    for (int i = 0; i < n; i++)
    {
        ans += sol[i];
    }

    cout << ans << endl;// 출력하는 부분
    return 0;
}