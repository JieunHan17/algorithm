#include <cstdio>
#include <vector>
#include <utility>
#include <queue>
#include <algorithm>

#define MAX_N 21
#define MAX_M 401

using namespace std;

int N, M, gas;
int board[MAX_N][MAX_N];
int taxiY, taxiX;
pair<int, int> customers_depart[MAX_M];
pair<int, int> customers_arrive[MAX_M];
int dy[4] = {-1, 0, 1, 0}; // 북동남서
int dx[4] = {0, 1, 0, -1};
int cntOfCustomers;
int gasToCharge = 0;

bool compare(pair<int, int> cust1, pair<int, int> cust2)
{
    if (cust1.first < cust2.first)
    {
        return true;
    }
    else if (cust1.first == cust2.first)
    {
        if (customers_depart[cust1.second].first < customers_depart[cust2.second].first)
        {
            return true;
        }
        else if (customers_depart[cust1.second].first == customers_depart[cust2.second].first)
        {
            return customers_depart[cust1.second].second < customers_depart[cust2.second].second;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}

int findCustomer()
{
    queue<pair<int, int> > q;
    q.push(make_pair(taxiY, taxiX));

    int dist[MAX_N][MAX_N];
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            dist[i][j] = -1;
        }
    }
    dist[taxiY][taxiX] = 0;

    /* 택시와 승객이 같은 위치에 서 있는 경우 */
    if (board[taxiY][taxiX] >= 1)
    {
        return board[taxiY][taxiX];
    }
    
    vector<pair<int, int> > candidates;
    while (!q.empty())
    {
        int curY = q.front().first;
        int curX = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nextY = curY + dy[i];
            int nextX = curX + dx[i];
            if (nextY < 1 || nextY > N || nextX < 1 || nextX > N)
            {
                continue;
            }
            if (dist[nextY][nextX] < 0 && board[nextY][nextX] != -1)
            {
                if (board[nextY][nextX] >= 1)
                {
                    candidates.push_back(make_pair(dist[curY][curX] + 1, board[nextY][nextX]));
                }
                q.push(make_pair(nextY, nextX));
                dist[nextY][nextX] = dist[curY][curX] + 1;
            }
        }
    }

    if (candidates.empty())
    {
        return 0;
    }
    else
    {
        sort(candidates.begin(), candidates.end(), compare);
        gas -= candidates[0].first;
        if (gas <= 0)
        {
            return 0;
        }
        return candidates[0].second;
    }
    
}

bool moveCustomer(int idxOfCustomer)
{
    queue<pair<int, int> > q;
    q.push(make_pair(taxiY, taxiX));

    int dist[MAX_N][MAX_N];
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            dist[i][j] = -1;
        }
    }
    dist[taxiY][taxiX] = 0;

    while (!q.empty())
    {
        int curY = q.front().first;
        int curX = q.front().second;
        q.pop();

        if (curY == customers_arrive[idxOfCustomer].first && curX == customers_arrive[idxOfCustomer].second)
        {
            gas -= dist[curY][curX];
            if (gas < 0)
            {
                return false;
            }
            gasToCharge = dist[curY][curX] * 2;
            return true;
        }

        for (int i = 0; i < 4; i++)
        {
            int nextY = curY + dy[i];
            int nextX = curX + dx[i];
            if (nextY < 1 || nextY > N || nextX < 1 || nextX > N)
            {
                continue;
            }
            if (dist[nextY][nextX] < 0 && board[nextY][nextX] != -1)
            {
                q.push(make_pair(nextY, nextX));
                dist[nextY][nextX] = dist[curY][curX] + 1;
            }
        }
    }
    return false;
}

int main()
{
    scanf("%d %d %d", &N, &M, &gas);
    cntOfCustomers = M;

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            scanf("%d", &board[i][j]);
            if (board[i][j] == 1)
            {
                // 벽을 -1로 대체
                board[i][j] = -1;
            }
        }
    }
    scanf("%d %d", &taxiY, &taxiX);
    for (int i = 1; i <= M; i++)
    {
        int departY, departX, arriveY, arriveX;
        scanf("%d %d %d %d", &departY, &departX, &arriveY, &arriveX);
        board[departY][departX] = i;
        customers_depart[i] = make_pair(departY, departX);
        customers_arrive[i] = make_pair(arriveY, arriveX);
    }

    while (cntOfCustomers > 0)
    {
        int idxOfCustomer = findCustomer();
        if (idxOfCustomer == 0)
        {
            printf("-1");
            return 0;
        }
        else
        {
            taxiY = customers_depart[idxOfCustomer].first;
            taxiX = customers_depart[idxOfCustomer].second;
            bool arrived = moveCustomer(idxOfCustomer);
            if (!arrived)
            {
                printf("-1");
                return 0;
            }
            board[taxiY][taxiX] = 0;
            cntOfCustomers--;
            gas += gasToCharge;
            taxiY = customers_arrive[idxOfCustomer].first;
            taxiX = customers_arrive[idxOfCustomer].second;
        }
    }
    printf("%d", gas);
    return 0;
}