#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <vector>

#define INF 1000000000

using namespace std;

void dfs(vector<vector<int>> &adj, int root, vector<int> &visited) {
    visited[root] = true;
    for (int xx : adj[root]) {
        if (!visited[xx]) {
            dfs(adj, xx, visited);
        }
    }
}

void solve() {
    int N, M;

    cin >> N >> M;

    vector<vector<int>> adj(N);
    set<vector<int>> edges;

    for (int i = 0; i < M; i++) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;

        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    vector<int> visited(N, false);

    // Go through each vertex

    int ctr = 0;

    for (int i = 0; i < N; i++) {
        if (visited[i] == false) {
            ctr++;
            dfs(adj, i, visited);
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