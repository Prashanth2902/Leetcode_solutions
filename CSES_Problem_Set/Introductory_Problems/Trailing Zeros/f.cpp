#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


int main() {
    ll n;
    cin >> n;
    ll ans = 0;
    ll muliplier = 5;
    while(muliplier <= n) {
        ans += n/muliplier;
        muliplier*=5;
    }
    cout << ans << endl;
}