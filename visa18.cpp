#include <bits/stdc++.h>
using namespace std;

int main(){
    int ih; cin>>ih;
    int n; cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int ch=0;
    for(int i=0;i<n;i++){
        ch+=a[i];
        if(ch<0) ch=0;
        if(ch>100) ch=100;
    }
    if(ch<0) ch=0;
    if(ch>100) ch=100;
    cout<<ch<<endl;
    return 0;
}

