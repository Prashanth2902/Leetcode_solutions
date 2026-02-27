#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int f(vector<int>& arr) {
    int n = arr.size();
    vector<int> res = arr;
    sort(res.begin(), res.end());
    if(res == arr) return n;
    else return 1;
}

void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin >> arr[i];
    cout << f(arr) << endl;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}