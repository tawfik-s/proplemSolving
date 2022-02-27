// Author : tawfik shalash
//8888888888888888888888888888888888888888888888888888888888888//
//8888888888888888888888888888888888888888888888888888888888888//
//88888888888888888888888 tawfik shalash 8888888888888888888888//
//8888888888888888888888888888888888888888888888888888888888888//
//8888888888888888888888888888888888888888888888888888888888888//
#include<bits/stdc++.h>
//cpp 11
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef set<int> si;
#define fast     ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define endl "\n"
ll n,l,r,x;

bool check(vector<int>&v)
{
    ll count=0;
    int minn=v[0];
    int maxx=0;
    for(int i=0;i<v.size();i++)
    {
        count+=v[i];
        minn=min(minn,v[i]);
        maxx=max(maxx,v[i]);
    }

    if(count>=l&&count<=r&&maxx-minn>=x)
    {
        return true;
    }
    else
    {
        return false;
    }
}
ll res=0;

void possibleSubsets(vector<int> A)
{
    int N=A.size();

    for(int i = 0;i < (1 << N); ++i)
    {
        vector<int>v;
        for(int j = 0;j < N;++j) {
            if (i & (1 << j)) {

                v.push_back(A[j]);
            }
        }
        if(!v.empty()&&check(v))
        {
            res++;
        }
    }
}

using namespace std;
int main() {

    fast
#ifndef ONLINE_JUDGE
freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
#endif

    cin>>n>>l>>r>>x;
    vector<int>v;
    v.resize(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    possibleSubsets(v);
    cout<<res;


    return 0;

}