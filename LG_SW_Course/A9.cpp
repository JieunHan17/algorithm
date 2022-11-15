#include <stdio.h>
#include <algorithm>
 
int N, l, M;
int x[100+10], y[100+10];
int ans = -1;
 
int GetCntFish(int startY, int startX, int endY, int endX)
{
    if (startY < 1 || startY > N || startX < 1 || startX > N || endY < 1 || endY > N)
    {
        return 0;
    }
    
    int cnt = 0;
    for (int i = 0; i < M; i++)
    {
        if (y[i] >= startY && y[i] <= endY && x[i] >= startX && x[i] <= endX)
        {
            cnt++;
        }
    }
    return cnt;
}

int main(void)
{
      // 입력받는 부분
      scanf("%d %d %d", &N, &l, &M);
 
      for(int i=0; i<M; i++)
      {
            scanf("%d %d", &y[i], &x[i]);
      }
 
      // 여기서부터 작성
      for (int i = 0; i < M; i++)
      {
          int curY = y[i];
          int curX = x[i];
          for (int j = 1; j < l/2; j++)
          {
              int height = j;
              int width = l/2 - j;
              
              for (int h = 0; h < height; h++)
              {
                  // 서쪽 변
                  ans = std::max(ans, GetCntFish(curY - h, curX, curY + (height - h), curX + width));
                  
                  // 동쪽 변
                  ans = std::max(ans, GetCntFish(curY - h, curX - width, curY + (height - h), curX));
              }
              
              for (int w = 0; w < width; w++)
              {
                  // 북쪽 변
                  ans = std::max(ans, GetCntFish(curY, curX - w, curY + height, curX + (width - w)));
                  
                  // 남쪽 변
                  ans = std::max(ans, GetCntFish(curY - height, curX - w, curY, curX + (width - w)));
              }
          }
      }
 
      // 출력하는 부분
      printf("%d", ans);
      return 0;
}