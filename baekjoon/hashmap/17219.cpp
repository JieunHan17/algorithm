#include <iostream>
#include <unordered_map>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    unordered_map<string, string> m;
    while (N--)
    {
        string addr, pwd;
        cin >> addr >> pwd;
        m[addr] = pwd;
    }

    while (M--)
    {
        string input_addr;
        cin >> input_addr;
        cout << m[input_addr] << '\n';
    }

    return 0;
}