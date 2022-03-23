#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int K, L;
    cin >> K >> L;

    unordered_map<string, int> students;
    for (int i = 0; i < L; i++)
    {
        string student;
        cin >> student;
        students[student] = i;
    }

    vector<pair<int, string> > v;
    for (unordered_map<string, int>::iterator idx = students.begin(); idx != students.end(); idx++)
    {
        v.push_back(make_pair(idx->second, idx->first));
    }
    sort(v.begin(), v.end());

    if (v.size() < K)
    {
        vector<pair<int, string> >::iterator i;
        for (i = v.begin(); i != v.end(); i++)
        {
            cout << (*i).second << '\n';
        }
    }
    else
    {
        for (int i = 0; i < K; i++)
        {
            cout << v[i].second << '\n';
        }
    }

    return 0;
}