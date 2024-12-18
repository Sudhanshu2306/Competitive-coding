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
// Segment Tree for SUM in a range
const int x=100000; // Adjust based on problem constraints
ll tree[4*x], lazy[4*x];

void build(const vll& arr, ll node, ll start, ll end) {
    if(start==end) tree[node]=arr[start];
    else{ll mid=(start+end)/2; build(arr,2*node,start,mid); build(arr,2*node+1,mid+1,end); tree[node]=tree[2*node]+tree[2*node+1];}
}
void updatePoint(ll node, ll start, ll end, ll idx, ll val) {
    if (start==end) tree[node]=val;
    else{ll mid=(start+end)/2; if(idx<=mid) updatePoint(2*node,start,mid,idx,val); else updatePoint(2*node+1,mid+1,end,idx,val); tree[node]=tree[2*node]+tree[2*node+1];}
}

void updateRange(ll node, ll start, ll end, ll l, ll r, ll val) {
    if(lazy[node]!=0){tree[node]+=(end-start+1)*lazy[node];if(start!=end){lazy[2*node]+=lazy[node]; lazy[2*node+1]+=lazy[node];}lazy[node] = 0;}
    if(start>end || start>r || end<l) return;
    if (start>=l && end<=r){tree[node]+=(end-start+1)*val; if(start!=end) {lazy[2*node]+=val; lazy[2*node+1]+=val;} return;}
    ll mid=(start+end)/2;
    updateRange(2*node,start,mid,l,r,val);
    updateRange(2*node+1,mid+1,end,l,r,val);
    tree[node]=tree[2*node]+tree[2*node+1];
}

ll queryRange(ll node, ll start, ll end, ll l, ll r){
    if(start>end || start>r || end<l) return 0;
    if(lazy[node]!=0){tree[node]+=(end-start+1)*lazy[node]; if(start!=end) {lazy[2*node]+=lazy[node]; lazy[2*node+1]+=lazy[node];} lazy[node]=0;}
    if(start>=l && end<=r) return tree[node];
    ll mid=(start+end)/2;
    ll leftSum=queryRange(2*node,start,mid,l,r);
    ll rightSum=queryRange(2*node+1,mid+1,end,l,r);
    return leftSum+rightSum;
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

void solve() {
    // Your code goes here
    inll(n);
    cout<<"? 1 2"<<endl;
    fflush(stdout);
    inll(x12); // x+y

    cout<<"? 2 3"<<endl;
    fflush(stdout);
    inll(x23); // y+z

    cout<<"? 1 3"<<endl;
    fflush(stdout);
    inll(x13); // x+z


    vll a(n+1,0); 
    a[3]=(x13-x12+x23)/2;
    a[2]=x23-a[3]; a[1]=x12-a[2]; 

    fori(i,4,a.size()-1){
        cout<<"? "<<1<<" "<<i<<endl;
        fflush(stdout);
        inll(temp);
        a[i]=temp-a[1];
    }
    cout<<"!";
    for1(i,a.size()-1){
        cout<<" "<<a[i];
    }
    cout<<endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Shiv sama rahe mujh mein, aur main suniye ho raha hoon
    // NO. 1 is always an odd!

    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }

    return 0;
}


