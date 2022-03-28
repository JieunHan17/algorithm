#include <iostream>
#include <string>

#define MAX_N 65

using namespace std;

string video[MAX_N];
string answer = "";

bool isDifferent(int N, int startY, int startX)
{
    char init = video[startY][startX];
    bool ans = false;
    for (int i = startY; i < startY + N; i++)
    {
        for (int j = startX; j < startX + N; j++)
        {
            if (video[i][j] != init)
            {
                ans = true;
                return ans;
            }
        }
    }
    return ans;
}

void recur(int N, int startY, int startX)
{
    if (!isDifferent(N, startY, startX))
    {
        answer += video[startY][startX];
        return;
    }
    answer += '(';
    recur(N / 2, startY, startX);
    recur(N / 2, startY, startX + N / 2);
    recur(N / 2, startY + N / 2, startX);
    recur(N / 2, startY + N / 2, startX + N / 2);
    answer += ')';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> video[i];
    }
    recur(N, 0, 0);

    cout << answer;
    return 0;
}