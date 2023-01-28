#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int n;
    cin >> n;

    int x = 0;
    int y = 0;

    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;

        if (str == "For") {
            x++;
        } else {
            y++;
        }
    }

    if (x < y) {
        cout << "No";
    } else {
        cout << "Yes";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}
