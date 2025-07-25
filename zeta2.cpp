#include<bits/stdc++.h>
using namespace std;

int main(){
    int a,b; cin>>a>>b;
    int count=0;

    int maxi=max(a,b), mini=min(a,b);
    while(true){
        if(maxi%2==0){
            count+=((maxi/2)-1);
            mini+=(maxi/2)-1;
            maxi=2;
        }
        else{
            count+=(maxi/2);
            mini+=(maxi/2);
            maxi=1;
        }
        if(mini==0) break;
        swap(maxi,mini);
    }
    cout<<count<<endl;

    return 0;
}
