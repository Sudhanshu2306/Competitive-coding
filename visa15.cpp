#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];

    int k; cin>>k;
    set<long long> st;
    st.insert(1);
    int x=1;
    while(x<=1e9){
        x*=k;
        st.insert(x);
    }
    int count=0;
    for(int i=0;i<n;i++){
        if(st.find(a[i])!=st.end()) count++;
    }
    cout<<count<<endl;

    return 0;
}

