#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solve() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    for (int i = 1; i <= n - 1; i++) {
        int ell = n - 1;
        while (true) {
            if (ell + i > n) {
                ell--;
                continue;
            }

            bool bad = false;
            for (int k = 1; k <= ell; k++) {
                if (s[k - 1] == s[k + i - 1]) {
                    bad = true;
                    break;
                }
            }

            if (bad) {
                ell--;
                continue;
            } else {
                cout << ell << "\n";
                break;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}
