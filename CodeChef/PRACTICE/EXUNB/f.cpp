#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n;
    cin >> n;
    if (n % 2 == 0) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
        int wins_needed = (n - 1) / 2;
        
        for (int i = 0; i < n; i++) {
            string res = "";
            for (int j = 0; j < n; j++) {
                int diff = (j - i + n) % n;
                if (diff > 0 && diff <= wins_needed) {
                    res += '1';
                } else {
                    res += '0';
                }
            }
            cout << res << endl;
        }
    }
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}