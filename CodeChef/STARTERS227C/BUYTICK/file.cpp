#include<bits/stdc++.h>
using namespace std;

int func(vector<int>& arr, string s, int k) {
    vector<int> available_prices;
    
    for(int i = 0; i < arr.size(); i++) {
        if(s[i] == '0') {
            available_prices.push_back(arr[i]);
        }
    }

    if(available_prices.size() < k) return -1;
    
    sort(available_prices.begin(), available_prices.end());
    
    long long ans = 0;
    for(int i = 0; i < k; i++) {
        ans += available_prices[i];
    }
    
    return ans;
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin >> arr[i];
    string s;
    cin >> s;
    cout << func(arr, s, k) << endl;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}