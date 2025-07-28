#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; cin>>n;
    vector<int> a(n);

    for(int i=0;i<n;i++) cin>>a[i];

    int lodd=0, leven=0;
    int rodd=0, reven=0;
    for(int i=0;i<n;i++){
        if(i%2==1) rodd+=a[i];
        else reven+=a[i];
    }
    int count=0;
    for(int i=0;i<n;i++){
        if(i%2==1) rodd-=a[i];
        else reven-=a[i];

        if(reven+lodd==rodd+leven) count++;

        if(i%2==1) lodd+=a[i];
        else leven+=a[i];
    }
    cout<<count<<endl;

    return 0;
}


// element remove hoga toh piche ka left side same rahega par right side change ho jaayega
