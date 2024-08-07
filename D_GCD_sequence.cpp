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

    if(n==3){
        cout<<"YES"<<endl; return;
    }
    vi b(n-1);
    for0(i,n-1){
        b[i]=gcd(a[i],a[i+1]);
    }
    
    vi prefix(n,0),suffix(n,0);
    prefix[0]=1; prefix[1]=1;
    suffix[n-1]=1; suffix[n-2]=1;

    int m=b.size();
    for(int i=m-2;i>=0;i--){
        if(b[i]>b[i+1]) break;
        else suffix[i]=1;
    }

    for(int i=1;i<m;i++){
        if(b[i]>=b[i-1]) prefix[i+1]=1;
        else break;
    }

    for0(i,n){
        if(i==0 && suffix[1]==1) {
            cout<<"YES"<<endl; return;
        }
        else if(i==n-1 && prefix[n-2]==true) {
            cout<<"YES"<<endl;
            return;
        }
        else if(i>0 && i<n-1){
            if(prefix[i-1]==0 || suffix[i+1]==0) continue;
            
            int curr=gcd(a[i-1],a[i+1]);
            if(i==1 && curr<=gcd(a[i+1],a[i+2])){
                cout<<"YES"<<endl; return;
            }
            else if(i==n-2 && curr>=gcd(a[i-1],a[i-2])){
                cout<<"YES"<<endl; return;
            }
            else if(i>1 && i<n-2){  
                if(curr>=gcd(a[i-1],a[i-2]) && curr<=gcd(a[i+1],a[i+2])){
                    cout<<"YES"<<endl;
                    return;
                }
            }
        }
    }
    cout<<"NO"<<endl;
    
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


