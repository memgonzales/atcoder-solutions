#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<string> vv(n);

    for (int i = 0; i < n; i++) {
        string x;
        cin >> x;
        vv[i] = x;
    }

    int cnt = 0;
    bool ok = true;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            // Check
            ok = true;

            for (int k = 1; k <= m; k++) {
                if (vv[i][k - 1] == 'x' && vv[j][k - 1] == 'x') {
                    ok = false;
                    break;
                }
            }

            if (ok) {
                cnt++;
            }
        }
    }

    cout << cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}