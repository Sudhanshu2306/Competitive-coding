#include <bits/stdc++.h>
using namespace std;

vector<int> solve(vector<string>& v) {
    vector<int> out;
    for (auto s : v) {
        int n = s.size();
        if (n == 0) { out.push_back(1); continue; }
        if (n & 1)  { out.push_back(0); continue; }

        vector<vector<char>> ok(n, vector<char>(n, 0));

        for (int len = 2; len <= n; len += 2) {
            for (int i = 0; i + len <= n; ++i) {
                int j = i + len - 1;
                bool good = false;

                if (s[i] == s[j]){
                    good = (len == 2) || ok[i + 1][j - 1];
                }

                if (!good) {
                    for (int k = i + 1; k < j; k += 2) {
                        if (ok[i][k] && ok[k + 1][j]) { good = true; break; }
                    }
                }
                ok[i][j] = good;
            }
        }
        out.push_back(ok[0][n - 1] ? 1 : 0);
    }
    return out;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; 
    if (!(cin >> n)) return 0;
    vector<string> v(n);
    for (int i = 0; i < n; ++i) cin >> v[i];

    vector<int> ans = solve(v);
    for (int i = 0; i < n; ++i) {
        if (i) cout << ' ';
        cout << ans[i];
    }
    cout << '\n';
    return 0;
}