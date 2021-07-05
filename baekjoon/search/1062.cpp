#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

bool check(char alphabet)
{
    return alphabet != 'a' && alphabet != 'n' && alphabet != 't' && alphabet != 'i' && alphabet != 'c';
}

int main()
{
    int N, K;
    string words[50];

    scanf("%d %d", &N, &K);

    if (K < 5)
    {
        printf("0\n");
    }
    else
    {
        for (int i = 0; i < N; i++)
        {
            scanf("%s", words[i]);
        }

        for (int i = 0; i < N; i++)
        {
            int word_size = words[i].size();
            for (int j = 0; j < word_size; j++)
            {
            }
        }
    }
    return 0;
}