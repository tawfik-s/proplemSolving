
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
int Max = 1e9;

string a,b;
int n,m;
int arr[1005][1005];
ll solve(int i,int j)
{
    if(i>(n-1))
    {
        return ((m)-j)*30;
    }
    if(j>(m-1))
    {
        return ((n)-i)*15;
    }
    if(arr[i][j]!=-1)
    {
        return arr[i][j];
    }
    ll ans=1e9;

    if(a[i]==b[j])
    {
        ans=solve(i+1,j+1);
    }

    ans=min(ans,(solve(i+1,j)+15));
    ans=min(ans,(solve(i,j+1)+30));

    return arr[i][j]=ans;
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
#endif

    while(true)
    {

        cin>>a;
        if(a=="#")
            return 0;
        cin>>b;
        n=a.length();
        m=b.length();
        memset(arr,-1,sizeof arr);
        ll x=solve(0,0);
        cout<<x<<endl;
    }


    return 0;

}
