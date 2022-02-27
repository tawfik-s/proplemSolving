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
bool factork(int N)
{
    si factors;

    int PF=2;
    while(PF*PF<=N)
    {
        while(N%PF==0)
        {
            N/=PF;
            factors.insert(PF);
        }
        PF++;
    }
    if(N!=1)factors.insert(N);
    if(factors.size()==2)
    {
        return true;
    }
    return false;
}

ll d=1073741824;

ll Divisors(ll n)
{
   ll count=0;
    for (int i=1; i<=sqrt(n); i++)
    {
        if (n%i == 0)
        {
            // If divisors are equal, print only one
            if (n/i == i)
                count++;

            else // Otherwise print both
                count+=2;
        }
    }
    return count;
}
map<ll,ll>mp;
int main() {

    fast
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
#endif

ll a,b,c;
cin>>a>>b>>c;

ll sum=0;
for(int i=1;i<=a;i++)
{
    for(int j=1;j<=b;j++)
    {
        for(int k=1;k<=c;k++)
        {
            ll x=i*j*k;
            if(mp[x]!=0) {
                sum = sum % d + mp[x];
                sum = sum % d;
            }
            else
            {
                mp[x]=Divisors(i*j*k)%d;
                sum = sum % d + mp[x];
                sum = sum % d;
            }
        }
    }
}

cout<<sum;
    return 0;
}
