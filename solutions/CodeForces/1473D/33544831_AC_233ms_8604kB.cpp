
/*
author: tawfik shalash
─▄█▄─█▀█▀█─▄█▄
▀▀████▄█▄████▀▀
─────▀█▀█▀

*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef set<int> si;
typedef pair<int, int> ii;
const ll INF = 1e14;
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define endl "\n"
ll M = 1e9 + 7;
ll OO = 1e9;
ll MOD=1e9+7;
int Max=1e9,q;

pair<int,int>pmax(pair<int,int>a,pair<int,int>b)
{

    return {min(a.first,b.first),max(a.second,b.second)};

}



void build(vector<int>&a, vector<pair<int,int>>&t, int v, int vl, int vr){
    if(vl==vr) t[v]={a[vl],a[vl]};
    else{
        int vm=(vl+vr)/2;
        build(a,t,2*v,vl,vm);
        build(a,t,2*v+1,vm+1,vr);
        t[v]= pmax(t[2*v],t[2*v+1]);
    }
}


pair<int,int> get(vector<pair<int,int>>&t, int v, int vl, int vr, int l, int r){
    if(l>r) return {INT_MAX,INT_MIN};
    if(vl==l && vr==r) return t[v];
    int vm=(vl+vr)/2;
    return  pmax(get(t,2*v, vl, vm, l, min(r,vm))        ,
                 get(t,2*v+1, vm+1, vr, max(l,vm+1) , r));
}


int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
#endif

    int t;
    cin>>t;
    while(t--) {
        int n, q;
        cin >> n>>q;
        string s;
        cin>>s;
        vector<int> arr(n + 5);
        vector<pair<int, int>> tree(4 * (n + 5));
        arr[0]=0;
        for (int i = 1; i <= n; i++) {
            arr[i]=arr[i-1]+((s[i-1]=='+')?1:-1);
        }
        build(arr, tree, 1, 0, n );


        while (q--) {

                int l, r;
                cin >> l >> r;
                ii lef = get(tree, 1, 0, n , 0, l-1);
                ii right=lef;
                if(r!=n)
                {
                    right=get(tree, 1, 0, n , r+1, n);
                    int d=arr[r]-arr[l-1];
                    right.first-=d;
                    right.second-=d;
                }
                ii zz= pmax(lef,right);

                cout << abs(zz.second - zz.first) +1<< '\n';

        }


    }
    return 0;
}

