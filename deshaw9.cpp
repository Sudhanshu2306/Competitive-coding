#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &a){
    int n=a.size();
    int count=0;

    for(int i=0;i<n-1;i++){
        if(a[i]>a[i+1]){
            count+=(a[i]-a[i+1]);
        }
    }
    count+=a[n-1];
    return count;
}

int main(){
    int n; cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];

    int ans=solve(a);
    cout<<ans<<endl;
    return 0;
}