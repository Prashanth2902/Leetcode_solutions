#include<bits/stdc++.h>
using namespace std;

string func(string s) {
    int n = s.size();
    deque<char> q;
    for(auto c: s) q.push_back(c);
    string t = "";
    int l=0, r=n-1;
    bool flag = true;
    while(l<=r) {
        char c;
        if(flag) {
            c = s[l];
            if(t.empty()) {
                t += c;
            } else {
                if(c == '1') {
                    t = t + c;
                } else {
                    t = c + t;
                }
            }
            flag = false;
            l++;
        } else {
            c = s[r]; 
                if(c == '0') {
                    t = t + c;
                } else {
                    t = c + t;
                }
            flag = true;
            r--;
        }
    }
    return t;
}

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    cout << func(s) << endl;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}