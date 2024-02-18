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
    char c; cin>>c;

    map<char,vector<string>> mp;
    for(int i=0;i<2*n;i++){
        string s; cin>>s;
        mp[s[1]].push_back(s);
    }

    vector<char> arr;
    arr.push_back('C');
    arr.push_back('D');
    arr.push_back('H');
    arr.push_back('S');

    vector<pair<string,string>> ans;
 

    for(int i=0;i<arr.size();i++) 
        sort(mp[arr[i]].begin(),mp[arr[i]].end());
    ll count=0;
    for(ll i=0;i<arr.size();i++){
        if(arr[i]!=c){
            if(mp[arr[i]].size()%2==1) count++;
        }
    }

    if(count>mp[c].size()||mp[c].size()%2!=count%2)cout<<"IMPOSSIBLE"<<endl;
    else {

        for(ll i=0;i<arr.size();i++){
            if(arr[i]!=c){
                if(mp[arr[i]].size()%2==1){
                    cout<<mp[arr[i]][mp[arr[i]].size()-1]<<" "<<mp[c][mp[c].size()-1]<<endl;
                    mp[arr[i]].pop_back();
                    mp[c].pop_back();
                }
            }
        }

        for(ll i=0;i<arr.size();i++){
            char a=arr[i];
            ll j=0;
            while(j<mp[a].size()){
                cout<<mp[a][j]<<" "<<mp[a][j+1]<<endl;
                j+=2;
            }
        }
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


