#include <bits/stdc++.h>
using namespace std;

int f(vector<pair<int,int>> a, int l){
    int n=a.size();
    sort(a.begin(),a.end());

    int ans=0;
    for(int i=0;i<n;i++){
        int st=a[i].first;
        int et=a[i].second;

        if(ans+l<=st) return ans;
        ans=max(ans,et);
    }
    if(ans+l<=1440) return ans;
    else return -1;
}

int main(){
    // n is the number of employees
    int n; cin>>n;
    vector<pair<int,int>> a;

    for(int i=0;i<n;i++){
        int m; cin>>m;
        for(int j=0;j<m;j++){
            int x; cin>>x;
            int y; cin>>y;
            a.push_back({x,y});
        }
    }
    int l; cin>>l;

    int ans=f(a,l);
    cout<<ans<<endl;

    return 0;
}

