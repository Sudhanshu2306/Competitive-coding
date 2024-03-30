#include <bits/stdc++.h>
using namespace std;

// Commonly used loops
#define for0(i, n) for (int i = 0; i < (n); i++)
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
typedef vector<bool> vb;
typedef vector<pair<int,int>> vpii;

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

vi ss() {
    vb pp(1e5+1,true);
    vi p;
    
    pp[0]=pp[1]=false;
    for(int i=2;i*i<=1e5;i++){
        if(pp[i]) 
            for(int j=i*i;j<=1e5;j+=i)
                pp[j]=false;
            
        
    }
    for(int i=2;i<=1e5;i++) {
        if(pp[i]) {
            p.push_back(i);
        }
    }
    return p;
}


bool f(int num){ 
    while(num > 0){
        int digit = num % 10;
        if (digit != 0 && digit != 1) {
            return false;
        }
        num /= 10;
    }
    return true; 
}


void solve() {
    // Your code goes here
    ll a; cin>>a;
    // vi p=ss();
    bool flag=false;
    
    vll store={100000,1,121,111,101,10,11,100,110,1010,1000,1001,1011,1100,1111,1101,1110,10000,10001,10010,10011,10100,10101,10111,10110,11000,111001,11010,11011,11100,11101,11110,11111};
    int x=store.size();
    for0(i, x){
        if(a%store[i]==0){
            // if(store[i]!=a)
            // cout<<"YES"<<endl;
            flag=true;
            // return; 
            break;
        } 
        // else cout<<"NO"<<endl;
    }
    if(flag) cout<<"YES"<<endl;
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


