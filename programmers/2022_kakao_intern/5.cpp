#include <string>
#include <vector>
#include <utility>

#define MAX 50001

using namespace std;

vector<vector<int>> solution(vector<vector<int>> rc, vector<string> operations) {
    vector<vector<int>> answer;

    int height = rc.size();
    int width = rc[0].size();
    int cnt_outside = width * 2 + (height - 2) * 2;

    vector<pair<int, int> > outside;
    for (int j = 1; j < width; j++)
    {
        outside.push_back(make_pair(0, j));
    }
    for (int i = 1; i < height - 1; i++)
    {
        outside.push_back(make_pair(i, width - 1));
    }
    for (int j = width - 1; j > 0; j--)
    {
        outside.push_back(make_pair(height - 1, j));
    }
    for (int i = height - 1; i >= 0; i--)
    {
        outside.push_back(make_pair(i, 0));
    }

    vector<pair<string, int> > op;
    int start = 0;
    int end;
    string cur_op = operations[0];
    for (end = 1; end < operations.size(); end++)
    {
        if (cur_op != operations[end])
        {
            int cnt;
            if (cur_op == "ShiftRow")
            {
                cnt = (end - start) % height;
            }
            else
            {
                cnt = (end - start) % (width * 2 + (height - 2) * 2);
            }
            op.push_back(make_pair(cur_op, cnt));
            start = end;
            cur_op = operations[end];
        }
    }
    if (cur_op == "ShiftRow")
    {
        op.push_back(make_pair(cur_op, (end - start) % height));
    }
    else
    {
        op.push_back(make_pair(cur_op, (end - start) % (width * 2 + (height - 2) * 2)));
    }

    for (int k = 0; k < op.size(); k++)
    {
        if (op[k].first == "ShiftRow")
        {
            int rc_copy[height][width];
            for (int i = 0; i < height; i++)
            {
                int newRow = (i + op[k].second) % height;
                for (int j = 0; j < width; j++)
                {
                    rc_copy[newRow][j] = rc[i][j];
                }
            }
            for (int i = 0; i < height; i++)
            {
                for (int j = 0; j < width; j++)
                {
                    rc[i][j] = rc_copy[i][j];
                }
            }
        }
        else
        {
            vector<int> outside_value;
            for (int i = 0; i < cnt_outside; i++)
            {
                outside_value.push_back(rc[outside[i].first][outside[i].second]);
            }
            for (int i = 0; i < cnt_outside; i++)
            {
                int next = (i + op[k].second) % cnt_outside;
                int nextRow = outside[next].first;
                int nextCol = outside[next].second;
                rc[nextRow][nextCol] = outside_value[i];
            }
        }
    }

    answer = rc;
    return answer;
}