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
    int n; cin>>n;
    string s; cin>>s;

    umap<int,int> mp;
    ll minia=0, minic=0, minib=0;
    bool f1=false, f2=false, f3=true;

    for0(i,n){
        
        if(f3==true && s[i]=='a'){
            minia+=1; f1=true;
        } 

        else if(f1==true && s[i]=='b'){
            minib+=1; f2=true; f2=false;
        }
        
        else if(f1==true && f2==true && s[i]=='c'){
            minic+=1; 
        }
    }
    int ans=min3(minia,minib,minic);
    cout<<ans<<endl;


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


