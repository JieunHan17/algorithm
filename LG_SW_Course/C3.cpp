#include <iostream>

using namespace std;

int N;//색종이 수
int X[100+10];
int Y[100+10];
int paper[100+10][100+10];

void InputData() {
    cin >> N;
    for (int i=0; i<N; i++){
        cin >> X[i] >> Y[i];
    }
}

bool Check(int leftTopY, int leftTopX, int rightBottomY, int rightBottomX)
{
    for (int i = leftTopY; i <= rightBottomY; i++)
    {
        for (int j = leftTopX; j <= rightBottomX; j++)
        {
            if (paper[i][j] == 0)
            {
                return false;
            }
        }
    }
    return true;
}

int main() {
    int ans = -1;
    InputData();//입력받는 부분
    
    //여기서부터 작성
    for (int i = 0; i < N; i++)
    {
        for (int y = Y[i]; y < Y[i] + 10; y++)
        {
            for (int x = X[i]; x < X[i] + 10; x++)
            {
                paper[y][x]++;
            }
        }
    }
    
    int maxArea = 0;
    for (int leftTopY = 0; leftTopY < 99; leftTopY++)
    {
        for (int leftTopX = 0; leftTopX < 99; leftTopX++)
        {
            if (paper[leftTopY][leftTopX] == 0)
            {
                continue;
            }
            
            for (int rightBottomY = leftTopY + 1; rightBottomY < 100; rightBottomY++)
            {
                for (int rightBottomX = leftTopX + 1; rightBottomX < 100; rightBottomX++)
                {
                    if (Check(leftTopY, leftTopX, rightBottomY, rightBottomX))
                    {
                        maxArea = max(maxArea, (rightBottomY - leftTopY + 1) * (rightBottomX - leftTopX + 1));
                    }
                }
            }
        }
    }
    
    ans = maxArea;
    cout << ans << endl;//출력하는 부분
    return 0;
}