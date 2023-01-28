#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solve() {
    int a;
    cin >> a;

    int ctr = 0;
    for (int i = 0; i < a; i++) {
        int x;
        cin >> x;

        if (x % 2 != 0) {
            ctr++;
        }
    }

    cout << ctr << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        solve();
    }

    return 0;
}
