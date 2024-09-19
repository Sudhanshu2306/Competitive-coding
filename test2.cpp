#include <bits/stdc++.h>
using namespace std;

int solve(vector<int>& arr) {
    sort(arr.begin(),arr.end());
    int n=arr.size();
   
    map<int,int> mp;
    long long sum=0;
    mp[arr[n-2]]=1; mp[arr[n-1]]=1;
    for(int i=0;i<n-2;i++){
        sum+=arr[i];
        mp[arr[i]]++;
    }
    if(sum==arr[n-2]) return arr[n-1];
    else{
        for(int i=0;i<n-2;i++){
            int x=sum-arr[i]+arr[n-2];
            if(x==arr[n-1]) return arr[n-1];
        }
        return arr[n-2];
    }
    return -1;
}

int main() {
    int n; cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int result=solve(a);
    cout<<result<<endl;

    return 0;
}
