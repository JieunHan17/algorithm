#include <iostream>
#include <vector>
#include <utility>

using namespace std;

#define MAXN (9)

int sudoku[MAXN][MAXN];
vector<pair<int, int> > empty;
bool usedRow[MAXN+10][MAXN+10];
bool usedCol[MAXN+10][MAXN+10];
bool usedCell[MAXN+10][MAXN+10];

void InputData(){
    for (int r=0; r<MAXN; r++){
        for (int c=0; c<MAXN; c++){
            cin >> sudoku[r][c];
            if (sudoku[r][c] == 0)
            {
                empty.push_back(make_pair(r, c));
            }
            else
            {
                usedRow[r][sudoku[r][c]] = true;
                usedCol[c][sudoku[r][c]] = true;
                int cellIdx = (r / 3) * 3 + (c / 3);
                usedCell[cellIdx][sudoku[r][c]] = true;
            }
        }
    }
}

void OutputData(){
    for (int r=0; r<MAXN; r++){
        for (int c=0; c<MAXN; c++){
            cout << sudoku[r][c] << " ";
        }
        cout << endl;
    }
}

bool DFS(int idx)
{
    if (idx == empty.size())
    {
        return true;
    }
    
    int y = empty[idx].first;
    int x = empty[idx].second;
    int cellIdx = (y / 3) * 3 + (x / 3);

    for (int i = 1; i <= 9; i++)
    {
        if (!usedRow[y][i] && !usedCol[x][i] && !usedCell[cellIdx][i])
        {
            usedRow[y][i] = true;
            usedCol[x][i] = true;
            usedCell[cellIdx][i] = true;
            sudoku[y][x] = i;
            if (DFS(idx + 1))
            {
                return true;
            }
            usedRow[y][i] = false;
            usedCol[x][i] = false;
            usedCell[cellIdx][i] = false;
            sudoku[y][x] = 0;
        }
    }
    return false;
}

int main(){
    InputData();//입력받는 부분

    //여기서부터 작성
    DFS(0);

    OutputData();//출력하는 부분
    return 0;
}
