#include<bits/stdc++.h>
using namespace std;

int stepsNeeded(int n, int X, int Y, const vector<int>& a) {
    vector<int> p(n+2); p[0] = 0;
    for (int i = 1; i <= n; ++i) p[i] = a[i-1];
    p[n+1]=0;

    int jumps = 0, i = 0;

    while (i <= n) {
        int d = p[i+1] - p[i];
        if (d >= 0 && d <= Y) { jumps++; i++; }  
        else if (d <  0 && -d <= X) { jumps++; i++; } 
        else break;                                
    }
    if (i == n+1) return jumps;

    while (i > 0) {
        int d = p[i-1] - p[i];
        if (d >= 0 && d <= X) { jumps++; i--; } 
        else if (d <  0 && -d <= Y) { jumps++; i--; }
        else break;                               
    }
    return jumps;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, X, Y;
    cin >> N >> X >> Y;
    vector<int> a(N);
    for (int i = 0; i < N; ++i) 
        cin >> a[i];
    cout << stepsNeeded(N, X, Y, a) << "\n";
    return 0;
}
