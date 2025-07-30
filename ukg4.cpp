#include<bits/stdc++.h>
using namespace std;
long f(vector<int> x, vector<int> y, int k)
{
int n = x.size();
vector<pair<int,int>> pts(n);
for(int i = 0; i < n; ++i) pts[i] = {x[i], y[i]};
sort(pts.begin(), pts.end());                     // sort by x (then y)

long long best = numeric_limits<long long>::max();

for(int l = 0; l < n; ++l)
{
    multiset<int> ys;
    for(int r = l; r < n; ++r)
    {
        ys.insert(pts[r].second);
        if((int)ys.size() < k) continue;

        int xSpan = pts[r].first - pts[l].first;

        vector<int> ordered;
        ordered.reserve(ys.size());
        for(int v : ys) ordered.push_back(v);     // multiset → sorted array

        for(size_t i = 0; i + k - 1 < ordered.size(); ++i)
        {
            int ySpan = ordered[i + k - 1] - ordered[i];
            long long side = max(xSpan, ySpan) + 2LL;   // +2 for strict interior
            long long area = side * side;
            if(area < best) best = area;
        }
    }
}
return best;
}
int main(){
    // int n; cin>>n;
    // vector<pair<int,int>> a(n);
    // for(int i=0;i<n;i++) cin>>a[i].first>>a[i].second;

    // sort(a.begin(),a.end(),[](pair<int,int> &x, pair<int,int> &y){
    //     int p=max(abs(x.first),abs(x.second)), q=max(abs(y.first),abs(y.second));
    //     if(p==q) return abs(x.first)+abs(x.second)>abs(y.first)+abs(y.second);
    //     return p>q;
    // });
    // int k; cin>>k;

    // long long mini=1e18;
    // for(int i=0;i<=n-k;i++){
    //     int minx=1e9, maxx=-1e9;
    //     int maxy=-1e9, miny=1e9;
    //     for(int j=0;j<k;j++){
    //         minx=min(minx,a[i+j].first);
    //         maxx=max(maxx,a[i+j].first);
    //         miny=min(miny,a[i+j].second);
    //         maxy=max(maxy,a[i+j].second);
    //     }
    //     int side=max(maxx-minx+2,maxy-miny+2);
    //     mini=min(mini,1LL*side*side);
    // }
    // cout<<mini<<endl;
    int n; cin>>n;
    vector<int> x(n), y(n);
    for(int i=0;i<n;i++) cin>>x[i]>>y[i];
    int k; cin>>k;
    int ans=f(x,y,k);
    cout<<ans<<endl;
    return 0;
}