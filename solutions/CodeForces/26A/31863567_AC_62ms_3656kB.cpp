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


int main() {

    fast
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
#endif

int n;
cin>>n;
int count=0;
for(int i=2;i<=n;i++)
{

    if(factork(i))
    {
     //   cout<<i<<endl;
        count++;
    }
}
cout<<count;


    return 0;
}
