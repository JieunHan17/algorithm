#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

#define MAX 501

using namespace std;

int K;
int A[6+10];
int B[6+10];
int dir[5];

int maxWidth, maxHeight, minWidth, minHeight;
int maxWidthIdx, maxHeightIdx, minWidthIdx, minHeightIdx;

void InputData(){
    cin >> K;
    for (int i=0 ; i<6 ; i++){
        cin >> A[i] >> B[i];
    }
}

int main(){
    int ans = -1;
    InputData();// 입력받는 부분

    // 여기서부터 작성
    for (int i = 0; i < 6; i++)
    {
        dir[A[i]]++;
    }
    
    for (int i = 0; i < 6; i++)
    {
        if (A[i] == 1 || A[i] == 2)
        {
            if (maxWidth < B[i])
            {
                maxWidth = B[i];
                maxWidthIdx = i;
            }
        }
        else
        {
            if (maxHeight < B[i])
            {
                maxHeight = B[i];
                maxHeightIdx = i;
            }
        }
    }
    
    if (dir[1] == 2 && dir[2] == 1 && dir[3] == 2 && dir[4] == 1 || dir[1] == 1 && dir[2] == 2 && dir[3] == 1 && dir[4] == 2)
    {
        minWidthIdx = (maxWidthIdx + 2) % 6;
        minHeightIdx = (minWidthIdx + 1) % 6;
    }
    else
    {
        minHeightIdx = (maxHeightIdx + 2) % 6;
        minWidthIdx = (minHeightIdx + 1) % 6;
    }
    
    minWidth = B[minWidthIdx];
    minHeight = B[minHeightIdx];
    
    ans = (maxWidth * maxHeight - minWidth * minHeight) * K;

    cout << ans << endl;// 출력하는 부분
    return 0;
}