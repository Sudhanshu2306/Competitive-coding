#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> solve(vector<ll>& warehouse, vector<vector<ll>>& catalog) {
    vector<ll> w(warehouse.begin(), warehouse.end());
    sort(w.begin(), w.end());
    ll total = 0;
    for (int v : warehouse) total += v;

    vector<ll> ans;
    ans.reserve(catalog.size());

    for (auto& q : catalog) {
        ll x = q[0], y = q[1], best = LLONG_MAX;

        auto it = lower_bound(w.begin(), w.end(), x);

        if (it != w.end()) {                               
            ll a = *it, cost = 0;
            ll lack = y - (total - a);
            if (lack > 0) cost += lack;
            best = min(best, cost);
        }

        if (it != w.begin()) {                           
            auto it2 = it; it2--;                         
            ll a = *it2;
            ll cost = x - a;
            ll lack = y - (total - a);
            if (lack > 0) cost += lack;
            best = min(best, cost);
        }

        ans.push_back(best);
    }
    return ans;
}

int main(){
    long long n; cin>>n;
    vector<long long> a(n);
    for(long long i=0;i<n;i++) cin>>a[i];

    long long q; cin>>q;
    vector<vector<long long>> b(q,vector<ll>(2));
    for(int i=0;i<q;i++) cin>>b[i][0]>>b[i][1];

    vector<ll> ans=solve(a,b);
    
    for(int i=0;i<ans.size();i++) cout<<ans[i]<<" ";
    cout<<endl;

    return 0;
}

