#include <bits/stdc++.h>
using namespace std;

// Commonly used loops
#define for0(i, n) for (int i = 0; i < (n); ++i)
#define for1(i, n) for (int i = 1; i <= (n); ++i)
#define rfor0(i, n) for (int i = (n) - 1; i >= 0; --i)
#define rfor1(i, n) for (int i = (n); i >= 1; --i)
#define foreach(it, v) for (auto it = v.begin(); it != v.end(); ++it)
#define fori(i, a, b) for (int i = a; i <= b; ++i)
#define fora(e, v) for (const auto &e : v)

// Macros
#define pb push_back
#define f first
#define s second
#define sz(s) (int)(s.size())
#define Num_of_Digits(n) ((int)log10(n) + 1)
#define inint(x) int x; cin>>x;
#define inll(x) long long int x; cin>>x;
#define instr(x) string x; cin>>x;
#define sort(v) sort(v.begin(),v.end());
#define all(x) x.begin(), x.end()
#define MAX(x) *max_element(all(x))
#define MIN(x) *min_element(all(x))
#define SUM(x) accumulate(all(x), 0LL)
#define py cout<<"YES"<<endl
#define pn cout<<"NO"<<endl
#define pm cout<<"-1"<<endl
#define ps(x,y) fixed<<setprecision(y)<<x
#define PI (3.141592653589)
#define M 1000000007

// Bit manipulation macros
#define setBit(x, i) (x |= (1LL << i))
#define clearBit(x, i) (x &= ~(1LL << i))
#define toggleBit(x, i) (x ^= (1LL << i))
#define checkBit(x, i) ((x & (1LL << i)) != 0)
#define set_bits(x) __builtin_popcountll(x)
#define zero_bits(x) __builtin_ctzll(x)

// Shortcuts for common data types
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pii> vpii;
#define vvi(a, m, n, x) vector<vector<int>> a(m, vector<int>(n, x))
#define vvll(a, m, n, x) vector<vector<ll>> a(m, vector<ll>(n, x))
#define umap unordered_map
#define umset unordered_set

class DisjointSet{
    public:
    vector<int> parent,size;
    DisjointSet(int n){parent.resize(n+1,1);size.resize(n+1,1);for(int i=0;i<=n;i++){parent[i]=i;}}
    int findParent(int node){if(node==parent[node]) return node;return parent[node]=findParent(parent[node]);}
    void unionBySize(int u, int v){int parent_u=findParent(u);int parent_v=findParent(v);if(parent_u==parent_v) return;if(size[parent_u]>size[parent_v]){parent[parent_v]=parent_u;size[parent_u]+=size[parent_v];}else{parent[parent_u]=parent_v;size[parent_v]+=size[parent_u];}}
};
ll bi_expo (ll a,ll b){
    ll ans=1;
    while(b){
        if(b&1) ans=(ans*a)%1000000007;
        a=(a*a)%1000000007;
        b>>=1;
    }return ans;
}

// Floating-point comparisons
#define EPS 1e-9
#define EQ(a, b) (abs(a - b) < EPS)

// Debugging macro
#define debug(x) cerr << #x << " = " << x << endl

// constants
vector <ll> primes;
vector <bool> is_prime;

// most used function
ll moduloMultiplication(ll a,ll b,ll mod){ll res = 0;a %= mod;while (b){if (b & 1)res = (res + a) % mod;b >>= 1;}return res;}
ll powermod(ll x, ll y, ll p){ll res = 1;x = x % p;if (x == 0) return 0;while (y > 0){if (y & 1)res = (res*x) % p;y = y>>1;x = (x*x) % p;}return res;}
ll modinv(ll p,ll q){ll ex;ex=M-2;while (ex) {if (ex & 1) {p = (p * q) % M;}q = (q * q) % M;ex>>= 1;}return p;}
#define gcd __gcd
#define lcm(a, b) ((a)/gcd(a,b)*(b))
string decToBinary(int n){string s="";int i = 0;while (n > 0) {s =to_string(n % 2)+s;n = n / 2;i++;}return s;}
ll binaryToDecimal(string n){string num = n;ll dec_value = 0;int base = 1;int len = num.length();for(int i = len - 1; i >= 0; i--){if (num[i] == '1')dec_value += base;base = base * 2;}return dec_value;}
bool isPrime(ll n){if(n<=1)return false;if(n<=3)return true;if(n%2==0||n%3==0)return false;for(int i=5;i*i<=n;i=i+6)if(n%i==0||n%(i+2)==0)return false;return true;}
bool isPowerOfTwo(int n){if(n==0)return false;return (ceil(log2(n)) == floor(log2(n)));}
bool isPerfectSquare(ll x){if (x >= 0) {ll sr = sqrt(x);return (sr * sr == x);}return false;}

void Sieve(int n){ is_prime.assign(n + 1, true); is_prime[0] = is_prime[1] = false; for(ll i = 2; i * i <= n; i++) if(is_prime[i]) for(ll j = i * i; j <= n; j += i) is_prime[j] = false;}
void get_primes(int n){ for(int i = 2; i <= n; i++)  if(is_prime[i])  primes.push_back(i); }

ll mex(vll &a){
    set<ll> st;
    for0(i,a.size()+1) st.insert(i);
    for(auto i:a) st.erase(i);
    return *(st.begin());
}

void solve() {
    // Your code goes here
    inint(n); inint(m);
    vvll a(n,vll(m,0));
    ll sr=0;
    for0(i,n){
        if(sr<m-1) sr++;
        ll sc=sr;
        for0(j,m){
            a[i][sc]=j;
            sc=(sc+1)%m;
        }
    }

    vll temp;
    for0(i,m){
        vll c;
        for0(j,n){
            c.pb(a[j][i]);
        }
        temp.pb(mex(c));
    }
    cout<<mex(temp)<<endl;

    for(auto i:a){
        for(auto j:i) cout<<j<<" ";
        cout<<endl;
    }
    // cout<<endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Shiv sama rahe mujh mein, aur main suniye ho raha hoon
    // NO. 1 is always an odd!

    int t;
    cin>>t;
    while(t--){
        solve();
    }

    return 0;
}


