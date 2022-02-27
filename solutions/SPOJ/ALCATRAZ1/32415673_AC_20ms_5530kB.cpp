//8888888888888888888888888888888888888888888888888888888888888//
//8888888888888888888888888888888888888888888888888888888888888//
//88888888888888888888888 tawfik shalash 8888888888888888888888//
//8888888888888888888888888888888888888888888888888888888888888//
//8888888888888888888888888888888888888888888888888888888888888//

#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{

    ios_base::sync_with_stdio(false); cin.tie(NULL);  cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

int t;
cin>>t;
while(t--)
{
    string s;
    cin>>s;
    ll sum=0;
    ll n=s.size();
    for(ll i=0;i<n;i++)
    {
        sum+=(s[i]-'1')+1;
    }
    cout<<sum<<endl;

}







    return 0;
}





























