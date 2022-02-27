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
map<ll,ll>mp;

ll factorial(ll n){
    if(n==1)
        return 1;
    return factorial(n-1)*n;
}

int main() {

    fast
#ifndef ONLINE_JUDGE
freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
#endif

    ll N;
    cin>>N;
    ll num= factorial(N);

    vector<int>v(N);
    for(int i=0;i<N;i++)
    {
        cin>>v[i];
    }
    int k=0;
    do{
        k++;
    }while(next_permutation(v.begin(),v.end()));
        for(int i=0;i<N;i++)
        {
            cin>>v[i];
        }
        do{
            k--;
        }while(next_permutation(v.begin(),v.end()));

        cout<<abs(k)<<endl;

    return 0;
}