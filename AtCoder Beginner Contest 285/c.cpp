#include <cmath>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solve() {
    string s;
    cin >> s;

    long long int mult = 0;
    long long int ans = 0;
    for (int i = s.size() - 1; i >= 0; i--) {
        ans += (s[i] - 'A' + 1) * powl(26, mult);
        mult++;
    }

    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}
