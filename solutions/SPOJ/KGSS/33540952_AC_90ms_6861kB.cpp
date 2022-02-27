
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
    vector<int>z(4);
    z[0]=a.first;
    z[1]=a.second;
    z[2]=b.first;
    z[3]=b.second;
    sort(z.begin(),z.end());
    return {z[2],z[3]};

}



    void build(vector<int>&a, vector<pair<int,int>>&t, int v, int vl, int vr){
        if(vl==vr) t[v]={0,a[vl]};
        else{
            int vm=(vl+vr)/2;
            build(a,t,2*v,vl,vm);
            build(a,t,2*v+1,vm+1,vr);
            t[v]= pmax(t[2*v],t[2*v+1]);
        }
    }


    void update(vector<pair<int,int>>&t, int v, int vl, int vr, int pos, int newVal){
        if(vl==vr) t[v]={newVal,0};
        else{
            int vm=(vl+vr)/2;
            if(pos<=vm) update(t,2*v,vl,vm, pos, newVal);
            else update(t,2*v+1,vm+1,vr, pos, newVal);
            t[v]= pmax(t[2*v],t[2*v+1]);
        }
    }


    pair<int,int> get(vector<pair<int,int>>&t, int v, int vl, int vr, int l, int r){
        if(l>r) return {0,0};
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


    int n;
    int cnt=0;
    cin>>n;
        vector<int> arr(n + 5);vector<pair<int,int>> tree(4 * (n + 5));
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        build(arr, tree, 1, 0, n - 1);
        int q;
        cin>>q;
        char tp;
        while (q--) {
            cin >> tp;
            if (tp == 'Q') {
                int l, r;
                cin >> l >> r;
                l--, r--;
                ii zz=get(tree, 1, 0, n - 1, l, r);
                cout << zz.first+zz.second << '\n';
            } else {
                int indx, newVal;
                cin >> indx >> newVal;
                indx--;
                update(tree, 1, 0, n - 1, indx, newVal);
                arr[indx] = newVal;

            }
        }



    return 0;
}


