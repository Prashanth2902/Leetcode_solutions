#include<bits/stdc++.h>
using namespace std;

int func(vector<int>& arr) {
    unordered_set<int> seen;
    int ans = 0;
    for(auto n: arr) {
        if(seen.count(n)) {
            ans++;
            seen.clear();
        } else {
            seen.insert(n);
        }
    }
    return 2*ans;
}

void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin >> arr[i];
    cout << func(arr) << endl;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}