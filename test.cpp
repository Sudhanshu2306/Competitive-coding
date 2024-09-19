#include <bits/stdc++.h>
using namespace std;

int f(vector<string> p, int m) {
	int ans=0;
	for(int i=0;i<m;i++){
		set<char> st;
		for(int j=0;j<p.size();j++) st.insert(p[j][i]);

		string temp="";
		for(auto c:st) temp.push_back(c);

		if(temp.size()>2) ans++;
		else if(temp.size()==2){
			if(temp[0]!='?') ans++;
		}
	}
	return ans;
}


int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Shiv sama rahe mujh mein, aur main suniye ho raha hoon
    // NO. 1 is always an odd!

    int n; cin>>n;
    int m; cin>>m;
    vector<string> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int m=a[i].size();
    cout<<f(a,m)<<endl;

    return 0;
}


