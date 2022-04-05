#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>

#define MAX 9

using namespace std;

int N, M;
int office[MAX][MAX];
int office_copy[MAX][MAX];
int dy[4] = {0, -1, 0, 1}; // 동(0) 북(1) 서(2) 남(3)
int dx[4] = {1, 0, -1, 0};
vector<pair<int, int> > cctv;

void mark(int y, int x, int dir)
{
    dir %= 4; // dir로 4 이상의 숫자가 들어오면 인덱스가 맞지 않기 때문
    while (1)
    {
        y += dy[dir];
        x += dx[dir];
        if (y < 0 || y >= N || x < 0 || x >= M || office_copy[y][x] == 6)
        {
            return;
        }
        if (office_copy[y][x] != 0)
        {
            continue;
        }
        office_copy[y][x] = -1;
    }

}

int main()
{
    scanf("%d %d", &N, &M);

    int minimum = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            scanf("%d", &office[i][j]);
            if (office[i][j] != 0 && office[i][j] != 6)
            {
                cctv.push_back(make_pair(i, j));
            }
            if (office[i][j] == 0) // cctv가 하나도 없을 때 대비
            {
                minimum++;
            }
        }
    }

    for (int temp = 0; temp < (1<<(2*cctv.size())); temp++) // 1<<(2*cctv.size())는 4의 cctv.size()승
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                office_copy[i][j] = office[i][j];
            }
        }
        int num = temp;
        for (int i = 0; i < cctv.size(); i++)
        {
            int dir = num % 4;
            num /= 4;

            int curY = cctv[i].first;
            int curX = cctv[i].second;

            if (office[curY][curX] == 1)
            {
                mark(curY, curX, dir);
            }
            else if (office[curY][curX] == 2)
            {
                mark(curY, curX, dir);
                mark(curY, curX, dir + 2);
            }
            else if (office[curY][curX] == 3)
            {
                mark(curY, curX, dir);
                mark(curY, curX, dir + 1);
            }
            else if (office[curY][curX] == 4)
            {
                mark(curY, curX, dir);
                mark(curY, curX, dir + 1);
                mark(curY, curX, dir + 2);
            }
            else
            {
                mark(curY, curX, dir);
                mark(curY, curX, dir + 1);
                mark(curY, curX, dir + 2);
                mark(curY, curX, dir + 3);
            }
        }

        int cnt = 0;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                if (office_copy[i][j] == 0)
                {
                    cnt++;
                }
            }
        }
        minimum = min(minimum, cnt);
    }

    printf("%d", minimum);
    return 0;
}