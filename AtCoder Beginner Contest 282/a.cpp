#include <iostream>

using namespace std;

void solve()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << (char)('A' + i);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}