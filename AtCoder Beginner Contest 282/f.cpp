#include <cmath>
#include <iostream>
#include <map>

using namespace std;

int log2_flr(unsigned long long i) {
    return i ? __builtin_clzll(1) - __builtin_clzll(i) : -1;
}

void solve() {
    // Inspired by sparse tables
    int N;
    cin >> N;

    map<pair<int, int>, int> mm;

    // 2^j <= N
    for (int j = 0; (1 << j) <= N; j++) {
        // i + 2^j <= N
        for (int i = 0; i + (1 << j) <= N; i++) {
            mm[{i + 1, i + (1 << j)}] = 0;
        }
    }

    cout << mm.size() << endl;

    int ctr = 0;
    for (auto m : mm) {
        mm[{m.first.first, m.first.second}] = ++ctr;
        cout << m.first.first << " " << m.first.second << endl;
    }

    int Q;
    cin >> Q;

    for (int i = 0; i < Q; i++) {
        int L, R;
        cin >> L >> R;

        // [2, 7] = [2, 5] U [5, 7]
        // 6 terms
        int lg = log2_flr(R - L + 1);
        cout << mm[{L, L + (1 << lg) - 1}] << " " << mm[{R - (1 << lg) + 1, R}] << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}
