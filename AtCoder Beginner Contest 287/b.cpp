#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int x, y;
    cin >> x >> y;

    vector<int> vv(x);
    for (int i = 0; i < x; i++) {
        cin >> vv[i];
    }

    vector<int> nn(y);
    for (int i = 0; i < y; i++) {
        cin >> nn[i];
    }

    int ctr = 0;
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            if (vv[i] % 1000 == nn[j]) {
                ctr++;
                break;
            }
        }
    }

    cout << ctr;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}
