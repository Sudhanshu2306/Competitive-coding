#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX_N = 15000;
vector<int> graph[MAX_N];
vector<bool> visited(MAX_N, false);
vector<int> potentials(MAX_N, 0);

int dfs(int node) {
    visited[node] = true;
    potentials[node] = 1;
    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            potentials[node] += dfs(neighbor);
        }
    }
    return potentials[node];
}

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    dfs(0);

    int max_potential = 0;
    for (int i = 0; i < n; i++) {
        int total_potential = 0;
        for (int neighbor : graph[i]) {
            total_potential += max(1, potentials[neighbor] - (potentials[i] + 1)) + 1;
        }
        max_potential = max(max_potential, potentials[i] + total_potential);
    }

    cout << max_potential << endl;

    return 0;
}
