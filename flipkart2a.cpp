#include <bits/stdc++.h>
using namespace std;

using ll = long long;

static inline ll pack(int x, int y) { return (static_cast<ll>(x) << 32) ^ (y & 0xffffffffLL); }

struct Point { int x, y; };

int main() {

    int n;
    if (!(cin >> n)) return 0;

    vector<Point> pts(n);
    unordered_set<ll> st;
    st.reserve(n << 1);

    for (int i = 0; i < n; ++i) {
        cin >> pts[i].x >> pts[i].y;
        st.insert(pack(pts[i].x, pts[i].y));
    }

    int best = INT_MAX;

    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; j++) {
            if (pts[i].y != pts[j].y) continue;        
            int side = abs(pts[i].x - pts[j].x);
            if (!side) continue;
            
            for (int dir = 1; dir >= -1; dir -= 2) {  
                int ny = pts[i].y + dir * side;
                if (st.count(pack(pts[i].x, ny)) && st.count(pack(pts[j].x, ny)))
                    best = min(best, side);
            }
        }

    cout << (best == INT_MAX ? -1 : best);
    return 0;
}