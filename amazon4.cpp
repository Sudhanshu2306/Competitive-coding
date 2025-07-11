#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll findMinPrice(vector<int> cost, int pairCost, int k){
    int n = cost.size();
    vector<int> v = cost;
    sort(v.begin(), v.end(), greater<int>());     

    vector<ll> pref(n + 1, 0);
    for (int i = 0; i < n; ++i) pref[i + 1] = pref[i] + v[i];

    ll total = pref[n], best = total;
    int maxi = min(k, n / 2);

    for (int p = 1; p <= maxi; ++p){
        ll sum = pref[2 * p];
        ll cost = total - sum + 1LL * p * pairCost;
        if (cost < best) best = cost;
    }
    return best;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n; 
    vector<int> cost(n);
    for(int i = 0; i < n; i++) 
        cin >> cost[i];
    int pairCost, k;
    cin >> pairCost >> k;

    cout << findMinPrice(cost, pairCost, k) << "\n";
    return 0;
}
