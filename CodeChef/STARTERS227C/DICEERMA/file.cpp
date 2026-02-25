#include<bits/stdc++.h>
using namespace std;


int func(int n, int s) {
    if (s <= 5 * n) {
        return 6 * n;
    }
    int replace = s - (5 * n);
    int score = (n - replace) * 6 + (replace * 5);
    return score;
}


void solve() {
    int n, s;
    cin >> n >> s;
    cout << func(n, s) << endl;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}