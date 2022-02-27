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
vector<bool> Prime(100007,0);
void sieve() {

    for(int i=2;i<=sqrt(100007);i++)
    {
        if(Prime[i]==0)
        {
            for(int j=i*i;j<=100007;j+=i)
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

    sieve();
    vi pipo;
    for(int i=2;i<100007;i++)
    {
        if(Prime[i]==0)
        {
            pipo.push_back(i);
        }
    }
    int n,m;
    cin>>n>>m;
    vector<vi>v(n,vector<int>(m));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>v[i][j];
        }
    }
    int mimi=100000;
    for(int i=0;i<n;i++)
    {
        int sum=0;
        for(int j=0;j<m;j++)
        {
            int x= lower_bound(pipo.begin(),pipo.end(),v[i][j])-pipo.begin();
            sum+=pipo[x]-v[i][j];

        }
        mimi=min(mimi,sum);
    }

    for(int i=0;i<m;i++)
    {
        int sum=0;
        for(int j=0;j<n;j++)
        {
            int x= lower_bound(pipo.begin(),pipo.end(),v[j][i])-pipo.begin();
            sum+=pipo[x]-v[j][i];

        }
        mimi=min(mimi,sum);
    }
    cout<<mimi;




    return 0;
}