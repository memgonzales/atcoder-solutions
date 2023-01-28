#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solve() {
    int a;
    cin >> a;

    vector<string> vv(a);

    for (int i = 0; i < a; i++) {
        cin >> vv[i];
    }

    for (int i = a - 1; i >= 0; i--) {
        cout << vv[i] << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}
