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
vector<bool> Prime(1007,0);

void sieve() {
    Prime[1]=1;
    for(int i=2;i<=sqrt(1007);i++)
    {
        if(Prime[i]==0)
        {
            for(int j=i*i;j<=1005;j+=i)
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
    for(int i=2;i<1001;i++)
    {
        if(Prime[i]==0)
        {
            pipo.push_back(i);
        }
    }
    map<int,int> mp;
    int n,k;
    cin>>n>>k;
    for(int i = 0 ; i<pipo.size()-1 ; i++){
        mp[pipo[i]+pipo[i+1]+1] = 1;
    }

    for(int i = 4; i<=n ; i++) { //check all until n
        if (mp[i] == 1&&Prime[i] == 0) {
                k--;
        }
    }
    if(k<=0){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }



    return 0;
}
