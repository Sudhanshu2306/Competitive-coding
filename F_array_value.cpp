#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int countLessThanOrEqual(vector<int>& a, int n, int val) {
    int count = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if ((a[i] ^ a[j]) <= val) {
                count++;
            }
        }
    }
    return count;
}

int findKthStatistic(vector<int>& a, int n, int k) {
    int left = 0, right = INT_MAX;
    int result = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (countLessThanOrEqual(a, n, mid) >= k) {
            result = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        cout << findKthStatistic(a, n, k) << "\n";
    }

    return 0;
}
