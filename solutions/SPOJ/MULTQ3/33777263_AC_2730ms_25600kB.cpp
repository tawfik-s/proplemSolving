
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

vector<int> sumtwoColumn(vector<int>col1, vector<int>col2){
    vector<int>ret(3);
    for(int i=0;i<3;i++)
    {
        ret[i]= col1[i] + col2[i];
    }
    return ret;
}
void goRight(vector<int>&col, int goo){
    goo%=3;
    vector<int>old=col;
    for(int i=0;i<3;i++)
    {
        col[i]=old[(i - goo + 3) % 3];
    }
}
void push(vector<vector<int>>&t, vector<int>&lazy, int v, int vl, int vr){
    if(lazy[v]==0) return;

    goRight(t[v * 2], lazy[v]);
    lazy[v*2]+=lazy[v];
    goRight(t[v * 2 + 1], lazy[v]);
    lazy[v*2+1]+=lazy[v];
    lazy[v]=0;
}

void build(vector<vector<int>>&t, int v, int vl, int vr){
    if(vl==vr) t[v][0]=1;
    else{
        int vm=(vl+vr)/2;
        build(t,2*v,vl,vm);
        build(t,2*v+1,vm+1,vr);
        t[v]= sumtwoColumn(t[2 * v], t[2 * v + 1]);
    }
}


void update(vector<vector<int>>&t, vector<int>&lazy, int v, int vl, int vr, int l, int r){
    if(l>r) return ;
    if(vl==l && vr==r){
        goRight(t[v], 1);
         lazy[v]++; 
    }
    else{
        push(t,lazy,v, vl, vr);
        int vm=(vl+vr)/2;
        update(t,lazy,v*2,vl,vm,l,min(r,vm));
        update(t,lazy,v*2+1,vm+1,vr,max(l,vm+1),r);
        t[v]= sumtwoColumn(t[2 * v], t[2 * v + 1]);
    }
}


vector<int> get(vector<vector<int>>&t, vector<int>&lazy, int v, int vl, int vr, int l, int r){
    if(l>r)
    {
        vector<int>ret(3,0);
        return ret;
    }
    if(vl==l && vr==r) return t[v];
    push(t,lazy,v, vl, vr);
    int vm=(vl+vr)/2;
    return sumtwoColumn(get(t, lazy, 2 * v, vl, vm, l, min(r, vm)),
                        get(t, lazy, 2 * v + 1, vm + 1, vr, max(l, vm + 1), r));
}
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
#endif
    int n,q;
    cin>>n>>q;
    vector<vector<int>>tree(4*n+5,vector<int>(3,0));
    vector<int>lazy(4*n+5);
    build(tree,1,0,n-1);
    while(q--)
    {
        int tp,l,r;
        cin>>tp>>l>>r;
        if(tp)
        {
            cout<<get(tree,lazy,1,0,n-1,l,r)[0]<<endl;
        }
        else
            update(tree,lazy,1,0,n-1,l,r);
    }


    return 0;
}
