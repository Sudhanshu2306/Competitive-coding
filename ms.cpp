#include <bits/stdc++.h>
using namespace std;

int f(vector<int>& arr) {
    int n = arr.size();
    if (n <= 1) return 0;
    
    int count = 0;
    
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (i == 0 && j == n-1) continue;

            bool isSorted = true;
            int prev = INT_MIN; 
            
            for (int k = 0; k < n; k++) {
                if (k >= i && k <= j) continue;
                if (arr[k] < prev) {
                    isSorted = false;
                    break;
                }
                prev = arr[k];
            }
            if(isSorted) count++;
        }
    }
    
    return count;
}

int main() {
    vector<int> arr = {9,7,5,4,12};
    cout << "Number of ways: " << f(arr) << endl;
    
    return 0;
}