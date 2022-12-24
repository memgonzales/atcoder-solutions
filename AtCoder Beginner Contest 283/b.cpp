#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> vv(n);

    for (int i = 0; i < n; i++) {
        cin >> vv[i];
    }

    int q;
    cin >> q;

    for (int i = 0; i < q; i++) {
        int x;
        cin >> x;

        if (x == 1) {
            int k, y;
            cin >> k >> y;
            vv[k - 1] = y;
        } else {
            int k;
            cin >> k;
            cout << vv[k - 1] << "\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}
