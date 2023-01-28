#include <cmath>
#include <iostream>
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

bool find_cycle(vector<vector<int>> &adj) {
    color.assign(n, 0);
    parent.assign(n, -1);
    cycle_start = -1;

    for (int v = 0; v < n; v++) {
        if (color[v] == 0 && dfs(v, adj))
            break;
    }

    if (cycle_start == -1) {
        return true;
    } else {
        return false;
    }
}

void dfs(vector<vector<int>> &adj, int root, vector<int> &visited) {
    visited[root] = true;
    for (int xx : adj[root]) {
        if (!visited[xx]) {
            dfs(adj, xx, visited);
        }
    }
}

void solve() {
    int m;
    cin >> n >> m;

    vector<vector<int>> adj(n);

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;

        x--;
        y--;

        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    int two = 0;
    int one = 0;
    for (vector<int> aa : adj) {
        if (aa.size() == 2) {
            two++;
        } else if (aa.size() == 1) {
            one++;
        } else {
            cout << "No";
            return;
        }
    }

    vector<int> visited(n, false);

    int ctr = 0;

    for (int i = 0; i < n; i++) {
        if (visited[i] == false) {
            ctr++;
            dfs(adj, i, visited);
        }
    }

    if (two == n - 2 && one == 2 && !find_cycle(adj) && ctr == 1) {
        cout << "Yes";
    } else {
        cout << "No";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}
