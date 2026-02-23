#include<bits/stdc++.h>
using namespace std;

int main() {
    long long n;
    cin >> n;
    vector<long long> arr(n-1);
    for(int i=0;i<n-1;i++) cin >> arr[i];
    long long totalSum = n*(n+1)/2;
    long long currSum = 0;
    for(auto n: arr) currSum += n;
    cout << totalSum - currSum << endl;
    return 0;
}