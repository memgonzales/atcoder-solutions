#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solve() {
    int N;
    string ans;

    cin >> N >> ans;

    bool in = false;
    for (int i = 0; i < N; i++) {
        if (ans[i] == '"') {
            in = !in;
        } else if (!in && ans[i] == ',') {
            ans[i] = '.';
        }
    }

    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}