#include <iostream>

using namespace std;

long long int bin_exp(long long int base, long long int exp) {
    if (exp == 0) {
        return 1;
    }

    long long int pow = bin_exp(base, exp / 2);
    pow = pow * pow;

    if (exp % 2 != 0) {
        pow = pow * base;
    }

    return pow;
}

void solve() {
    long long int a, b;
    cin >> a >> b;
    cout << bin_exp(a, b);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}
