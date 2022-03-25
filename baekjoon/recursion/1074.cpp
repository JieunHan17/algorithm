#include <cstdio>

using namespace std;

int recur(int N, int r, int c)
{
    if (N == 0)
    {
        return 0;
    }
    int half = 1<<(N - 1);

    if (r < half && c < half)
        return recur(N - 1, r, c);
    else if (r < half && c >= half)
        return half * half + recur(N - 1, r, c - half);
    else if (r >= half && c < half)
        return 2 * half * half + recur(N - 1, r - half, c);
    else
        return 3 * half * half + recur(N - 1, r - half, c - half);
}

int main()
{
    int N, r, c;
    scanf("%d %d %d", &N, &r, &c);
    printf("%d", recur(N, r, c));

    return 0;
}