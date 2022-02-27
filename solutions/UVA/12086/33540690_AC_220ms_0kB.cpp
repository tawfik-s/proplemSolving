
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



void build(vector<int>&a, vector<int>&t, int v, int vl, int vr){
    if(vl==vr) t[v]=a[vl];
    else{
        int vm=(vl+vr)/2;
        build(a,t,2*v,vl,vm);
        build(a,t,2*v+1,vm+1,vr);
        t[v]=t[2*v]+t[2*v+1];
    }
}


void update(vector<int>&t, int v, int vl, int vr, int pos, int newVal){
    if(vl==vr) t[v]=newVal;
    else{
        int vm=(vl+vr)/2;
        if(pos<=vm) update(t,2*v,vl,vm, pos, newVal);
        else update(t,2*v+1,vm+1,vr, pos, newVal);
        t[v]=t[2*v]+t[2*v+1];
    }
}


int get(vector<int>&t, int v, int vl, int vr, int l, int r){
    if(l>r) return 0;
    if(vl==l && vr==r) return t[v];
    int vm=(vl+vr)/2;
    return  get(t,2*v, vl, vm, l, min(r,vm))        +
            get(t,2*v+1, vm+1, vr, max(l,vm+1) , r);
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
    while(cin>>n,n) {
        if(cnt)
        {
            cout<<endl;
        }
        cout<<"Case "<<++cnt<<":"<<endl;
        vector<int> arr(n + 5), tree(4 * (n + 5));
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        build(arr, tree, 1, 0, n - 1);
        string tp;
        while ( cin >> tp) {
            if (tp == "END") break;
            if (tp == "M") {
                int l, r;
                cin >> l >> r;
                l--, r--;
                cout << get(tree, 1, 0, n - 1, l, r) << '\n';
            } else {
                int indx, newVal;
                cin >> indx >> newVal;
                indx--;
                update(tree, 1, 0, n - 1, indx, newVal);
                arr[indx] = newVal;

            }
        }
    }


    return 0;
}


