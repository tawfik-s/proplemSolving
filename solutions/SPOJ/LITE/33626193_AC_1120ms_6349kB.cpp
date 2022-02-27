#include <bits/stdc++.h>

#define ll long long

using namespace std;

void push(vector<int>&t,vector<int>&lazy,int v,int vl ,int vr){
    if(lazy[v]%2==0)return;
    int vm=(vl+vr)/2;
    t[v*2]=(vm-vl+1)-t[v*2];
    lazy[v*2]+=lazy[v];
    t[v*2+1]=(vr-(vm+1)+1)-t[v*2+1];
    lazy[v*2+1]+=lazy[v];
    lazy[v]=0;
}

void update(vector<int>&t,vector<int>&lazy,int v,int vl,int vr,int l,int r)
{
    if(l>r)
        return;
    if(vl==l&&vr==r)
    {
        t[v]=(vr-vl+1)-t[v];
        lazy[v]++;
    }
    else{
        push(t,lazy,v,vl,vr);
        int vm=(vl+vr)/2;
        update(t,lazy,v*2,vl,vm,l,min(r,vm));
        update(t,lazy,v*2+1,vm+1,vr,max(l,vm+1),r);
        t[v]=t[2*v]+t[2*v+1];
    }

}

int get(vector<int>&t, vector<int>&lazy, int v, int vl, int vr, int l, int r){
    if(l>r) return 0;
    if(vl==l && vr==r) return t[v];
    push(t,lazy,v, vl, vr);
    int vm=(vl+vr)/2;
    return get(t, lazy, 2*v, vl, vm, l, min(r,vm))  +
            get(t, lazy, 2*v+1, vm+1, vr, max(l,vm+1) , r);
}



int main()
{
   ios_base::sync_with_stdio(0);cin.tie(0);

    int n,q;
    cin>>n>>q;
    vector<int>tree(4*n+5,0), lazy(4*n+5,0);
    int tp,l,r;
    while(q--)
    {
        cin>>tp>>l>>r;
        --l,--r;
        if(tp==0)
        {
            update(tree,lazy,1,0,n-1,l,r);
        }
        else
        {
            cout<<get(tree,lazy,1,0,n-1,l,r)<<endl;
        }

    }





    return 0;
}
