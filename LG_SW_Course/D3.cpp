#include <iostream>

#define MAXN 100

using namespace std;

struct Info
{
    int X;
    int Y;
    int Sm;
    int Pm;
    int Sv;
    int Pv;
};

int N, M;
Info ingredients[MAXN + 10];

bool Check(int target)
{
    int money = M;
    for (int i = 0; i < N; i++)
    {
        int need = target * ingredients[i].X - ingredients[i].Y;
        if (need > 0)
        {
            int onlyLargeAvailableNum = (need + ingredients[i].Sv - 1) / ingredients[i].Sv;
            int onlyLargeAvailableCost = ingredients[i].Pv * onlyLargeAvailableNum;
            int minCost = onlyLargeAvailableCost;
            for (int j = 0; j < onlyLargeAvailableNum; j++)
            {
                int smallAvailableNum = (need - ingredients[i].Sv * j + (ingredients[i].Sm - 1)) / ingredients[i].Sm;
                int cost = ingredients[i].Pv * j + ingredients[i].Pm * smallAvailableNum;
                if (cost < minCost)
                {
                    minCost = cost;
                }
            }
            money -= minCost;
        }
        else
        {
            continue;
        }

        if (money < 0)
        {
            return false;
        }
    }
    return true;
}

int BS(int low, int high) // Upper Bound
{
    if (low > high)
    {
        return high;
    }
    int mid = (low + high) / 2;
    if (Check(mid))
    {
        return BS(mid + 1, high);
    }
    else
    {
        return BS(low, mid - 1);
    }
}

int main(void)
{
    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        cin >> ingredients[i].X >> ingredients[i].Y >> ingredients[i].Sm >> ingredients[i].Pm >> ingredients[i].Sv >> ingredients[i].Pv;
    }
    
    int ans = BS(1, 100000);
    cout << ans << "\n";
    return 0;
}