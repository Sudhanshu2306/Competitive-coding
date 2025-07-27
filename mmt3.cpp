#include <bits/stdc++.h>
using namespace std;
using ll = long long;

static const ll INF = (ll)-4e18;

// Compute total reward obtainable from one edge weight z
ll edgeTotal(ll z) {
    if (z <= 0) return 0;
    long double d = 1.0L + 8.0L * z;
    ll k = (ll)((1 + sqrt(d)) / 2);
    while (k * (k - 1) / 2 > z) --k;
    while ((k + 1) * k / 2 <= z) ++k;
    return k * z - (k * (k + 1) * (k - 1)) / 6;
}

void dfs1(int u, const vector<vector<pair<int,ll>>> &g, vector<char> &vis, vector<int> &order) {
    vis[u] = 1;
    for (auto &e : g[u]) {
        if (!vis[e.first]) dfs1(e.first, g, vis, order);
    }
    order.push_back(u);
}

void dfs2(int u, const vector<vector<pair<int,ll>>> &rg, vector<int> &comp, int id) {
    comp[u] = id;
    for (auto &e : rg[u]) {
        if (comp[e.first] == -1) dfs2(e.first, rg, comp, id);
    }
}

ll maximumReward(int A, int B, const vector<vector<ll>> &C) {
    int n = A;
    int m = C.size();
    vector<vector<pair<int,ll>>> g(n), rg(n);
    // Build graph and reverse graph
    for (const auto &e : C) {
        int u = (int)e[0] - 1;
        int v = (int)e[1] - 1;
        ll z = e[2];
        g[u].push_back({v, z});
        rg[v].push_back({u, z});
    }
    // Kosaraju order
    vector<char> vis(n, 0);
    vector<int> order;
    for (int i = 0; i < n; ++i) {
        if (!vis[i]) dfs1(i, g, vis, order);
    }
    // Assign components
    vector<int> comp(n, -1);
    int cid = 0;
    for (int i = n - 1; i >= 0; --i) {
        int u = order[i];
        if (comp[u] == -1) dfs2(u, rg, comp, cid++);
    }
    // Compute intra-SCC rewards and DAG edges
    vector<ll> inReward(cid, 0);
    vector<vector<pair<int,ll>>> dag(cid);
    vector<int> indeg(cid, 0);
    for (const auto &e : C) {
        int u = (int)e[0] - 1;
        int v = (int)e[1] - 1;
        ll z = e[2];
        int cu = comp[u], cv = comp[v];
        if (cu == cv) {
            inReward[cu] += edgeTotal(z);
        } else {
            dag[cu].push_back({cv, z});
            ++indeg[cv];
        }
    }
    // DP on condensation DAG
    vector<ll> dp(cid, INF);
    int start = comp[B - 1];
    dp[start] = inReward[start];
    queue<int> q;
    for (int i = 0; i < cid; ++i) {
        if (indeg[i] == 0) q.push(i);
    }
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (auto &ed : dag[u]) {
            int v = ed.first;
            ll w = ed.second;
            if (dp[u] != INF) {
                dp[v] = max(dp[v], dp[u] + w + inReward[v]);
            }
            if (--indeg[v] == 0) q.push(v);
        }
    }
    // Answer is max reachable DP value
    ll ans = 0;
    for (ll x : dp) if (x != INF) ans = max(ans, x);
    return ans;
}

// Example usage:
int main() {
    int A,B; cin>>A>>B;
    int m; cin>>m;
    vector<vector<ll>> C(m,vector<ll>(3));
    for(int i=0;i<m;i++){
        for(int j=0;j<3;j++){
            cin>>C[i][j];
        }
    }
    cout << maximumReward(A, B, C) << "\n";
    return 0;
}