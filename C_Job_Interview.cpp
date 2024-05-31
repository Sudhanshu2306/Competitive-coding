#include <bits/stdc++.h>
using namespace std;

#define for0(i, n) for (int i = 0; i < (n); ++i)
#define min3(a, b, c) min(a, min(b, c))
#define max3(a, b, c) max(a, max(b, c))
#define setBit(x, i) (x |= (1LL << i))
#define clearBit(x, i) (x &= ~(1LL << i))
#define toggleBit(x, i) (x ^= (1LL << i))
#define checkBit(x, i) ((x & (1LL << i)) != 0)
#define EPS 1e-9
#define EQ(a, b) (abs(a - b) < EPS)
#define debug(x) cerr << #x << " = " << x << endl
#define gcd __gcd
#define lcm(a, b) ((a) / gcd(a, b) * (b))

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define vvi(a, m, n, x) vector<vector<int>> a(m, vector<int>(n, x))
#define vvll(a, m, n, x) vector<vector<ll>> a(m, vector<ll>(n, x))
#define umap unordered_map
#define umset unordered_set

void solve() {
    int n, m;
    cin >> n >> m;

    vi p(n + m + 1), t(n + m + 1);
    for0(i, n + m + 1) cin >> p[i];
    for0(i, n + m + 1) cin >> t[i];

    int sp = 0, st = 0, np = 0, nt = 0;
    vector<int> ap(p.size()), at(p.size());

    for0(i, p.size()) {
        if (p[i] > t[i] && np <= n) {
            sp += p[i];
            np++;
            ap[i] = 1;
        } else if (p[i] < t[i] && nt < m) {
            sp += t[i];
            nt++;
            ap[i] = 0;
        } else if (np <= n) {
            sp += p[i];
            np++;
            ap[i] = 1;
        } else {
            sp += t[i];
            nt++;
            ap[i] = 0;
        }
    }

    nt = 0;
    np = 0;
    for0(i, p.size()) {
        if (p[i] < t[i] && nt <= m) {
            st += t[i];
            nt++;
            at[i] = 0;
        } else if (p[i] > t[i] && np < n) {
            st += p[i];
            np++;
            at[i] = 1;
        } else if (nt <= m) {
            st += t[i];
            nt++;
            at[i] = 0;
        } else {
            st += p[i];
            np++;
            at[i] = 1;
        }
    }

    for0(i, p.size()) {
        int ts = 0;
        if (ap[i] == 1) {
            ts = sp - p[i];
        } else if (at[i] == 0) {
            ts = st - t[i];
        }
        cout << ts << " ";
    }
    cout << endl;
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
