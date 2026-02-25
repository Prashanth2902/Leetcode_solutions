#include<bits/stdc++.h>
using namespace std;

void solve() {
    int a,b,x,y;
    cin >> a >> b >> x >> y;
    int ans = 0;
    while(a >= x) {
        ans += y;
        a -= x;
    }
    ans += a + b;
    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}