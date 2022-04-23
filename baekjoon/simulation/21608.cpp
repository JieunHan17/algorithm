#include <cstdio>
#include <algorithm>

#define MAX_N 21
#define MAX_STUDENT 401

using namespace std;

int N;
int classroom[MAX_N][MAX_N];
int students[MAX_STUDENT][4];
int dy[4] = {0, -1, 0, 1}; //동북서남
int dx[4] = {1, 0, -1, 0};
int check[MAX_N][MAX_N];
int scores[5] = {0, 1, 10, 100, 1000};

bool first(int student_idx)
{
    int temp[MAX_N][MAX_N];
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            temp[i][j] = -1;
        }
    }
    int maximum = 0;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if (classroom[i][j] == 0)
            {
                int cnt = 0;
                for (int k = 0; k < 4; k++)
                {
                    int nextY = i + dy[k];
                    int nextX = j + dx[k];
                    if (nextY < 1 || nextY > N || nextX < 1 || nextX > N)
                    {
                        continue;
                    }
                    for (int l = 0; l < 4; l++)
                    {
                        if (classroom[nextY][nextX] == students[student_idx][l])
                        {
                            cnt++;
                            break;
                        }
                    }
                }
                temp[i][j] = cnt;
                maximum = max(maximum, cnt);
            }
        }
    }

    int cnt = 0;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if (temp[i][j] == maximum)
            {
                check[i][j] = 1;
                cnt++;
            }
        }
    }

    if (cnt > 1)
    {
        return true;
    }
    else
    {
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                if (check[i][j] == 1)
                {
                    classroom[i][j] = student_idx;
                }
            }
        }
        return false;
    }
}

bool second(int student_idx)
{
    int temp[MAX_N][MAX_N];
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            temp[i][j] = -1;
        }
    }
    int maximum = 0;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if (check[i][j] == 1)
            {
                int cnt = 0;
                for (int k = 0; k < 4; k++)
                {
                    int nextY = i + dy[k];
                    int nextX = j + dx[k];
                    if (nextY < 1 || nextY > N || nextX < 1 || nextX > N)
                    {
                        continue;
                    }
                    if (classroom[nextY][nextX] == 0)
                    {
                        cnt++;
                    }
                }
                temp[i][j] = cnt;
                maximum = max(maximum, cnt);
            }
        }
    }

    int cnt = 0;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if (temp[i][j] == maximum)
            {
                check[i][j] = 2;
                cnt++;
            }
        }
    }

    if (cnt > 1)
    {
        return true;
    }
    else
    {
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                if (check[i][j] == 2)
                {
                    classroom[i][j] = student_idx;
                }
            }
        }
        return false;
    }
}

void third(int student_idx)
{
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if (check[i][j] == 2)
            {
                classroom[i][j] = student_idx;
                return;
            }
        }
    }
}

int getScore()
{
    int total = 0;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            int student_idx = classroom[i][j];
            int cnt = 0;
            for (int k = 0; k < 4; k++)
            {
                int nextY = i + dy[k];
                int nextX = j + dx[k];
                if (nextY < 1 || nextY > N || nextX < 1 || nextX > N)
                {
                    continue;
                }
                for (int l = 0; l < 4; l++)
                {
                    if (classroom[nextY][nextX] == students[student_idx][l])
                    {
                        cnt++;
                        break;
                    }
                }
            }
            total += scores[cnt];
        }
    }

    return total;
}

int main()
{
    scanf("%d", &N);
    int cntOfStudent = N * N;
    for (int i = 1; i <= cntOfStudent; i++)
    {
        int idx;
        scanf("%d", &idx);
        for (int j = 0; j < 4; j++)
        {
            scanf("%d", &students[idx][j]);
        }

        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j<= N; j++)
            {
                check[i][j] = 0;
            }
        }

        bool goToSecond = first(idx);
        if (goToSecond)
        {
            bool goToThird = second(idx);
            if (goToThird)
            {
                third(idx);
            }
        }
    }
    int ans = getScore();
    printf("%d", ans);
    return 0;
}