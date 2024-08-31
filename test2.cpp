#include <bits/stdc++.h>

using namespace std;

void f(const vector<int>& A, vector<vector<int>>& cycles) {
    int N = A.size();
    vector<bool> vis(N, false);

    for (int i = 0; i < N; ++i) {
        if (!vis[i]) {
            vector<int> cycle;
            int current = i;
            
            while (!vis[current]) {
                vis[current] = true;
                cycle.push_back(current);
                current = A[current] - 1; 
            }

            if (cycle.size() > 1){ 
                cycles.push_back(cycle);
            }
        }
    }
}

int solve(int N, const vector<int>& A) {
    vector<vector<int>> cycles;
    f(A, cycles);
    unordered_set<int> st;

    for (const auto& cycle : cycles) {
        for (int index : cycle) {
            st.insert(index + 1);
        }
    }
    return N - st.size();
}

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    int result = solve(N, A);
    cout << result << endl;

    return 0;
}
