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

vi f(int y) {
    vector<bool> a(y + 1, true);
    vi primes;
    a[0] = a[1] = false;

    for (int p=2;p<=y;p++) {
        if (a[p]) {
            primes.push_back(p);
            for (int i=p*p;i<=y;i+=p) {
                a[i] = false;
            }
        }
    }
    return primes;
}

void solve() {
    // Your code goes here
    int n; cin>>n;
    if(n<12){
        cout<<"No"<<endl; return;
    }
    n-=4;
    int y = static_cast<int>(sqrt(n));
    vi primes = f(y);

    // int size = primes.size();

    vi temp;
    // for0(i,primes.size()) {
    //     int sq=primes[i] * primes[i];
    //     if (sq<n) {
    //         temp.push_back(sq);
    //     }
    // }

    int i = 0, j = primes.size() - 1;
    while(i<j){
        ll x=primes[i]*primes[i];
        ll y=primes[j]*primes[j];
        ll sum = x+y;
        if(sum == n){
            cout<<"Yes"<<endl; return;
        }
        else if(sum<n) i++;
        else j--;
    }
    cout<<"No"<<endl;
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


