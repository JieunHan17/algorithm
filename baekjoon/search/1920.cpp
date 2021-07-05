#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
long array1[100000] = {
    0,
};
long array2[100000] = {
    0,
};

int BinarySearch(long key)
{
    int left = 0, right = N - 1, mid;

    while (left <= right)
    {
        mid = (left + right) / 2;
        if (key == array1[mid])
        {
            return 1;
        }
        else if (key < array1[mid])
        {
            right = mid - 1;
        }
        else if (array1[mid] < key)
        {
            left = mid + 1;
        }
    }
    return 0;
}

int main()
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%ld", &array1[i]);
    }
    sort(array1, array1 + N);

    scanf("%d", &M);
    for (int i = 0; i < M; i++)
    {
        scanf("%ld", &array2[i]);
    }
    for (int i = 0; i < M; i++)
    {
        if (BinarySearch(array2[i]))
        {
            printf("1\n");
        }
        else
        {
            printf("0\n");
        }
    }
    return 0;
}