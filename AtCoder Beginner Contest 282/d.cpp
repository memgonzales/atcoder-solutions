#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <vector>

#define INF 1000000000

using namespace std;

bool bipartite(vector<set<int>> &adj, int root, vector<int> &color, int &black, int &white, int &size) {
    queue<int> q;
    q.push(root);

    bool isBipartite = true;
    color[root] = 0;
    black++;

    while (!q.empty() && isBipartite) {
        int u = q.front();
        q.pop();

        for (auto v : adj[u]) {
            size++;

            if (color[v] == INF) {
                color[v] = 1 - color[u];
                if (color[v] == 1) {
                    white++;
                } else {
                    black++;
                }
                q.push(v);
            } else if (color[v] == color[u]) {
                isBipartite = false;
                break;
            }
        }
    }

    return isBipartite;
}

void solve() {
    int N, M;

    cin >> N >> M;

    vector<set<int>> adj(N);
    set<vector<int>> edges;

    for (int i = 0; i < M; i++) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;

        adj[x].insert(y);
        adj[y].insert(x);
    }

    vector<int> color(N, INF);

    bool isBipartite = true;

    vector<int> blacks;
    vector<int> whites;
    vector<int> sizes;

    // Go through each vertex
    for (int i = 0; i < N; i++) {
        // Visited
        if (color[i] != INF) {
            continue;
        }

        int black = 0, white = 0, size = 0;

        isBipartite = isBipartite & bipartite(adj, i, color, black, white, size);

        if (!isBipartite) {
            cout << 0;
            return;
        }

        blacks.push_back(black);
        whites.push_back(white);
        sizes.push_back(size / 2);  // Prevent double counting
    }

    long long int ret = 0;

    // Same connected component
    for (int i = 0; i < blacks.size(); i++) {
        ret += blacks[i] * 1LL * whites[i] - sizes[i];
    }

    // Different connected components
    long long int diff = 0;
    for (int i = 0; i < blacks.size(); i++) {
        // all vertices - vertices of connected component
        diff += (blacks[i] + whites[i]) * 1LL * (N - blacks[i] - whites[i]);
    }

    cout << ret + diff / 2;  // Prevent double counting
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}