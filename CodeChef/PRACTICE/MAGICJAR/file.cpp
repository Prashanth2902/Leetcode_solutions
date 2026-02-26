#include<bits/stdc++.h>
using namespace std;

int func(vector<int>& arr) {
    int ans = 0;
    for(auto n: arr) ans += n-1;
    return ans+1;
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