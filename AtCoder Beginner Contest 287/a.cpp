#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

bool isSubsetSum(vector<long long int> set, int n, unsigned long long int sum) {
    if (sum == 0)
        return true;
    if (n == 0)
        return false;

    if (set[n - 1] > sum)
        return isSubsetSum(set, n - 1, sum);

    return isSubsetSum(set, n - 1, sum) || isSubsetSum(set, n - 1, sum - set[n - 1]);
}

void solve() {
    int n;
    cin >> n;

    int x = 0;
    int y = 0;

    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;

        if (str == "For") {
            x++;
        } else {
            y++;
        }
    }

    if (x < y) {
        cout << "No";
    } else {
        cout << "Yes";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}
