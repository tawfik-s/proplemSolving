// Author : tawfik shalash
//8888888888888888888888888888888888888888888888888888888888888//
//8888888888888888888888888888888888888888888888888888888888888//
//88888888888888888888888 tawfik shalash 8888888888888888888888//
//8888888888888888888888888888888888888888888888888888888888888//
//8888888888888888888888888888888888888888888888888888888888888//
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef set<int> si;
#define fast     ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define endl "\n"

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;

int factors(int n)
{
    set <int > ret;
    for(int i=2; i<n/i; i++)
    {

        while(n%i==0)
        {
            ret.insert(i);
            n/=i;
        }
    }
    if(n>1)
        ret.insert(n);
    return ret.size();
}
int main() {

    fast
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
#endif

    vector<int>lucky;
    for(int i=30;i<=3000;i++)
    {

        if(factors(i)>=3)
            lucky.push_back(i);
    }
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        cout<<lucky[n-1]<<'\n';
    }
    return 0;

}
