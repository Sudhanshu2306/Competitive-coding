#include <bits/stdc++.h>
using namespace std;

int getMinimumMoves(const vector<int>& tasks) {
    int n = tasks.size();
    if (n <= 1) return 0;

    int tot = accumulate(tasks.begin(), tasks.end(), 0);
    vector<int> pre(n + 1);
    for (int i = 1; i <= n; ++i) pre[i] = pre[i - 1] + tasks[i - 1];

    vector<vector<int>> dp1(tot + 1, vector<int>(tot + 1, 1e9)), dp2(tot + 1, vector<int>(tot + 1, 1e9));
    for (int v = 0; v <= tot; ++v) dp1[v][v] = abs(tasks[0] - v);

    vector<int> mini(tot + 1);
    vector<vector<int>> temp(tot+1,vector<int>(tot+1,1e9));

    for (int i = 2; i <= n; ++i) {
        dp2=temp;

        for (int u = 0; u <= tot; ++u) {
            int best = 1e9;
            for (int p = tot; p >= 0; --p) {
                best = min(best, dp1[p][u]);
                mini[p] = best;
            }
            int rem = tot - u;
            for (int c = 0; c <= rem; ++c) {
                int base = mini[c];
                if (base == 1e9) continue;
                int nu = u + c;
                int cost = base + abs(pre[i] - nu);
                if (cost < dp2[c][nu]) dp2[c][nu] = cost;
            }
        }
        dp1.swap(dp2);
    }

    int res = 1e9;
    for (int l = 0; l <= tot; ++l) res = min(res, dp1[l][tot]);
    return res;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) cin >> arr[i];
    cout << getMinimumMoves(arr) << endl;
}