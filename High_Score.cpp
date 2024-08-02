#include <bits/stdc++.h>
using namespace std;

// Commonly used loops
#define for0(i, n) for (int i = 0; i < (n); ++i)
#define for1(i, n) for (int i = 1; i <= (n); ++i)
#define rfor0(i, n) for (int i = (n) - 1; i >= 0; --i)
#define rfor1(i, n) for (int i = (n); i >= 1; --i)

// Minimum and maximum macros
#define min3(a, b, c) min(a, min(b, c))
#define max3(a, b, c) max(a, max(b, c))

// Bit manipulation macros
#define setBit(x, i) (x |= (1LL << i))
#define clearBit(x, i) (x &= ~(1LL << i))
#define toggleBit(x, i) (x ^= (1LL << i))
#define checkBit(x, i) ((x & (1LL << i)) != 0)

// Shortcuts for common data types
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

// 2D vector initialization
#define vvi(a, m, n, x) vector<vector<int>> a(m, vector<int>(n, x))
#define vvll(a, m, n, x) vector<vector<ll>> a(m, vector<ll>(n, x))

// map & set
#define umap unordered_map
#define umset unordered_set

// Iterate over container elements
#define foreach(it, v) for (auto it = v.begin(); it != v.end(); ++it)
#define fori(i, a, b) for (int i = a; i <= b; ++i)
#define fora(e, v) for (const auto &e : v)

// Floating-point comparisons
#define EPS 1e-9
#define EQ(a, b) (abs(a - b) < EPS)

// Debugging macro
#define debug(x) cerr << #x << " = " << x << endl

// Shortcuts for commonly used functions
#define gcd __gcd
#define lcm(a, b) ((a) / gcd(a, b) * (b))

void dfs(vi adj[],vi &vis,int node){
    vis[node]=1;
    for(auto i:adj[node]){
        if(!vis[i]) dfs(adj,vis,i);
    }
}

void solve() {
    // Your code goes here
    int n,m; cin>>n>>m;
    // 1 to n
    vvi edges(m,vi(3));
    for0(i,m){
        // directed edge 
        cin>>edges[i][0];
        cin>>edges[i][1];
        cin>>edges[i][2];
    }
    vi adj[n+1];
    vi adjR[n+1];
    for(auto it:edges){
        adj[it[0]].push_back(it[1]);
        adjR[it[1]].push_back(it[0]);
    }

    vi vis1(n+1,0),vis2(n+1,0);

    dfs(adj,vis1,1);
    dfs(adjR,vis2,n);

    vll dist(n+1,-1e16);
    dist[1]=0;

    bool flag=0;
    for1(i,n){
        flag=0;
        for(auto it:edges){
            int u=it[0]; int v=it[1];
            int wt=it[2];

            if(vis1[u] && vis2[v] && dist[u]+wt>dist[v]){
                flag=1;
                dist[v]=dist[u]+wt;
            }
        }
    }
    if(flag) {
        cout<<-1<<endl;
        return;
    }
    cout<<dist[n]<<endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}


