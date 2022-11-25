#include <stdio.h>
 
int M, N, K;
int ID[5000+10];
int X1[5000+10], Y1[5000+10];
int X2[5000+10], Y2[5000+10];
int SX, SY, DX, DY;
int sol;
 
int main()
{
      int i;
 
      // 입력받는 부분
      scanf("%d%d", &M, &N);
      scanf("%d", &K);
      for (i = 0; i < K; i++) {
            scanf("%d%d%d%d%d", &ID[i], &X1[i], &Y1[i], &X2[i], &Y2[i]);
      }
      scanf("%d%d%d%d", &SX, &SY, &DX, &DY);
 
      // 여기서부터 작성
 
      // 출력하는 부분
      printf("%d", sol);
 
      return 0;
}