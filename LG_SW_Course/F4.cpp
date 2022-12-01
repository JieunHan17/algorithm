#include <iostream>
#include <vector>
#include <utility>

#define MAX_NUM 12

using namespace std;

char map[5][10];
pair<int, int> coordinates[6][4] = {
    {make_pair(0, 4), make_pair(1, 3), make_pair(2, 2), make_pair(3, 1)},
    {make_pair(0, 4), make_pair(1, 5), make_pair(2, 6), make_pair(3, 7)},
    {make_pair(3, 1), make_pair(3, 3), make_pair(3, 5), make_pair(3, 7)},
    {make_pair(1, 1), make_pair(2, 2), make_pair(3, 3), make_pair(4, 4)},
    {make_pair(1, 7), make_pair(2, 6), make_pair(3, 5), make_pair(4, 4)},
    {make_pair(1, 1), make_pair(1, 3), make_pair(1, 5), make_pair(1, 7)},
}; // 6개의 줄에 해당하는 각 좌표 4개씩
vector<pair<int, int> > empty;
bool used[MAX_NUM + 10];

void InputData()
{
    for (int h = 0; h < 5; h++)
    {
        cin >> map[h];
        for (int w = 0; w < 9; w++)
        {
            if (map[h][w] == 'x')
            {
                empty.push_back(make_pair(h, w));
            }
            else if (map[h][w] >= 'A' && map[h][w] <= 'L')
            {
                used[map[h][w] - 'A' + 1] = true;
            }
        }
    }
}

void OutputData()
{
    for (int h = 0; h < 5; h++)
    {
        cout << map[h] << endl;
    }
}

bool Check()
{
    for (int i = 0; i < 6; i++)
    {
        int total = 0;
        bool skip = false;
        for (int j = 0; j < 4; j++)
        {
            int y = coordinates[i][j].first;
            int x = coordinates[i][j].second;
            if (map[y][x] == 'x')
            {
                skip = true;
                break;
            }
            total += (map[y][x] - 'A' + 1);
        }
        if (!skip && total != 26)
        {
            return false;
        }
    }
    return true;
}

bool DFS(int cnt)
{
    if (cnt == empty.size())
    {
        return true;
    }

    for (int i = 1; i <= 12; i++)
    {
        if (!used[i])
        {
            used[i] = true;
            map[empty[cnt].first][empty[cnt].second] = i - 1 + 'A';
            if (Check())
            {
                if (DFS(cnt + 1))
                {
                    return true;
                }
            }
            map[empty[cnt].first][empty[cnt].second] = 'x';
            used[i] = false;
        }
    }
    return false;
}

int main()
{
    InputData(); //입력받는 부분

    //여기서부터 작성
    DFS(0);

    OutputData(); //출력하는 부분
    return 0;
}

/*
A: 1
B: 2
C: 3
D: 4
E: 5
F: 6
G: 7
H: 8
I: 9
J: 10
K: 11
L: 12

2 + 9 + 5 + 7 = 23
*/