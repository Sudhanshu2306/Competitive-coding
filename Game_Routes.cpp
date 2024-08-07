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


void solve() {
    // Your code goes here
    int n,m; cin>>n>>m;
    vvi edges(m,vi(2));
    for0(i,m){
        cin>>edges[i][0];
        cin>>edges[i][1];
    }
    vi adj[n], adjR[n];
    for(auto it:edges){
        adj[it[0]-1].push_back(it[1]-1);
        adjR[it[1]-1].push_back(it[0]-1);
    }

    vi indegree(n+1,0);
    vi dp(n+1,0); dp[0]=1;
    for(auto i:edges){
        indegree[i[1]-1]++;
    }
    queue<int> q; 
    int mod=1e9+7;
    for0(i,n){
        if(indegree[i]==0) q.push(i);
    }

    while(!q.empty()){
        int u=q.front(); q.pop();

        for(auto v:adj[u]){
            indegree[v]--;
            if(indegree[v]==0) q.push(v);
        }

        for(auto i:adjR[u]){
            dp[u]=(dp[u]+dp[i])%mod;
        }

    }
    cout<<dp[n-1]<<endl;
    
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    

    return 0;
}


