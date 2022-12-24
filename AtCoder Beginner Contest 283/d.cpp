#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

void solve() {
    string s;
    cin >> s;

    vector<bool> letters(26, false);
    stack<char> ss;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') {
            ss.push('(');
        } else if (s[i] == ')') {
            while (!ss.empty()) {
                char top = ss.top();
                ss.pop();

                if (top == '(') {
                    break;
                } else {
                    letters[(int)(top) - 'a'] = false;
                }
            }
        } else {
            if (letters[(int)(s[i]) - 'a']) {
                cout << "No";
                return;
            }

            letters[(int)(s[i] - 'a')] = true;
            ss.push(s[i]);
        }
    }

    cout << "Yes";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}
