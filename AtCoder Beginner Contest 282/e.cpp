#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

class UFDS {
   public:
    vector<int> p, rank;
    UFDS(const int &num_elements) {
        p.assign(num_elements, 0);
        rank.assign(num_elements, 0);

        for (int i = 0; i < num_elements; i++) {
            p[i] = i;
        }
    }

    int find(const int &i) {
        if (p[i] != i) {
            p[i] = find(p[i]);
        }
        return p[i];
    }

    bool query(const int &a, const int &b) {
        return find(a) == find(b);
    }

    void union_set(const int &a, const int &b) {
        if (!query(a, b)) {
            int x = find(a);
            int y = find(b);

            if (rank[x] > rank[y]) {
                p[y] = x;
            } else {
                p[x] = y;
                if (rank[x] == rank[y]) {
                    rank[y]++;
                }
            }
        }
    }
};

long long int bin_exp(long long int base, long long int exp, long long int MOD) {
    if (exp == 0) {
        return 1;
    }

    long long int pow = bin_exp(base, exp / 2, MOD);
    pow = ((pow % MOD) * (pow % MOD)) % MOD;

    if (exp % 2 != 0) {
        pow = ((pow % MOD) * (base % MOD)) % MOD;
    }

    return pow;
}

void solve() {
    int N, M;
    cin >> N >> M;

    vector<int> vv(N);

    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;

        vv[i] = x;
    }

    vector<pair<long long int, pair<int, int>>> EdgeList(N * N);

    int ctr = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i != j) {
                EdgeList[ctr++] = {(bin_exp(vv[i], vv[j], M) + bin_exp(vv[j], vv[i], M)) % M, {i, j}};

            } else {
                EdgeList[ctr++] = {0, {i, j}};
            }
        }
    }

    // Kruskal's
    sort(EdgeList.rbegin(), EdgeList.rend());  // Max spanning tree
    long long int mst_cost = 0;

    UFDS uu(N);
    for (int i = 0; i < N * N; i++) {
        pair<int, pair<int, int>> front = EdgeList[i];
        if (!uu.query(front.second.first, front.second.second)) {
            mst_cost += front.first;
            uu.union_set(front.second.first, front.second.second);
        }
    }

    cout << mst_cost;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}
