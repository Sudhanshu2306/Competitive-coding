#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int minSubarrayLen(const vector<ll>& x, ll target) {
    int n = x.size();
    ll sum = 0;
    int best = INT_MAX, left = 0;
    for (int right = 0; right < n; right++) {
        sum += x[right];
        while (left <= right && sum > target) {
            sum -= x[left++];
        }
        if (sum == target) {
            best = min(best, right - left + 1);
            sum -= x[left++];
        }
    }
    return best == INT_MAX ? -1 : best;
}

int solve(int n, vector<int>& a, ll k) {
    ll S = 0;
    for (int v : a) S += v;
    ll q = (S > 0 ? k / S : 0);
    if (S == 0) {
        return (k == 0 ? 0 : -1);
    }
    ll r = k - q * S;
    vector<ll> x;
    x.reserve(2 * n);
    for (int v : a) x.push_back(v);
    for (int v : a) x.push_back(v);

    ll answer = LLONG_MAX;
    if (r == 0) {
        answer = q * n;
    } else {
        int len = minSubarrayLen(x, r);
        if (len != -1) {
            answer = min(answer, q * (ll)n + len);
        }
    }
    if (q > 0) {
        ll R2 = r + S;
        int len2 = minSubarrayLen(x, R2);
        if (len2 != -1) {
            answer = min(answer, (q - 1) * (ll)n + len2);
        }
    }

    return (answer == LLONG_MAX ? -1 : (int)answer);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    long long k;
    cin >> k;

    cout << solve(n, a, k) << "\n";
    return 0;
}
