#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solve() {
    string s;
    cin >> s;

    long long int ctr = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] != '0') {
            ctr++;
        } else {
            if (s[i] == '0') {
                if (s[i + 1] != '0') {
                    ctr++;
                } else {
                    i++;
                    ctr++;
                }
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
