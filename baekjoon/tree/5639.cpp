#include <iostream>
#include <cstdio>

using namespace std;

struct node
{
    node *left;
    node *right;
    int key;
};

node *add(node *n, int value)
{
    if (n == NULL)
    {
        n = (node *)malloc(sizeof(node));
        n->key = value;
        n->left = NULL;
        n->right = NULL;
    }
    else if (value < n->key)
    {
        n->left = add(n->left, value);
    }
    else if (value > n->key)
    {
        n->right = add(n->right, value);
    }
    return n;
}

void postorder(node *n)
{
    if (n->left != NULL)
    {
        postorder(n->left);
    }
    if (n->right != NULL)
    {
        postorder(n->right);
    }
    cout << n->key << endl;
}

int main()
{
    int input;
    node *tree = NULL;

    while (cin >> input)
    {
        if (input == EOF)
        {
            break;
        }
        tree = add(tree, input);
    }
    postorder(tree);
    return 0;
}