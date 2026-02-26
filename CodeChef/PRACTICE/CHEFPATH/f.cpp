#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

string f(ll N, ll M) {
    if((N == 1 && M == 2)
	    || (N == 2 && M == 1)
	    || (N != 1 && M != 1 && (N % 2 == 0 || M % 2 == 0))) {
            return "Yes";
        } else {
            return "No";
        }
}

void solve() {
    ll n, m;
    cin >> n >> m;
    cout << f(n, m) << endl;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}