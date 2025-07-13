#include <bits/stdc++.h>
using namespace std;

int dx[8] = { 0,  0,  1, -1,  1,  1, -1, -1 };
int dy[8] = { 1, -1,  0,  0,  1, -1,  1, -1 };

int countOccurrence(int N, vector<string> grid, string word){
    int L = word.size();

    int count = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (grid[i][j] != word[0]) continue;
            for (int d = 0; d < 8; d++) {
                bool ok = true;
                for (int t = 1; t < L; t++) {
                    int ni = i + dx[d] * t;
                    int nj = j + dy[d] * t;
                    if (ni < 0 || ni >= N || nj < 0 || nj >= N || grid[ni][nj] != word[t]) {
                        ok = false;
                        break;
                    }
                }
                if (ok) count++;
            }
        }
    }
    return count;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    vector<string> grid(N);
    for (int i = 0; i < N; i++) cin >> grid[i];

    string word; cin >> word;
    cout<<countOccurrence(N,grid,word)<<endl;
    return 0;
}
