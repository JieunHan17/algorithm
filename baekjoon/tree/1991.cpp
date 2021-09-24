#include <iostream>
#include <vector>

using namespace std;

struct tree
{
    int left;
    int right;
};

vector<tree> v(26);

void preorder(int node)
{
    if (node != '.' - 'A')
    {
        cout << (char)(node + 'A');
        preorder(v[node].left);
        preorder(v[node].right);
    }
    return;
}

void inorder(int node)
{
    if (node != '.' - 'A')
    {
        inorder(v[node].left);
        cout << (char)(node + 'A');
        inorder(v[node].right);
    }
    return;
}

void postorder(int node)
{
    if (node != '.' - 'A')
    {
        postorder(v[node].left);
        postorder(v[node].right);
        cout << (char)(node + 'A');
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        char node, left, right;
        cin >> node >> left >> right;
        v[node - 'A'].left = left - 'A';
        v[node - 'A'].right = right - 'A';
    }

    preorder(0);
    cout << endl;
    inorder(0);
    cout << endl;
    postorder(0);
    cout << endl;

    return 0;
}