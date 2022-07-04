#include <bits/stdc++.h>

using namespace std;
#define ll long long
//https://www.geeksforgeeks.org/longest-sub-array-sum-k/

int lenOfLongSubarr(vector<ll>&arr,int k)
{

    int n=arr.size();

    unordered_map<ll, ll> um;
    int sum = 0, maxLen = 0;

    for (int i = 0; i < n; i++) {

        sum += arr[i];

        if (sum == k)
            maxLen = i + 1;

        if (um.find(sum) == um.end())
            um[sum] = i;


        if (um.find(sum - k) != um.end()) {
            if (maxLen < (i - um[sum - k]))
                maxLen = i - um[sum - k];
        }
    }

    return maxLen;
}

int main() {
    ios_base::sync_with_stdio(false);


    ll n,s;
    cin>>n>>s;

    vector<ll>v(n,0);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    cout<<lenOfLongSubarr(v,s);

    return 0;
}