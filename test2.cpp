#include <vector>
#include <unordered_map>
#include <functional>

using namespace std;

int countGoodEdge(int n, int k, vector<int>& values, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> graph;
        for (const auto& edge : edges) {
            int u = edge[0], v = edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        vector<unordered_map<int, int>> freq_in_subtree(n + 1);

        function<void(int, int)> dfs = [&](int current, int parent) {
            freq_in_subtree[current][values[current - 1]]++;
            for (int neighbor : graph[current]) {
                if (neighbor != parent) {
                    dfs(neighbor, current);
                    for (const auto& entry : freq_in_subtree[neighbor]) {
                        int value = entry.first;
                        int count = entry.second;
                        freq_in_subtree[current][value] += count;
                    }
                }
            }
        };

        dfs(1, -1);

        int count_valid_edges = 0;

        for (const auto& edge : edges) {
            int u = edge[0], v = edge[1];
            if (freq_in_subtree[v][values[v - 1]] > freq_in_subtree[u][values[u - 1]]) {
                swap(u, v);
            }
            auto& freq_subtree = freq_in_subtree[v];
            unordered_map<int, int> freq_remaining_tree = freq_in_subtree[1];
            for (const auto& entry : freq_subtree) {
                int value = entry.first;
                int count = entry.second;
                freq_remaining_tree[value] -= count;
            }

            bool is_valid = true;
            for (const auto& entry : freq_subtree) {
                int count = entry.second;
                if (count > k) {
                    is_valid = false;
                    break;
                }
            }
            if (is_valid) {
                for (const auto& entry : freq_remaining_tree) {
                    int count = entry.second;
                    if (count > k) {
                        is_valid = false;
                        break;
                    }
                }
            }

            if (is_valid) {
                count_valid_edges++;
            }
        }

        return count_valid_edges;
    }

int main() {
    cin >> n >> k;
    
    for (int i = 1; i <= n; i++) {
        cin >> values[i];
    }
    
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    
    dfs(1, -1);
    count_good_edges(1, -1);
    
    cout << result << endl;
    
    return 0;
}
