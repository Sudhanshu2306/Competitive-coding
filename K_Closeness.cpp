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
typedef multiset<long long> msll;

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
    ll n,k; cin>>n>>k;
    vll a(n);
    // msll st;
    // ll res=1e9+7;
    for0(i,n){
        cin>>a[i];
        // st.insert(a[i]);
    } 

    sort(a.begin(),a.end());
    
    // for0(k,n){
    //     auto it1 = st.begin(); auto it2 = st.rbegin(); 
    //     ll i = *it1; 
    //     ll j = *it2;
    //     res=min(res,j-i);
    //     i+=k;
    //     st.erase(st.begin());
    //     st.insert(i);
    // }
    // cout<<res<<endl;

    ll maxi=a[n-1];
    ll mini=a[n-1];
    ll res;
    for0(i,n-1){
        ll temp=(maxi-a[i])/k;
        a[i]=a[i]+(temp*k);
    }
    // sort(a.begin(),a.end());
    for0(i,n){
        mini=min(mini,a[i]);
    }
    sort(a.begin(),a.end());
    res=maxi-mini;
    
    // mini=a[0];
    maxi=a[n-1];

    for0(i,n){
        res=min(res,abs(a[i]-maxi));
        maxi=max(maxi,a[i]+k);
    }
    cout<<res<<endl;
    
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


