#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m; cin>>n>>m;
    vector<int> change;
    set<int> st;
    for(int i=0;i<n;i++){
        int x; cin>>x; st.insert(x);
    }
    for(auto it:st) change.push_back(it);
    for(int i=1;i<=m;i++) if(change[i]!=i){
        cout<<-1<<endl; return 0;
    }

    vector<int> arr(m);
    for(int i=0;i<m;i++) cin>>arr[i];

    int ans=m;
    for(auto it:arr) ans+=it;
    cout<<ans<<endl;

    return 0;
}