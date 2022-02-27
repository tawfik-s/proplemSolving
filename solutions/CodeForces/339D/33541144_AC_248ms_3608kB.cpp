
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
ll MOD=1e9+7;
int Max=1e9,q;



void build(vector<int>&a, vector<int>&t, int v, int vl, int vr,bool state){
    if(vl==vr) t[v]=(a[vl]);
    else{
        int vm=(vl+vr)/2;
        build(a,t,2*v,vl,vm,!state);
        build(a,t,2*v+1,vm+1,vr,!state);
        if(!state)
        t[v]=t[2*v]|t[2*v+1];
        else
            t[v]=t[2*v]^t[2*v+1];

    }
}


void update(vector<int>&t, int v, int vl, int vr, int pos, int newVal,bool state){
    if(vl==vr) t[v]=(newVal);
    else{
        int vm=(vl+vr)/2;
        if(pos<=vm) update(t,2*v,vl,vm, pos, newVal,!state);
        else update(t,2*v+1,vm+1,vr, pos, newVal,!state);
        if(!state)
            t[v]=t[2*v]|t[2*v+1];
        else
            t[v]=t[2*v]^t[2*v+1];
    }
}


int get(vector<int>&t, int v, int vl, int vr, int l, int r,bool state){
    if(l>r) return 0;
    if(vl==l && vr==r) return t[v];
    int vm=(vl+vr)/2;
    if(!state)
    return  get(t,2*v, vl, vm, l, min(r,vm),1)        |
            get(t,2*v+1, vm+1, vr, max(l,vm+1) , r,1);
    else
        return  get(t,2*v, vl, vm, l, min(r,vm),0)        ^
                get(t,2*v+1, vm+1, vr, max(l,vm+1) , r,0);

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
    int nn=n;
    n=(1<<n);
    vector<int> arr(n + 5), tree(4 * (n + 5));
    for (int i = 0; i < n; i++) {
       cin>> arr[i];
    }
    build(arr, tree, 1, 0, n - 1,!(bool)(nn%2));
    while (q--) {

        int indx, newVal;
        cin>>indx>>newVal;
        indx--;
        update(tree,1,0,n-1,indx,newVal,!(bool)(nn%2));
        arr[indx]=newVal;

        cout << get(tree, 1, 0, n - 1, 0, n-1,!(bool)(nn%2)) << '\n';
    }


    return 0;
}