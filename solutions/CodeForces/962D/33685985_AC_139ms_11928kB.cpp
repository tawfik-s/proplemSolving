
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

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    int n;
    priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>st;
    cin >> n;
    vector<int>arr(n);
    for (int i = 0; i < n; i++) {

        cin>>arr[i];
        st.push({arr[i],i});
    }
    vector<pair<int,long long>>result;
    while(true)
    {
        pair<long long, int> a = st.top();
        st.pop();
        if(st.size()==0) {
            result.push_back({a.second,a.first});
            break;
        }
        else
        {
            pair<long long, int> b = st.top();
            if (a.first==b.first)
            {
                st.push({a.first *2,b.second});
                st.pop();
            }
            else
            {
                result.push_back({a.second,a.first});
            }
        }
    }
    sort(result.begin(),result.end());
    cout<<result.size()<<endl;
    for(auto x:result)
    {
        cout<<x.second<<" ";
    }


    return 0;
}

