#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string S;
    getline(cin, S);

    vector<int> st;      // will hold signed terms
    char lastOp = '+';   // imaginary '+' before the first term

    auto apply = [&](int val) {
        if (lastOp == '+') {
            st.push_back(val);
        } else if (lastOp == '-') {
            st.push_back(-val);
        } else if (lastOp == '*') {
            int t = st.back(); st.pop_back();
            st.push_back(t * val);
        } else if (lastOp == '/') {
            int t = st.back(); st.pop_back();
            st.push_back(t / val);
        }
    };

    int i = 0, n = S.size();
    while (i < n) {
        char c = S[i];
        int val = 0;

        if (isdigit(c)) {
            // parse full number
            while (i < n && isdigit(S[i])) {
                val = val * 10 + (S[i] - '0');
                ++i;
            }
            apply(val);
            continue;  // we've already advanced i
        }
        else if (isalpha(c)) {
            // letter → 1
            apply(1);
            ++i;
        }
        else {
            // one of + - * /
            lastOp = c;
            ++i;
        }
    }

    // sum up everything in the stack
    long long result = 0;
    for (int x : st) result += x;
    cout << result << "\n";
    return 0;
}
