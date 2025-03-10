#include<bits/stdc++.h>
using namespace std;

void isPossible(int a, int b, int c, int d){
    // (a,b) -> (a,a+b) or
    // (a,b) -> (a+b,b)
    if(__gcd(a,b)==__gcd(c,d)){cout<<"YES"<<endl; return;}
    cout<<"NO"<<endl;
}

int main(){
    int a,b; cin>>a>>b;
    int c,d; cin>>c>>d;
    isPossible(a,b,c,d);

    return 0;
}