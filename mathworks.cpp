#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; cin>>n;
    vector<string> a(n);
    for(int i=0;i<n;i++) cin>>a[i];

    vector<int> cnt(26,0);
    for(auto it:a){
        for(auto itr:it) cnt[itr-'a']++;
    }

    vector<int> x;
    int total=0;
    for(auto it:a){
        int z=it.size();
        x.push_back(it.size());
    }
    sort(x.begin(),x.end());

    int pairs=0;
    int odds=0;
    for(auto it:cnt){
        odds+=(it%2);
        pairs+=(it/2);
    } 
    int ans=0;
    for(auto it:x){
        if(it%2==0){
            if(pairs*2>=it){
                pairs-=(it/2);
            }
            else break;
        }
        else{
            if(odds>0){
                if(pairs>=(it/2)){
                    pairs-=(it/2); odds--;
                }
                else break;
            }
            else{
                if(pairs>=((it/2)+1)){
                    pairs-=((it/2)+1); odds++;
                }
                else break;
            }
        }
        ans++;
    }
    cout<<ans<<endl;
    return 0;
}