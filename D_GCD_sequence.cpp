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

bool isNonDecreasing(const vi& sequence) {
    for (size_t i = 1; i < sequence.size(); ++i) {
        if (sequence[i] < sequence[i - 1]) {
            return false;
        }
    }
    return true;
}

void solve() {
    // Your code goes here
    int n; cin>>n;
    vi a(n); for0(i,n) cin>>a[i];

    vi b(n-1);
    for0(i,n-1){
        b[i]=gcd(a[i],a[i+1]);
    }
    
    int ind = -1;
    for0(i,n-2) {
        if (b[i] > b[i + 1]) {
            ind = i;
            // cout<<b[i]<<" ";
            break;
        }
    }
    if (ind == -1) {
        cout << "YES" << endl;
        return;
    }

    // int ind=-1;
    // for0(i,n-3){
    //     if()
    // }

    if(n==2){
        cout<<"YES"<<endl; return;
    } 

    vi a1, b1, c1;

        for0(i,n) {
            if (i != ind + 1) {
                a1.push_back(a[i]);
            }
            if (i != ind + 2) {
                b1.push_back(a[i]);
            }
            if (i != ind) {
                c1.push_back(a[i]);
            }
        }

        vi gcd1, gcd2, gcd3;
        for0(i,n-2){
            gcd2.push_back(gcd(b1[i], b1[i + 1]));
            // cout<<gcd(b1[i],b1[i+1]);
            gcd3.push_back(gcd(c1[i], c1[i + 1]));
            // cout<<gcd(c1[i],c1[i+1]);
            gcd1.push_back(gcd(a1[i], a1[i + 1]));
            // cout<<gcd(q1[i],a1[i+1]);
        }

        bool f1=true, f2=true, f3=true;
        for0(i,n-3) {
            if (gcd3[i] > gcd3[i + 1]) {
                f3 = false;
                break;
            }
        }

        for0(i,n-3) {
            if (gcd1[i] > gcd1[i + 1]) {
                f1 = false;
                break;
            }
        }
        for0(i,n-3) {
            if (gcd2[i] > gcd2[i + 1]) {
                f2 = false;
                break;
            }
        }

        if((!f1 && !f2 && !f3)) cout << "NO" << endl;
        else cout << "YES" << endl;

    
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


