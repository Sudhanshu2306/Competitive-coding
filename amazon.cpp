#include <bits/stdc++.h>
using namespace std;

long long solve(vector<int>& a){
    int n=a.size();
    long long count=0;

    while(true){
        int maxi=*max_element(a.begin(), a.end());
        int mini=*min_element(a.begin(), a.end());

        if(maxi-mini<=1) break;

        int max_idx=-1;
        for(int i=0;i<n;i++){
            if(a[i]==maxi){
                max_idx=i; break;
            }
        }
        int min_idx=-1;
        for(int i=0;i<n;i++){
            if(a[i]==mini){
                min_idx=i; break;
            }
        }

        a[max_idx]--; a[min_idx]++;
        count++;
    }
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