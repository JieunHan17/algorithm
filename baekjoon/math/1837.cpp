#include <iostream>
#include <string>
#include <algorithm>

#define MAX 1000001

using namespace std;

bool divide(string P, int num)
{
    int len = P.length();
    int sum = 0;
    for (int i = 0; i < len; i++)
    {
        sum = (sum * 10 + (P[i] - '0')) % num;
    }
    if (sum == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string P;
    int K;
    cin >> P >> K;

    bool prime[MAX];
    fill(prime, prime + MAX, true);
    prime[0] = false;
    prime[1] = false;
    for (int i = 2; i < MAX; i++)
    {
        for (int j = 2; i * j < MAX; j++)
        {
            prime[i * j] = false;
        }
    }

    for (int i = 2; i < K; i++)
    {
        if (prime[i])
        {
            bool result = divide(P, i);
            if (result)
            {
                cout << "BAD " << i << endl;
                return 0;
            }
        }
    }
    cout << "GOOD" << endl;

    return 0;
}