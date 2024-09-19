#include <bits/stdc++.h>
using namespace std;

int f(int n, vector<int> a){
    if(n==0) return 0;
    int maxii=1,maxid=1;
    int ci=1,cd=1;

    for(int i=1;i<n;i++){
        if(a[i]>a[i-1]) ci++;
        else ci=1;
        maxii=max(maxii,ci);
        if(a[i]<a[i-1]) cd++;
        else cd=1;
        maxid=max(maxid,cd);
    }
    return max(maxii,maxid);
}

int main(){
    int n; cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<f(n,a)<<endl;
    return 0;
}

// 6 25 46 15 96 24 10