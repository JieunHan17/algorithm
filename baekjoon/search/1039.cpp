#include <stdio.h>
#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

int N, K;
queue<int> q;
bool visited[1000000][11] = {
    true,
};

int toInt(string str)
{
    int length = str.length();
    int result = 0;
    for (int i = 0; i < length; i++)
    {
        result += (str[i] - '0') * pow(10, length - 1 - i);
    }
    return result;
}

int swap(int num, int start, int end)
{
    string num_string = to_string(num);
    char buf;

    if (num_string[start] == num_string[end])
    {
        return num;
    }

    buf = num_string[start];
    num_string[start] = num_string[end];
    num_string[end] = buf;

    if (num_string[0] == '0')
    {
        return -1;
    }

    return toInt(num_string);
}

bool validate(int num)
{
    if (num < 10)
    {
        return false;
    }
    else if (num < 100 && num % 10 == 0)
    {
        return false;
    }
    else
    {
        return true;
    }
}

int getLength(int num)
{
    int length = 0;
    while (num > 0)
    {
        length++;
        num /= 10;
    }
    return length;
}

int main()
{
    scanf("%d %d", &N, &K);
    int N_length = getLength(N);
    if (N == 1000000)
    {
        printf("1000000\n");
        return 0;
    }
    if (!validate(N))
    {
        printf("-1\n");
        return 0;
    }
    q.push(N);
    visited[N][0] = true;

    while (!q.empty())
    {
        for (int i = 0; i < K; i++)
        {
            int q_size = q.size();
            for (int j = 0; j < q_size; j++)
            {
                int cur = q.front();
                q.pop();

                // cout << cur << endl;

                vector<int> temp;
                for (int k = 0; k < N_length - 1; k++)
                {
                    for (int l = k + 1; l < N_length; l++)
                    {
                        int next = swap(cur, k, l);
                        // cout << "next: " << next << endl;
                        if (next != -1 && !visited[next][i])
                        {
                            q.push(next);
                            visited[next][i] = true;
                        }
                    }
                }
            }
        }
    }

    int max = 0;
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        if (max <= cur)
        {
            max = cur;
        }
    }
    printf("%d\n", max);
    return 0;
}