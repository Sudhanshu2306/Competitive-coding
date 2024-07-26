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

vi f(string x,int l, int r){
    vi count(26,0);
    for(int i=l;i<=r;i++){
        count[x[i]-'a']++;
    }
    return count;
}
void solve() {
    // Your code goes here
    int n; cin>>n;
    int q; cin>>q;

    string a; cin>>a;
    string b; cin>>b;

    vvi pa(n+1,vi(26,0));
    vvi pb(n+1,vi(26,0));

    for1(i,n){
        for0(j,26){
            pa[i][j]=pa[i-1][j];
            pb[i][j]=pb[i-1][j];
        }
        pa[i][a[i-1]-'a']++;
        pb[i][b[i-1]-'a']++;
    }

    vector<pii> queries(q);
    for0(i,q){
        // cin>>queries[i].first;
        // cin>>queries[i].second;
        int l,r; cin>>l>>r;

        int count=0;
        for0(i,26){
            int x=pa[r][i]-pa[l-1][i];
            int y=pb[r][i]-pb[l-1][i];
            count+=abs(x-y);
        }
        cout<<count/2<<endl;
        
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}


