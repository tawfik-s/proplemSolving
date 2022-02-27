
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

int n,m;
vector<vector<int>>arr;
vector<vector<ll>>bit;

void add(ll x, ll y, ll diff){
    for(int i=x; i<=n; i+=(i & -i))
        for(int j=y; j<=m; j+=(j & -j))
            bit[i][j]+=diff;
}

void build(){
    arr=vector<vector<int>>(n+1,vector<int>(n+1,0));
    bit=vector<vector<ll>>(n+1,vector<ll>(n+1,0));
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            add(i,j,arr[i][j]);
}

ll prefixSum(int x, int y){
    ll sum=0;
    for(int i=x; i>=1; i-=(i & -i))
        for(int j=y; j>=1; j-=(j & -j))
            sum+=bit[i][j];
    return sum;
}

ll rangeSum(int x1, int y1, int x2, int y2){
    return prefixSum(x2,y2)-prefixSum(x1-1,y2)-prefixSum(x2,y1-1)+prefixSum(x1-1,y1-1);
}


int main()
{
   // ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
#endif
    int t;
    scanf("%d",&t);
    int cnt=1;
    while(t--)
    {
        printf("Case %d:\n",cnt++);
        n=1004;
        m=n;
        build();
        int k;
        scanf("%d",&k);
        while(k--){
            int s;
            cin>>s;
            if(s==1)
            {
                int x1,y1,x2,y2;
                scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
                printf("%d\n",rangeSum(x1+1,y1+1,x2+1,y2+1));
            }
            else if(s==0)
            {
                int l,r;
                scanf("%d%d",&l,&r);
                l++;
                r++;
                if(arr[l][r]==0) {
                    add(l, r, 1);
                    arr[l][r] = 1;
                }
            }
        }
    }



    return 0;
}


