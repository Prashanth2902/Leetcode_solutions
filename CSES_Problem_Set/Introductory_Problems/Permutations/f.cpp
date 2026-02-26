#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll n;
    cin >> n;
    if(n == 2 || n == 3) {
        cout << "NO SOLUTION" << endl;
    } else {
        vector<int> res(n);
        int num = 1;
        for(int i=2;i<=n;i+=2) {
            res[i-1] = num;
            num++;
        }
        for(int i=1;i<=n;i+=2) {
            res[i-1] = num;
            num++;
        }
        for(auto n: res) cout << n << " ";
    }
    return 0;
}