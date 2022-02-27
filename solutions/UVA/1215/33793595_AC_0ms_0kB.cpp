
/*
author: tawfik shalash
─▄█▄─█▀█▀█─▄█▄
▀▀████▄█▄████▀▀
─────▀█▀█▀

*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef set<int> si;
typedef pair<int, int> ii;
const ll INF = 1e14;
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define endl "\n"
ll M = 1e9 + 7;
ll OO = 1e9;
ll MOD = 1e9 + 7;
int Max = 1e9, q;
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
#endif
    int t;
    cin>>t;
    while(t--) {
        int n;
        string s;
        cin>>n;
        vector<int>arr(n);
        for(int i = 0; i < n; i++) { 
            cin >> arr[i]; 
        }
        cin>>s;
        int len = s.length(), ans = 0;
        set<int> mySet;
        mySet.insert(0);
        mySet.insert(len);
        for(int i = 0; i < n; i++) {
            auto iter = mySet.lower_bound(arr[i]);
            int low, high;
            high = *iter;
            iter--;
            low = *iter;

            vector<int> strl(26, 0), strr(26, 0);

            for(int j = arr[i] - 1; j >= low; j--) { strl[s[j] - 'a'] = 1; }

            for(int j = arr[i]; j < high; j++) { strr[s[j] - 'a'] = 1; }

            for(int j = 0; j < 26; j++) {
                if (strl[j] ^ strr[j]) {
                    // xor to check if its in poth or not in poth don't increase else increase
                    ans++;
                }
            }
            mySet.insert(arr[i]);
        }
        cout<<ans<<endl;
    }



    return 0;

}
