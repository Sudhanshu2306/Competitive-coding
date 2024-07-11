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

bool f(int n, int m, vvi& a, vvi& b) {
    rfor1(i,n-1){
        rfor1(j,m-1) {
            if(a[i][j]!=b[i][j]){
                int x=(b[i][j]-a[i][j]+3) % 3;
                a[i][j] = b[i][j];
                a[i-1][j]=(a[i-1][j] + 2*x) % 3; a[i][j-1]=(a[i][j-1] + 2*x) % 3;
                a[i-1][j-1] = (a[i-1][j-1] + x) % 3;
            }
            // cout<<a[i][j]<<" ";
            // cout<<b[i][j]<<" ";
        }
        // cout<<endl;
    }
    for0(i,n) if(a[i][0] != b[i][0]) return false;
    
    for0(j,m) if (a[0][j] != b[0][j]) return false;

    return true;
}

void solve() {
    // Your code goes here
    int n,m; cin>>n>>m;
    vvi a(n,vi(m)),b(n,vi(m));

    for0(i,n){
        for0(j,m){
            char ch; cin>>ch;
            a[i][j]=ch-'0';
        }
    }
    for0(i,n){
        for0(j,m){
            char ch; cin>>ch;
            b[i][j]=ch-'0';
        }
    }
    
    if(f(n,m,a,b)) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
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


