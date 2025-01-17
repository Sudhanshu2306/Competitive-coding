#include <bits/stdc++.h> 
using namespace std;

int f(vector<int> weight, vector<int> value, int n, int maxWeight) {
    vector<vector<int>> dp(n + 1, vector<int>(maxWeight + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= maxWeight; w++) {
            if (weight[i - 1] <= w) {
                dp[i][w] = max(dp[i - 1][w], value[i - 1] + dp[i - 1][w - weight[i - 1]]);
            } 
            else dp[i][w] = dp[i - 1][w];
        }

    }
    return dp[n][maxWeight];

}

int main(){
    int n; cin>>n;
    vector<int> w(n);
    for(int i=0;i<n;i++) cin>>w[i];

    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];

    int cap; cin>>cap;
    int ans=f(w,v,n,cap);
    cout<<ans<<endl;
    return 0;
}