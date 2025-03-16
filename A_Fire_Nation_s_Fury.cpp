#include <bits/stdc++.h>
using namespace std;

static const int MOD = 1000000007;

// Fenwick (BIT) for range-sum queries on [1..n].
struct Fenwick {
    int n;
    vector<long long> fenw;
    Fenwick(int n) : n(n), fenw(n+1, 0) {}
    
    void update(int i, long long delta) {
        for (; i <= n; i += i & -i)
            fenw[i] += delta;
    }
    
    long long sum(int i) {
        long long s = 0;
        for (; i > 0; i -= i & -i)
            s += fenw[i];
        return s;
    }
    
    long long rangeSum(int l, int r) {
        if (l > r) return 0;
        return sum(r) - sum(l-1);
    }
};

vector<int> adj[100000+5];
int inTime[100000+5], outTime[100000+5];
int eulerList[100000+5];
int timer;

void dfs(int u, int p) {
    inTime[u] = ++timer;
    eulerList[timer] = u;
    for (auto &v : adj[u]) {
        if (v == p) continue;
        dfs(v, u);
    }
    outTime[u] = timer;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; 
    cin >> t;
    while(t--) {
        int N; 
        cin >> N;
        
        // Clear adjacency
        for(int i = 1; i <= N; i++){
            adj[i].clear();
        }
        
        // Read edges
        vector<int> A(N-1), B(N-1);
        for(int i = 0; i < N-1; i++) cin >> A[i];
        for(int i = 0; i < N-1; i++) cin >> B[i];
        
        // Build the tree
        for(int i = 0; i < N-1; i++){
            adj[A[i]].push_back(B[i]);
            adj[B[i]].push_back(A[i]);
        }
        
        // Run DFS from node 1 to get inTime/outTime
        timer = 0;
        dfs(1, -1);
        
        // We'll use a Fenwick tree to count how many "larger-index" nodes
        // are in each subtree segment.
        Fenwick fenw(N);
        long long answer = 0;
        
        // Process nodes in descending order
        for(int label = N; label >= 1; label--){
            int pos = inTime[label];
            int L = inTime[label], R = outTime[label];
            
            // number of processed nodes in [L, R] is the jealousy of 'label'
            long long cnt = fenw.rangeSum(L, R);
            answer = (answer + cnt) % MOD;
            
            // now mark this node as processed
            fenw.update(pos, 1);
        }
        
        cout << answer % MOD << "\n";
    }
    return 0;
}
