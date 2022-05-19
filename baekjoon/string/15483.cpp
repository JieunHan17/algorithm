#include <iostream>
#include <string>
#include <algorithm>

#define MAX 1001

using namespace std;

int dp[MAX][MAX];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string A, B;
    cin >> A >> B;

    int lengthA = A.length();
    int lengthB = B.length();
    for (int i = 1; i <= lengthA; i++)
    {
        dp[i][0] = i;
    }
    for (int j = 1; j <= lengthB; j++)
    {
        dp[0][j] = j;
    }
    for (int i = 1; i <= lengthA; i++)
    {
        for (int j = 1; j <= lengthB; j++)
        {
            if (A[i - 1] == B[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = min(dp[i - 1][j - 1] + 1, min(dp[i - 1][j] + 1, dp[i][j - 1] + 1));
            }
        }
    }

    cout << dp[lengthA][lengthB];
    return 0;
}