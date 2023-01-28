#include <iostream>
#include <map>
#include <vector>

using namespace std;

int n;
vector<char> color;
vector<int> parent;
int cycle_start, cycle_end;

bool dfs(int v, vector<vector<int>> &adj) {
    color[v] = 1;
    for (int u : adj[v]) {
        if (color[u] == 0) {
            parent[u] = v;
            if (dfs(u, adj))
                return true;
        } else if (color[u] == 1) {
            cycle_end = v;
            cycle_start = u;
            return true;
        }
    }
    color[v] = 2;
    return false;
}

void find_cycle(vector<vector<int>> &adj) {
    color.assign(n, 0);
    parent.assign(n, -1);
    cycle_start = -1;

    for (int v = 0; v < n; v++) {
        if (color[v] == 0 && dfs(v, adj))
            break;
    }

    if (cycle_start == -1) {
        cout << "Yes";
    } else {
        cout << "No";
    }
}

void solve() {
    int M;
    cin >> M;

    vector<vector<int>> adj(200000);
    map<string, int> ss;

    for (int i = 0; i < M; i++) {
        string x, y;
        cin >> x >> y;

        if (!ss.count(x)) {
            ss[x] = ss.size();
        }

        if (!ss.count(y)) {
            ss[y] = ss.size();
        }

        adj[ss[x]].push_back(ss[y]);
    }

    n = ss.size();

    find_cycle(adj);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}