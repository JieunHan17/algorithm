#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

int N, M;
string board[50];

int main()
{
    scanf("%d %d", &N, &M);

    for (int i = 0; i < N; i++)
    {
        scanf("%s", &board[i]);
    }
    return 0;
}