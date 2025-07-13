#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll pack(int x, int y){ 
    return ((ll)x<<32)^(ll)(y); 
}

int main() {
    int n; cin>>n;

    vector<pair<int,int>> pts(n);
    set<ll> st;

    for (int i = 0; i < n; ++i) {
        cin >> pts[i].first>>pts[i].second;
        st.insert(pack(pts[i].first, pts[i].second));
    }

    int best=INT_MAX;

    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++) {
            int dx = pts[j].first - pts[i].first;
            int dy = pts[j].second - pts[i].second;
            if (!dx || !dy || abs(dx) != abs(dy)) continue;
            
            int x1 = pts[i].first, y1 = pts[i].second;
            int x2 = pts[j].first, y2 = pts[j].second;
            
            if (st.count(pack(x1, y2)) && st.count(pack(x2, y1)))
                best = min(best, abs(dx));
        }

    cout << (best == INT_MAX ? -1 : best);
    return 0;
}