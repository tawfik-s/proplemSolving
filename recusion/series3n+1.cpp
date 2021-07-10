#include<bits/stdc++.h>

using namespace std;

typedef long long ll;


//link:https://codeforces.com/group/gA8A93jony/contest/269931/problem/A



ll solve(ll n)
{
    if(n==1)
        return 1;

    if(n%2==0)
        return 1+solve(n/2);
    else
        return 1+solve(3*n+1);



}








int main ()
{
    ios_base::sync_with_stdio(0), cin.tie(0);

#ifndef  ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    ll n;
    cin>>n;
    cout<<solve(n);



    return 0;
}