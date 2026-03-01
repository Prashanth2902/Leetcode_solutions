#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MOD = 1e9 + 7;

ll dfs(int n, unordered_map<ll,ll>& cache) {
    if(n < 0) return 0;
    if(n == 0) return 1;
    if(cache.count(n)) return cache[n];
    ll res = 0;
    for(int i=1;i<=6;i++) {
        res = (res + dfs(n-i, cache))%MOD;
    }
    return cache[n] = res;
}

ll f(int n) {
    unordered_map<ll, ll> cache;
    return dfs(n, cache);
}

int main() {
    int n;
    cin >> n;
    cout << f(n) << endl;
    return 0;
}