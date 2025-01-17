#include <bits/stdc++.h>

using namespace std;

int64_t h, q, i, k, s, c, a[222000];

int main()

{

    for (cin >> h >> q; i < h; i++)

        cin >> k, a[i] = k + a[i - 1] * !!i;

    for (; q--;)

    {

        cin >> k;

        s += k;
        auto j = upper_bound(a, a + h, s) - a;

        j == h ? c = s = 0 : c = j;

        cout << h - c << '\n';
    }
}