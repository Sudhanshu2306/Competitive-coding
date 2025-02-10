#include <bits/stdc++.h> 

using namespace std;

#define ll long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;
    while (t--) {
        ll n, m;
        cin >> n >> m;
        vector<vector<ll>> vec(n, vector<ll>(m));
        
        for (ll i = 0; i < n; i++) {
            for (ll j = 0; j < m; j++) {
                cin >> vec[i][j];
            }
        }

        auto cmp = [&](vector<ll>& a, vector<ll>& b) {
            ll sa = accumulate(a.begin(), a.end(), 0LL);
            ll sb = accumulate(b.begin(), b.end(), 0LL);
            if (sa != sb) return sa > sb;
            return a > b; // Lexicographical comparison
        };

        sort(vec.begin(), vec.end(), cmp);

        ll total_sum = 0, prefix_sum = 0;
        for (ll i = 0; i < n; i++) {
            for (ll j = 0; j < m; j++) {
                prefix_sum += vec[i][j];
                total_sum += prefix_sum;
            }
        }

        cout << total_sum << endl;
    }

    return 0;
}
