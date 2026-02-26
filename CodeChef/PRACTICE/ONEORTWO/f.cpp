#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

string f(ll x, ll y) {
    if(x >= y + 2) return "CHEF";
    if (x <= y - 2) return "CHEFINA";
    if (abs(x-y) <= 1 && min(x, y)&1) return "CHEF";
    else return "CHEFINA";
}

void solve() {
    ll x, y;
    cin >> x >> y;
    cout << f(x, y) << endl;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}