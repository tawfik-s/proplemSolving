
/*
author: tawfik shalash
　　██░▀██████████████▀░██
　　█▌▒▒░████████████░▒▒▐█
　　█░▒▒▒░██████████░▒▒▒░█
　　▌░▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒░▐
　　░▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒░
　 ███▀▀▀██▄▒▒▒▒▒▒▒▄██▀▀▀██
　 ██░░░▐█░▀█▒▒▒▒▒█▀░█▌░░░█
　 ▐▌░░░▐▄▌░▐▌▒▒▒▐▌░▐▄▌░░▐▌
　　█░░░▐█▌░░▌▒▒▒▐░░▐█▌░░█
　　▒▀▄▄▄█▄▄▄▌░▄░▐▄▄▄█▄▄▀▒
　　░░░░░░░░░░└┴┘░░░░░░░░░
　　██▄▄░░░░░░░░░░░░░░▄▄██
　　████████▒▒▒▒▒▒████████
　　█▀░░███▒▒░░▒░░▒▀██████
　　█▒░███▒▒╖░░╥░░╓▒▐█████
　　█▒░▀▀▀░░║░░║░░║░░█████
　　██▄▄▄▄▀▀┴┴╚╧╧╝╧╧╝┴┴███
　　██████████████████████
     عك وليس كله كويس
*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef set<int> si;
typedef pair<ll, int> ii;
const ll INF = 1e14;
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define endl "\n"
ll M = 1e9 + 7;
ll OO = 1e9;
const ll N=1e5+9;
ll MOD=1e9+7;


int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
#endif

    ll n,q,u;
    cin>>n>>q>>u;
    vector<ll>arr(n);
    int sqr=(int)(ceil(sqrt(n)));
    vector<vector<ll>>blocks(sqr);
    for(int i=0; i<n; i++){
        cin>>arr[i];
        blocks[i/sqr].push_back(arr[i]);
    }
    for(int i=0;i<sqr;i++)
    {
        sort(blocks[i].begin(),blocks[i].end());
    }
    while(q--){
            ll l,r,sum=0,c,v;
            cin>>l>>r>>c>>v;
            --l,--r;--v;
            for(int i=l; i<=r;){
                if(i%sqr==0 && i+sqr-1<=r){
                    sum+=lower_bound(blocks[i/sqr].begin(), blocks[i/sqr].end(), c)-blocks[i/sqr].begin();
                    i+=sqr;
                }
                else {
                    if(arr[i++]<c)
                        sum++;
                }
            }
            ll newval=u*sum/(r-l+1);
            int bi=v/sqr;
            ll arrinbi= lower_bound(blocks[bi].begin(),blocks[bi].end(),arr[v])-blocks[bi].begin();
            blocks[bi][arrinbi]=newval;
            sort(blocks[bi].begin(),blocks[bi].end());
            arr[v]=newval;

    }
    for(auto arr:arr)
    {
        cout<<arr<<endl;
    }



    return 0;
}

