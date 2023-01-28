#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solve() {
    int n;
    cin >> n;

    int ctr = 1;
    for (int i = 100000000; i <= 999999999; i++) {
        if (i / 100000000 == i / 10000000 % 10 && i / 10000 % 10 == i / 1000 % 10 && i / 100 % 10 == i % 10) {
            if (ctr == n) {
                cout << i;
                break;
            }
            ctr++;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}
