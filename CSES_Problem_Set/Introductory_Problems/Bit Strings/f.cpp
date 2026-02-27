#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MOD = 1000000007;

int main() {
    ll n;
    cin >> n;
    ll res = 1;
    for(ll i=0;i<n;i++) {
        res = (res*2)%MOD;
    }
    cout << res << endl;
}