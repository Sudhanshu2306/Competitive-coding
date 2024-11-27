#include <iostream>
#include <vector>
using namespace std;

const int MOD = 998244353;
const int MAX_Y = 4 * 1000000;  // Upper bound for Y

// Precompute number of ways to achieve each score up to MAX_Y
vector<int> precompute_ways(int max_y) {
    vector<int> dp(max_y + 1, 0);
    dp[0] = 1;  // Base case: 1 way to get score 0 (no tiles)
    
    for (int value = 2; value <= max_y; value *= 2) {  // Only powers of 2
        for (int j = max_y; j >= value; --j) {
            dp[j] = (dp[j] + dp[j - value]) % MOD;
        }
    }
    return dp;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    
    vector<int> queries(t);
    int max_y = 0;

    // Read all queries and find maximum Y
    for (int i = 0; i < t; i++) {
        cin >> queries[i];
        max_y = max(max_y, queries[i]);
    }

    // Precompute the number of ways for all scores up to max_y
    vector<int> dp = precompute_ways(max_y);

    // Output result for each query
    for (int i = 0; i < t; i++) {
        cout << dp[queries[i]] << '\n';
    }

    return 0;
}
