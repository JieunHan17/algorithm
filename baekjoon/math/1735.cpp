#include <cstdio>
#include <algorithm>

using namespace std;

int A_top, A_bottom;
int B_top, B_bottom;

int GCD(int num1, int num2)
{
    if (num2 == 0)
    {
        return num1;
    }
    else
    {
        return GCD(num2, num1 % num2);
    }
}

int LCM(int num1, int num2)
{
    return num1 * (num2 / GCD(num1, num2));
}

int main()
{
    scanf("%d %d", &A_top, &A_bottom);
    scanf("%d %d", &B_top, &B_bottom);

    int common_bottom;
    if (A_bottom >= B_bottom)
    {
        common_bottom = LCM(A_bottom, B_bottom);
    }
    else
    {
        common_bottom = LCM(B_bottom, A_bottom);
    }

    int A_new_top, B_new_top;
    A_new_top = (common_bottom / A_bottom) * A_top;
    B_new_top = (common_bottom / B_bottom) * B_top;

    int result_top = A_new_top + B_new_top;
    int flag;
    if (result_top >= common_bottom)
    {
        flag = GCD(result_top, common_bottom);
    }
    else
    {
        flag = GCD(common_bottom, result_top);
    }

    if (flag == 1)
    {
        printf("%d %d\n", result_top, common_bottom);
    }
    else
    {
        printf("%d %d\n", result_top / flag, common_bottom / flag);
    }

    return 0;
}