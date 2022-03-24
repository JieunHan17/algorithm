#include <iostream>
#include <string>
#include <unordered_map>

#define MAX_LENGTH 11
#define MAX_K 1001

using namespace std;

string board[MAX_LENGTH];
int N, M, K;
int dy[8] = {0, -1, -1, -1, 0, 1, 1, 1}; // 동쪽부터 시작해서 시계 반대 방향으로
int dx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
unordered_map<string, int> m;

void dfs(int startY, int startX, int depth, string str)
{
    if (depth == 5)
    {
        return;
    }

    m[str]++;

    for (int i = 0; i < 8; i++)
    {
        int nextY = startY + dy[i];
        int nextX = startX + dx[i];

        nextY = nextY < 0 ? N - 1 : nextY;
        nextY = nextY >= N ? 0 : nextY;
        nextX = nextX < 0 ? M - 1 : nextX;
        nextX = nextX >= M ? 0 : nextX;

        dfs(nextY, nextX, depth + 1, str + board[nextY][nextX]);        
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M >> K;
    
    for (int i = 0; i < N; i++)
    {
        cin >> board[i];
    }

    string str;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            dfs(i, j, 0, str + board[i][j]);
        }
    }

    while (K--)
    {
        string input;
        cin >> input;
        cout << m[input] << '\n';
    }

    
    return 0;
}