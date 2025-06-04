#include <bits/stdc++.h>
using namespace std;
int R, C;
vector<string> ig;
int maxi = 0;

bool is_valid(int r, int c) {
    return r >= 0 && r < R && c >= 0 && c < C;
}

bool solve(int r, int c, const vector<string>& g) {
    if (g[r][c] != '-') return false;

    for (int dr = -1; dr <= 1; ++dr) {
        for (int dc = -1; dc <= 1; ++dc) {
            if (dr == 0 && dc == 0) continue;

            int nr = r + dr;
            int nc = c + dc;

            if (is_valid(nr, nc)) {
                if (g[nr][nc] == '@') return false;
            }
        }
    }
    return true;
}

void solve(vector<string> g, int index, int count) {
    maxi = max(maxi, count);
    if (index == R * C) return;
    int r = index / C, c = index % C;

    if (solve(r, c, g)) {
        vector<string> next_grid = g;
        next_grid[r][c] = 'T';

        for (int dr = -1; dr <= 1; ++dr) {
            for (int dc = -1; dc <= 1; ++dc) {
                if (dr == 0 && dc == 0) continue;
                int nr = r + dr;
                int nc = c + dc;
                if (is_valid(nr, nc)) {
                    if (next_grid[nr][nc] == '-') next_grid[nr][nc] = '@';
                }
            }
        }
        solve(next_grid, index + 1, count + 1);
    }
    solve(g, index + 1, count);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> R >> C;

    ig.resize(R);
    for (int i = 0; i < R; i++) cin >> ig[i];

    solve(ig, 0, 0);

    cout << maxi << endl;

    return 0;
}