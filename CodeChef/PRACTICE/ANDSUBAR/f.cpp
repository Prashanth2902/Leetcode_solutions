#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll f(ll n) {
    if(n==1) return 1;

    ll ans = 1;
    ll p = 1;
    while(p <= n) {
        ll nextP = 2*p;
        ll currLen = min(n, nextP-1) - p + 1;
        ans = max(ans, currLen); 
        p = nextP;
    }
    return ans;
}

void solve() {
    ll n;
    cin >> n;
    cout << f(n) << endl;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}