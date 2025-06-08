#include <bits/stdc++.h>
using namespace std;
using ll = long long;

static const int H = 31;  // up to 2^31 > 1e9

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    vector<int> from(m), to(m);
    for(int i = 0; i < m; i++){
        cin >> from[i] >> to[i];
        adj[from[i]].push_back(to[i]);
        adj[to[i]].push_back(from[i]);
    }
    vector<ll> A(n);
    for(auto &x: A) cin >> x;
    ll K;
    cin >> K;

    // Build a rooted tree at 0:
    vector<int> parent(n, -1), order;
    order.reserve(n);
    queue<int> q;
    q.push(0);
    parent[0] = 0;
    while(!q.empty()){
        int u = q.front(); q.pop();
        order.push_back(u);
        for(int v: adj[u]){
            if(parent[v] < 0){
                parent[v] = u;
                q.push(v);
            }
        }
    }

    // dp[u][h] = best total in subtree u if path to u has already h halvings.
    vector<array<ll, H+2>> dp(n);
    // We'll process in reverse BFS order (i.e. post-order).
    for(int idx = n-1; idx >= 0; idx--){
        int u = order[idx];
        // for each possible h = 0..H
        for(int h = H; h >= 0; h--){
            // effective value at u after h halvings:
            ll val = A[u] >> h;  // same as floor(A[u]/2^h)
            // OPTION 1: type-1 at u
            ll opt1 = val - K;
            // OPTION 2: type-2 at u
            ll opt2 = val >> 1;  // floor(val/2)
            // now add children contributions
            for(int v: adj[u]){
                if(parent[v] == u){
                    opt1 += dp[v][h];
                    opt2 += dp[v][h+1];
                }
            }
            dp[u][h] = max(opt1, opt2);
        }
    }

    // the root has no parent, so we must collect at 0 with h=0
    cout << dp[0][0] << "\n";
    return 0;
}
