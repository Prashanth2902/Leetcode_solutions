#include<bits/stdc++.h>
using namespace std;

string func(long long x, long long y) {
    long long sum = x+y;
    if(sum < 0 || sum%3 != 0) return "NO";
    long long k = sum/3;
    if(x >= 2*k && x <= 4*k) return "YES";
    return "NO";
}

void solve() {
    int x, y;
    cin >> x >> y;
    cout << func(x, y) << endl;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}