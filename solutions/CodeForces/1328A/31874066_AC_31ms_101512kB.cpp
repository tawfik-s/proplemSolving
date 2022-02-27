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

bool Prime[100000005];
void sieve() {

    for(int i=3;i<=10000;i+=2)
    {
        if(Prime[i]==0)
        {
            for(int j=i*i;j<=100000000;j+=i+i)
            {

                Prime[j]=1;

            }
        }

    }
}
int main() {

    fast
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
#endif

int k;
cin>>k;

while(k--)
{
    ll a,b;
    cin>>a>>b;
    if(a%b==0)
        cout<<0<<endl;
    else
    cout<<b-a%b<<endl;
}
    return 0;
}
