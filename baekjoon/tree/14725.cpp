#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <map>

using namespace std;

struct TRIE
{
    map<string, TRIE *> node;

    void insert(vector<string> v, int index)
    {
        if (index == v.size())
        {
            return;
        }
        if (node.find(v[index]) == node.end())
        {
            node.insert(make_pair(v[index], new TRIE()));
        }
        node[v[index]]->insert(v, index + 1);
    }

    void find(int depth)
    {
        for (map<string, TRIE *>::iterator iter = node.begin(); iter != node.end(); iter++)
        {
            for (int i = 0; i < depth; i++)
            {
                cout << "--";
            }
            cout << iter->first << endl;
            node[iter->first]->find(depth + 1);
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    TRIE *root = new TRIE();
    for (int i = 0; i < N; i++)
    {
        int K;
        cin >> K;
        vector<string> v;
        v.reserve(K);
        for (int j = 0; j < K; j++)
        {
            string t;
            cin >> t;
            v.push_back(t);
        }
        root->insert(v, 0);
    }

    root->find(0);
    return 0;
}