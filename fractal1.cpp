#include<bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin>>s;

    int n=s.size();
    if(n%2!=0){
        cout<<-1<<endl;
        return 0;
    }

    int hf=n/2;
    string x=s.substr(0, hf);
    string y="";

    for(char c:x) if(c!='a') y+=c;

    if(x+y==s) cout<<x<<endl;
    else cout<<-1<<endl;

    return 0;
}