
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
void push(vector<ll>&t, vector<ll>&lazy, int v, int vl, int vr){
    if(lazy[v]==0) return;
    t[v*2]+=lazy[v];
    lazy[v*2]+=lazy[v];
    t[v*2+1]+=lazy[v];
    lazy[v*2+1]+=lazy[v];
    lazy[v]=0;
}

void build(vector<int>&a, vector<ll>&t, int v, int vl, int vr){
    if(vl==vr) t[v]=a[vl];
    else{
        int vm=(vl+vr)/2;
        build(a,t,2*v,vl,vm);
        build(a,t,2*v+1,vm+1,vr);
        t[v]=min(t[2*v],t[2*v+1]);
    }
}


void update(vector<ll>&t, vector<ll>&lazy, int v, int vl, int vr, int l, int r, ll toAdd){
    if(l>r) return ;
    if(vl==l && vr==r){
        t[v]+=toAdd; // Try to update this node to hold a value representing the whole range value after the update query
        lazy[v]+=toAdd; // Save info needed for update child nodes (propagate)
    }
    else{
        push(t,lazy,v, vl, vr);
        int vm=(vl+vr)/2;
        update(t,lazy,v*2,vl,vm,l,min(r,vm),toAdd);
        update(t,lazy,v*2+1,vm+1,vr,max(l,vm+1),r,toAdd);
        t[v]=min(t[2*v],t[2*v+1]);
    }
}


ll get(vector<ll>&t, vector<ll>&lazy, int v, int vl, int vr, int l, int r){
    if(l>r) return LLONG_MAX;
    if(vl==l && vr==r) return t[v];
    push(t,lazy,v, vl, vr);
    int vm=(vl+vr)/2;
    return min(get(t, lazy, 2*v, vl, vm, l, min(r,vm))  ,
            get(t, lazy, 2*v+1, vm+1, vr, max(l,vm+1) , r));
}
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
#endif

        int n,q;
        cin >> n ;
        vector<int> arr(n);
        vector<ll> tree(4 * n + 5), lazy(4 * n + 5);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        build(arr, tree, 1, 0, n - 1);
        string s;
        stringstream ss;
        cin>>q;
        cin.ignore();
        while (q--) {
            ss.clear();
            getline(cin,s);
            ss<<s;
             int tp=count(s.begin(),s.end(),' ');
            if (tp == 1) {
                int l,r;
                ss>>l>>r;
                if(l>r)
                    cout<<min(get(tree,lazy,1,0,n-1,l,n-1),get(tree,lazy,1,0,n-1,0,r))<<'\n';
                else
                    cout<<get(tree,lazy,1,0,n-1,l,r)<<'\n';
            }
            else{
                int l,r,toAdd;
                ss>>l>>r>>toAdd;
                if(l>r){
                    update(tree,lazy,1,0,n-1,l,n-1,toAdd);
                    update(tree,lazy,1,0,n-1,0,r,toAdd);
                }
                else
                    update(tree,lazy,1,0,n-1,l,r,toAdd);
            }
        }



    return 0;
}

