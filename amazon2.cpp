#include <bits/stdc++.h>
using namespace std;

int getMaximumBalancedShipments(vector<long long>& weight) {
struct Seg { long long mx, last; };
vector<Seg> seg;
long long curMax = LLONG_MIN;

for (size_t i = 0; i < weight.size(); ++i) {
    curMax = max(curMax, (long long)weight[i]);
    if (weight[i] <curMax) {                 // close balanced segment
        seg.push_back({curMax, weight[i]});
        curMax = LLONG_MIN;
    }
}
if (curMax != LLONG_MIN)                      // unfinished last segment
    seg.push_back({curMax, weight.back()});

while (!seg.empty() && seg.back().mx <= seg.back().last) {
    if (seg.size() == 1) return 0;            // full array still unbalanced
    Seg tail = seg.back(); seg.pop_back();    // merge with previous
    Seg& prev = seg.back();
    prev.last = tail.last;
    prev.mx = max(prev.mx, tail.mx);
}
return (int)seg.size();
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<long long> weight(n);
    for (int i = 0; i < n; i++) {
        cin >> weight[i];
    }

    cout << getMaximumBalancedShipments(weight) << "\n";
    return 0;
}
