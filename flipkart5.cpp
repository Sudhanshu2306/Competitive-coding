#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> adj;
vector<int> disc, low, parent;
vector<bool> ap;
int timer;

void dfsAP(int u) {
    disc[u] = low[u] = ++timer;
    int children = 0;
    for (int v : adj[u]) {
        if (disc[v] == 0) {
            children++;
            parent[v] = u;
            dfsAP(v);
            low[u] = min(low[u], low[v]);
            if (parent[u] == -1 && children > 1)        ap[u] = true;
            if (parent[u] != -1 && low[v] >= disc[u])    ap[u] = true;
        }
        else if (v != parent[u]) {
            low[u] = min(low[u], disc[v]);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    if (!(cin >> n)) return 0;
    adj.assign(n, {});
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            char c;
            do { if (!cin.get(c)) return 0; } while (isspace(c));
            if (c == '1') {
                adj[i].push_back(j);
            }
        }
    }

    disc.assign(n, 0);
    low.assign(n, 0);
    parent.assign(n, -1);
    ap.assign(n, false);
    timer = 0;

    for (int i = 0; i < n; i++)
        if (disc[i] == 0)
            dfsAP(i);

    vector<bool> isB(n, false);
    for (int u = 0; u < n; u++) {
        if (ap[u]) {
            for (int v : adj[u]) {
                if (!ap[v]) isB[v] = true;
            }
        }
    }

    bool first = true;
    for (int i = 0; i < n; i++) {
        if (isB[i]) {
            if (!first) cout << ' ';
            cout << i;
            first = false;
        }
    }
    cout << "\n";
    return 0;
}
