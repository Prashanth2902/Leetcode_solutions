#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n;
    cin >> n;
    vector<ll> arr(n);
    for(int i=0;i<n;i++) cin >> arr[i];
    ll ans = 0;
    for(int i=0;i<n-1;i++) {
        if(arr[i] > arr[i+1]) {
            ans += arr[i] - arr[i+1];
            arr[i+1] = arr[i];
        }
    }
    cout << ans << endl;
    return 0;
}