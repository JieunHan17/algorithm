#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

int combination[11];
int index[11];
int maximum = 1;
bool flag = false;
vector<int> temp;

int compareScore(vector<int> apeach, vector<int> ryan)
{
    int apeach_score = 0, ryan_score = 0;
    for (int i = 0; i <= 10; i++)
    {
        if (apeach[i] < ryan[i])
        {
            ryan_score += 10 - i;
        }
        else if (apeach[i] == 0 && ryan[i] == 0)
        {
            continue;
        }
        else
        {
            apeach_score += 10 - i;
        }
    }

    return ryan_score - apeach_score;
}

void dfs(int start, int cnt, int n, vector<int> info)
{
    if (cnt == n)
    {
        vector<int> ryan(11, 0);
        for (int i = 0; i < n; i++)
        {
            ryan[combination[i]]++;
        }
        int diff = compareScore(info, ryan);
        if (diff >= maximum)
        {
            maximum = diff;
            flag = true;
            temp = ryan;
        }
        return;
    }
    for (int i = start; i <= 10; i++)
    {
        combination[cnt] = index[i];
        dfs(i, cnt + 1, n, info);
    }
}

vector<int> solution(int n, vector<int> info)
{
    vector<int> answer;
    for (int i = 0; i <= 10; i++)
    {
        index[i] = i;
    }

    dfs(0, 0, n, info);

    if (!flag)
    {
        answer.push_back(-1);
    }
    else
    {
        answer = temp;
    }

    return answer;
}