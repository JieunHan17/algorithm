#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

#define LIMIT 151
#define MAX 987654321

using namespace std;

int dp[LIMIT][LIMIT];

int solution(int alp, int cop, vector<vector<int>> problems) {
    int answer = MAX;

    int max_alp = 0;
    int max_cop = 0;
    for (int i = 0; i < problems.size(); i++)
    {
        max_alp = max(max_alp, problems[i][0]);
        max_cop = max(max_cop, problems[i][1]);
    }

    for (int i = 0; i < LIMIT; i++)
    {
        for (int j = 0; j < LIMIT; j++)
        {
            dp[i][j] = MAX;
        }
    }
    
    dp[alp][cop] = 0;
    int i = alp;
    int j = cop;
    while (1)
    {
        if (i > 150 || j > 150)
        {
            break;
        }
        if (dp[i][j] == MAX)
        {
            i++;
            continue;
        }
        if (i >= max_alp && j >= max_cop)
        {
            answer = min(answer, dp[i][j]);
            break;
        }
        // 알고력 올리기
        dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + 1);

        // 코딩력 올리기
        dp[i][j + 1] = min(dp[i][j + 1], dp[i][j] + 1);

        // 문제 풀기
        for (int k = 0; k < problems.size(); k++)
        {
            if (i >= problems[k][0] && j >= problems[k][1])
            {
                dp[i + problems[k][2]][j + problems[k][3]] = min(dp[i + problems[k][2]][j + problems[k][3]], dp[i][j] + problems[k][4]);
            }
        }

        i++;
    }

    i = alp;
    j = cop;
    while (1)
    {
        if (i > 150 || j > 150)
        {
            break;
        }
        if (dp[i][j] == MAX)
        {
            j++;
            continue;
        }
        if (i >= max_alp && j >= max_cop)
        {
            answer = min(answer, dp[i][j]);
            break;
        }
        // 알고력 올리기
        dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + 1);

        // 코딩력 올리기
        dp[i][j + 1] = min(dp[i][j + 1], dp[i][j] + 1);

        // 문제 풀기
        for (int k = 0; k < problems.size(); k++)
        {
            if (i >= problems[k][0] && j >= problems[k][1])
            {
                dp[i + problems[k][2]][j + problems[k][3]] = min(dp[i + problems[k][2]][j + problems[k][3]], dp[i][j] + problems[k][4]);
            }
        }

        j++;
    }

    i = alp;
    j = cop;
    while (1)
    {
        if (i > 150 || j > 150)
        {
            break;
        }
        if (dp[i][j] == MAX)
        {
            i++;
            j++;
            continue;
        }
        if (i >= max_alp && j >= max_cop)
        {
            answer = min(answer, dp[i][j]);
            break;
        }
        // 알고력 올리기
        dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + 1);

        // 코딩력 올리기
        dp[i][j + 1] = min(dp[i][j + 1], dp[i][j] + 1);

        // 문제 풀기
        for (int k = 0; k < problems.size(); k++)
        {
            if (i >= problems[k][0] && j >= problems[k][1])
            {
                dp[i + problems[k][2]][j + problems[k][3]] = min(dp[i + problems[k][2]][j + problems[k][3]], dp[i][j] + problems[k][4]);
            }
        }

        i++;
        j++;
    }
    return answer;
}