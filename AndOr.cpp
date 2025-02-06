#include <iostream>
#include <vector>
#include <algorithm> // Make sure to include this for std::max

using namespace std;

// Function composition for segment tree nodes
pair<int, int> compose(pair<int, int> left, pair<int, int> right, int flip) {
    int new_flip = (left.second + right.second * (1 - flip)) % 2;
    int new_val = (left.first * (1 - flip)) | (right.first * flip); // Corrected: Using bitwise OR
    return {new_val, new_flip};
}

// Build segment tree
void build(vector<pair<int, int>>& tree, vector<int>& a, int v, int tl, int tr) {
    if (tl == tr) {
        tree[v] = {a[tl], 0};
    } else {
        int tm = (tl + tr) / 2;
        build(tree, a, v * 2, tl, tm);
        build(tree, a, v * 2 + 1, tm + 1, tr);
        tree[v] = compose(tree[v * 2], tree[v * 2 + 1], (tm - tl + 1) % 2);
    }
}

// Update segment tree node
void update(vector<pair<int, int>>& tree, int v, int tl, int tr, int pos, int new_val) {
    if (tl == tr) {
        tree[v] = {new_val, 0};
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm) {
            update(tree, v * 2, tl, tm, pos, new_val);
        } else {
            update(tree, v * 2 + 1, tm + 1, tr, pos, new_val);
        }
        tree[v] = compose(tree[v * 2], tree[v * 2 + 1], (tm - tl + 1) % 2);
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int q;
        cin >> q;

        vector<pair<int, int>> tree(4 * (max(0, n - 1))); // Corrected size calculation

        if (n > 1) {
            build(tree, a, 1, 1, n - 1);
        }


        while (q--) {
            int p, x;
            cin >> p >> x;
            p--;
            a[p] = x;

            if (n == 1) {
                cout << a[0] << endl;
            } else {
                if (p == 0) {
                    pair<int, int> result = (n > 1) ? tree[1] : make_pair(0,0) ; // Handle n=1 case
                    cout << ((a[0] & result.first) | ((1 - a[0]) & (1 - result.first))) << endl;
                } else {
                    update(tree, 1, 1, n - 1, p, x);
                    pair<int, int> result = tree[1];
                    cout << ((a[0] & result.first) | ((1 - a[0]) & (1 - result.first))) << endl;
                }
            }
        }
    }
    return 0;
}