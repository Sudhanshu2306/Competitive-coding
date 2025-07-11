#include <bits/stdc++.h>
using namespace std;

int main() {
    double r1, r2, h;
    if (!(cin >> r1 >> r2 >> h)) return 0;

    double s = r1 * h / (r2 - r1);                     
    double halfSum = (pow(s, 3) + pow(s + h, 3)) * 0.5; 
    double t = cbrt(halfSum);                        
    double x = t - s;                                   

    double radius = r1 + (r2 - r1) * x / h;            
    cout << fixed << setprecision(2) << radius << ' ' << x;
    return 0;
}