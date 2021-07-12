#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int N, input[100];
int check[1000001] = {0, 1};
int localPrimeNumCnt[100][80000] = {
    0,
};
int totalPrimeNumCnt[80000] = {
    0,
};
vector<int> prime;

int main()
{
    for (int i = 2; i <= 1000000; i++)
    {
        for (int j = 2; i * j <= 1000000; j++)
        {
            check[i * j] = 1;
        }
    }

    for (int i = 1; i <= 1000000; i++)
    {
        if (check[i] != 1)
        {
            prime.push_back(i);
        }
    }

    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &input[i]);
        for (int j = 0; j < prime.size(); j++)
        {
            while (input[i] % prime[j] == 0)
            {
                localPrimeNumCnt[i][j]++;
                totalPrimeNumCnt[j]++;
                input[i] /= prime[j];
            }
        }
    }

    int GCD = 1;
    int ans_cnt = 0;
    for (int i = 0; i < prime.size(); i++)
    {
        GCD *= pow(prime[i], (totalPrimeNumCnt[i] / N));
        for (int j = 0; j < N; j++)
        {
            int sub = totalPrimeNumCnt[i] / N - localPrimeNumCnt[j][i];
            if (sub > 0)
            {
                ans_cnt += sub;
            }
        }
    }

    printf("%d %d", GCD, ans_cnt);

    return 0;
}