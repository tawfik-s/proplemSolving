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
typedef vector<ll> vi;
#define fast     ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define endl "\n"

//binary exponentiation

const ll d= 131071;
long long binpow (long long a,long long b)
{
    if(b==0)
        return 1;
    long long res=binpow(a,b/2);
    res=res%d;
    if(b%2)
    {
        return ((res*res)%d*a)%d;
    }
    else
    {
        return (res*res)%d;
    }
}



int main() {

    fast
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
#endif

    string k;string s="";
    while(cin>>k)
    {

        if(k.back()!='#')
        {
            s+=k;
            continue;;
        }
        s+=k;
        s.pop_back();
        reverse(s.begin(),s.end());
        int n=s.size();
        ll res=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='1') {
                res = res % d;
                res +=binpow(2,i);
                res = res % d;
            }
        }
        if(res%d==0)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
        s="";

    }

    return 0;
}