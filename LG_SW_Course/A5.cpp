#include <iostream>
#include <utility>
using namespace std;

int A[5+10][5+10];
int B[25+10];
pair<int, int> A_IDX[25+10];
bool checked[5+10][5+10];

void InputData(){
    for (int i=0; i<5; i++){
        for (int j=0; j<5; j++){
            int num;
            cin >> num;
            A[i][j] = num;
            A_IDX[num] = make_pair(i, j);
        }
    }
    for (int i=0; i<25; i++){
        cin >> B[i];
    }
}

bool CheckDiagonal(int startY, int startX, int dy, int dx)
{
    for (int i = 0; i < 5; i++)
    {
        if (!checked[startY][startX])
        {
            return false;
        }
        startY = startY + dy;
        startX = startX + dx;
    }
    return true;
}

int GetBingoLines()
{
    int cnt = 0;
    
    bool flag;
    for (int i = 0; i < 5; i++)
    {
        flag = true;
        for (int j = 0; j < 5; j++)
        {
            if (!checked[i][j])
            {
                flag = false;
                break;
            }
        }
        if (flag)
        {
            cnt++;
        }
    }
    
    for (int j = 0; j < 5; j++)
    {
        flag = true;
        for (int i = 0; i < 5; i++)
        {
            if (!checked[i][j])
            {
                flag = false;
                break;
            }
        }
        if (flag)
        {
            cnt++;
        }
    }
    
    if (CheckDiagonal(0, 0, 1, 1))
    {
        cnt++;
    }
    
    if (CheckDiagonal(4, 0, -1, 1))
    {
        cnt++;
    }
    
    return cnt;
}

int main(){
    int ans = -1;
    InputData();// 입력받는 부분

    // 여기서부터 작성
    for (int i = 0; i < 25; i++)
    {
        int y = A_IDX[B[i]].first;
        int x = A_IDX[B[i]].second;
        checked[y][x] = true;
        if (GetBingoLines() >= 3)
        {
            ans = i + 1;
            break;
        }
    }

    cout << ans << endl;// 출력하는 부분
    return 0;
}