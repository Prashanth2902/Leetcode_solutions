#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll fun(ll row, ll col) {
    ll maxi = max(row, col);
    ll sq = (maxi-1) * (maxi-1);
    if(maxi % 2 == 0) {
        if(col != maxi) {
            return sq + col;
        } else {
            return (maxi * maxi) - row + 1;
        }
    } else {
        if(row == maxi) {
            return (maxi * maxi) - col + 1;
        } else {
            return sq + row;
        }
    }
}

void solve() {
    ll x, y;
    cin >> y >> x;
    cout << fun(x, y) << endl;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}