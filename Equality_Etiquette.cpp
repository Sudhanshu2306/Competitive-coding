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

int f(int A, int B) {
    int diff=abs(A - B);

    if (diff == 0) {
        return 0;
    }

    if (diff % 2 == 1) {
        return -1;
    }

    int moves = 0;

    for (int i = 1; i <= diff; ++i) {
        moves += i;
        if (moves >= diff) {
            return i;  
        }
    }
    return -1;
}

void solve() {
    // Your code goes here
    ll a,b;cin>>a>>b;
    ll d=abs(a-b);
    ll y=0; ll x=sqrt(d);
    x*=2;
    while(x!=y){
        ll mid=x+y;mid/=2;
        ll sum=mid*(mid+1);
        sum/=2;
        if(sum>=d)x=mid;
        else y=mid+1;
    }

    if(d%2==0){
        if(y%4==1)y+=2;
        else if(y%4==2)y++;
    }
    if(d%2==1){
        if(y%4==3)y+=2;
        else if(y%4==0)y++;
    }
    cout<<y<<endl;
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


