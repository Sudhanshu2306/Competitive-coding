#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++) {
            cin>>a[i][j];
        }
    }
    vector<pair<int,int>> ans;
    for(int i=0;i<n;i++){
        int r=i,c=0;
        int sum=0;
        while(r>0){
            sum+=a[r][c];
            r--;
            c++;
        }
        while(c<n){
            sum+=a[r][c];
            r++; c++;
        }
        ans.push_back({sum,i});
    }
    sort(a.begin(),a.end());
    
    for(int i=0;i<n;i++){
        cout<<ans[i].second<<" ";
    }
    return 0;
}