#include<bits/stdc++.h>
using namespace std;

int main() {

    string s;
    cin >> s;
    int ans = 1;
    int len = 1;
    for(int i=0;i<s.size()-1;i++) {
        if(s[i] != s[i+1]) {
            len = 1;
        } else {
            len++;
            ans = max(ans, len);
        }
    }
    cout << ans << endl;
    return 0;
}