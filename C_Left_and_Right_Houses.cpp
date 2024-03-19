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
    ll n; cin>>n;
    string s; cin>>s;

    ll x=0,y=0;
    for0(i,n){
        if(s[i]=='0') x++;
        else y++;
    }
    vi v;
    
    int a=0;
    int b=0;

    for0(i,n){
        if(s[i]=='1') b++;
        if(s[i]=='0') a++;

        ll left=i+1;
        ll right=n-left;

        left=(left+1)/2;
        right=(right+1)/2;
        if (a >= left and (y-b) >= right){
            v.push_back(1);
        }
        else{ 
            v.push_back(0);
        }
    }
    ll ans=-1;
  
    float mid = n;
    mid = mid / 2;
  
    vector<pair<float,int>> arr;
    for0(i,v.size()){
        if (v[i] == 1) {
            float temp=mid-(i+1);
            arr.push_back({abs(temp),i+1});
        }
    }
    mid = n;
    mid = mid / 2;

    bool flag=0;
    int mini=(n+1)/2;
    if(b>=mini) flag = 1;

    if(flag==1) arr.push_back({mid,0});
    sort(arr.begin(),arr.end());

    cout<<arr[0].second<<endl;
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


