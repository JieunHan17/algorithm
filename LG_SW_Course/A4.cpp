#include <stdio.h>
  
#define MAXN 1000
 
int C, R, K;
int X, Y;
int stadium[MAXN + 10][MAXN + 10];
int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};
int dir = 3;
  
int main(void)
{
      // 입력받는 부분
      scanf("%d %d", &C, &R);
      scanf("%d", &K);
  
      // 여기서부터 작성
      int startY = R;
      int startX = 1;
      stadium[startY][startX] = 1;
      for (int i = 2; i <= C * R; i++)
      {
          int nextY = startY + dy[dir];
          int nextX = startX + dx[dir];
          if (nextY <= 0 || nextY > R || nextX <= 0 || nextX > C || stadium[nextY][nextX] != 0)
          {
              i--;
              dir = (dir + 1) % 4;
              continue;
          }
          stadium[nextY][nextX] = i;
          startY = nextY;
          startX = nextX;
      }
       
       
      for (int i = 1; i <= R; i++)
      {
          for (int j = 1; j <= C; j++)
          {
              if (stadium[i][j] == K)
              {
                  X = j;
                  Y = R - i + 1;
              }
          }
      }
       
      // 출력하는 부분
      if(C * R < K) printf("0");
      else printf("%d %d", X, Y);
  
      return 0;
} 