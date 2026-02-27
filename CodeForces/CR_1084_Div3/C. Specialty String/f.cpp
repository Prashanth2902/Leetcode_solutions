#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

string f(string s) {
    stack<char> stk;
    for(char c: s) {
        if(!stk.empty() && stk.top() == c) {
            stk.pop();
        } else {
            stk.push(c); 
        }
        
    }
    if(stk.empty()) return "YES";
    else return "NO";
}

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    cout << f(s) << endl;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}