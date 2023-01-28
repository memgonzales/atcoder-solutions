#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solve() {
    int x, y;
    cin >> x >> y;

    if (y == x * 2 || y == x * 2 + 1) {
        cout << "Yes";
    } else {
        cout << "No";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}
