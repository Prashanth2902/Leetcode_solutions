#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll f(ll n) {
    ll totalWithoutAttacks = (n*n)*((n*n)-1)/2;
    ll attackSide = 4*(n-1)*(n-2);
    return totalWithoutAttacks - attackSide;
}

int main() {
    ll n;
    cin >> n;
    for(ll i=1;i<=n;i++) {
        cout << f(i) << endl;
    }
}