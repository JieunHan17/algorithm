#include <stdio.h>
#include <algorithm>
#include <queue>
#include <utility>

#define MAXK ((int)5e3)

using namespace std;

int M, N, K;
int SX, SY, DX, DY;
int sol;
struct BUS
{
      int x1, y1, x2, y2;
} bus[MAXK + 10]; //버스 운행 좌표
struct QUE
{
      int n, t; //버스번호, 횟수
};
int visited[MAXK + 10];

bool isPossible(int a, int b)
{
      if ((bus[a].x2 < bus[b].x1) || (bus[b].x2 < bus[a].x1))
      {
            return false;
      }
      if ((bus[a].y2 < bus[b].y1) || (bus[b].y2 < bus[a].y1))
      {
            return false;
      }
      return true;
}

int BFS()
{
      queue<QUE> q;
      fill(visited, visited + MAXK + 10, 0);

      for (int i = 1; i <= K; i++)
      {
            if (SX < bus[i].x1 || bus[i].x2 < SX)
            {
                  continue;
            }
            if (SY < bus[i].y1 || bus[i].y2 < SY)
            {
                  continue;
            }
            q.push({ i, 1 });
            visited[i] = 1;
      }

      while (!q.empty())
      {
            QUE cur = q.front();
            q.pop();

            if (bus[cur.n].x1 <= DX && DX <= bus[cur.n].x2 && bus[cur.n].y1 <= DY && DY <= bus[cur.n].y2)
            {
                  return cur.t;
            }
            for (int i = 1; i <= K; i++)
            {
                  if (visited[i])
                  {
                        continue;
                  }
                  if (!isPossible(cur.n, i))
                  {
                        continue;
                  }
                  q.push({ i, cur.t + 1 });
                  visited[i] = 1;
            }
      }
      return -1;
}

int main()
{
      int i;

      // 입력받는 부분
      scanf("%d%d", &M, &N);
      scanf("%d", &K);
      for (i = 0; i < K; i++)
      {
            int id;
            scanf("%d", &id);
            scanf("%d%d%d%d", &bus[id].x1, &bus[id].y1, &bus[id].x2, &bus[id].y2);
            if (bus[id].x1 == bus[id].x2)
            {
                  if (bus[id].y1 > bus[id].y2)
                  {
                        swap(bus[id].y1, bus[id].y2);
                  }
            }
            else
            {
                  if (bus[id].x1 > bus[id].x2)
                  {
                        swap(bus[id].x1, bus[id].x2);
                  }
            }
      }
      scanf("%d%d%d%d", &SX, &SY, &DX, &DY);

      // 여기서부터 작성
      sol = BFS();

      // 출력하는 부분
      printf("%d", sol);

      return 0;
}