#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll f(vector<ll>& arr) {
    ll maxVal = *max_element(arr.begin(), arr.end());
    ll ans = 0;
    for(auto n: arr) {
        if(n == maxVal) ans++;
    }
    return ans;
}

void solve() {
    ll n;
    cin >> n;
    vector<ll> arr(n);
    for(int i=0;i<n;i++) cin >> arr[i];
    cout << f(arr) << endl;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}