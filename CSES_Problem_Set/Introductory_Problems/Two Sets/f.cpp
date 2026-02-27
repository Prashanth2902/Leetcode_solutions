#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void print(vector<int>& arr1, vector<int>& arr2) {
    cout << "YES" << endl;
    cout << arr1.size() << endl;
    for(auto n: arr1) cout << n << " ";
    cout << endl;
    cout << arr2.size() << endl;
    for(auto n: arr2) cout << n << " ";
    cout << endl;
}

int main() {
    ll n;
    cin >> n;
    ll totalSum = n*(n+1)/2;
    if(totalSum&1) cout << "NO" << endl;
    else {
        vector<bool> visit(n);
        ll oneSetSum = totalSum/2;
        ll r = n;
        vector<int> arr1, arr2;
        while(oneSetSum > r) {
            oneSetSum -= r;
            arr1.push_back(r);
            visit[r-1] = true;
            r--;
        }
        visit[oneSetSum-1] = true;
        arr1.push_back(oneSetSum);
        for(int i=0;i<n;i++) {
            if(!visit[i]) arr2.push_back(i+1);
        }
        print(arr1, arr2);
    }
}