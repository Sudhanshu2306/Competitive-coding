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
    int n; cin>>n;
    string s; cin>>s;

    umap<char,int> mp;
    mp['N']=0; mp['S']=0; mp['E']=0; mp['W']=0;
    for0(i,n){
        mp[s[i]]++;
    }
    if(n==2){
        if(s[0]==s[1]){
            cout<<"RH"<<endl; return;
        }
        else {
            cout<<"NO"<<endl; return;
        }    
    }
    if(n%2==1){
        cout<<"NO"<<endl; return;
    } 
    if (mp['N'] == 0 && mp['S'] == 0 && (mp['E'] == 0 || mp['W'] == 0)) {
        cout << "NO" << endl;
        return;
    }
    if (mp['E'] == 0 && mp['W'] == 0 && (mp['N'] == 0 || mp['S'] == 0)) {
        cout << "NO" << endl;
        return;
    }

    int netVertical = mp['N'] - mp['S'];
    int netHorizontal = mp['E'] - mp['W'];

    // Check if we can balance the movements
    if (abs(netVertical) % 2 != 0 || abs(netHorizontal) % 2 != 0) {
        cout << "NO" << endl;
        return;
    }

    string r(n, 'R');
    int roverN = 0, roverS = 0, roverE = 0, roverW = 0;
    int heliN = 0, heliS = 0, heliE = 0, heliW = 0;

    bool assignedHeli = false;
    bool assignedRover = false;

    for (int i = 0; i < n; i++) {
        char c = s[i];
        if (c == 'N') {
            if (roverN < mp['N'] / 2 || !assignedHeli) {
                r[i] = 'R';
                roverN++;
                assignedRover = true;
            } else {
                r[i] = 'H';
                heliN++;
                assignedHeli = true;
            }
        } else if (c == 'S') {
            if (roverS < mp['S'] / 2 || !assignedHeli) {
                r[i] = 'R';
                roverS++;
                assignedRover = true;
            } else {
                r[i] = 'H';
                heliS++;
                assignedHeli = true;
            }
        } else if (c == 'E') {
            if (roverE < mp['E'] / 2 || !assignedHeli) {
                r[i] = 'R';
                roverE++;
                assignedRover = true;
            } else {
                r[i] = 'H';
                heliE++;
                assignedHeli = true;
            }
        } else if (c == 'W') {
            if (roverW < mp['W'] / 2 || !assignedHeli) {
                r[i] = 'R';
                roverW++;
                assignedRover = true;
            } else {
                r[i] = 'H';
                heliW++;
                assignedHeli = true;
            }
        }
    }

    // Ensure both rover and helicopter have at least one instruction
    
        // cout << "YES" << endl;
        cout << r << endl;

    // if((mp['N']+mp['S'])%2==0){
    //     if((mp['E']+mp['W'])%2==0){
    //         if((mp['N']+mp['S'])>0){
    //             for0(i,n){
    //                 if(s[i]=='N' || s[i]=='S') s[i]='R';
    //                 else s[i]='H';
    //             }
    //         }
    //         else{
    //             int a=n/4;
    //             int xe=1,xw=1;
    //             for0(i,n){
    //                 if(xe<=a && s[i]=='E'){
    //                     s[i]='R'; xe++;
    //                 }
    //                 else if(xw<=a && s[i]=='W'){
    //                     s[i]='R'; xw++;
    //                 }
    //                 else if(xe>a && s[i]=='E'){
    //                     s[i]='H'; xe++;
    //                 }
    //                 else if(xw>a && s[i]=='W'){
    //                     s[i]='H'; xw++;
    //                 }
    //             }
    //         }
    //     } 
    //     cout<<s<<endl;
    // }
    // else if((mp['E']+mp['W'])%2==0){
    //     if((mp['S']+mp['N'])%2==0){
    //         if((mp['E']+mp['W'])>0){
    //             for0(i,n){
    //                 if(s[i]=='E' || s[i]=='W') s[i]='R';
    //                 else s[i]='H';
    //             }
    //         }
    //         else{
    //             int a=n/4;
    //             int xe=1,xw=1;
    //             for0(i,n){
    //                 if(xe<=a && s[i]=='S'){
    //                     s[i]='R'; xe++;
    //                 }
    //                 else if(xw<=a && s[i]=='N'){
    //                     s[i]='R'; xw++;
    //                 }
    //                 else if(xe>a && s[i]=='S'){
    //                     s[i]='H'; xe++;
    //                 }
    //                 else if(xw>a && s[i]=='N'){
    //                     s[i]='H'; xw++;
    //                 }
    //             }
    //         }
    //     } 
    //     cout<<s<<endl;
    // }
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


