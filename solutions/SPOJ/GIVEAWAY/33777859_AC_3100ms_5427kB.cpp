
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
ll MOD = 1e9 + 7;
int Max = 1e9, q;



int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
#endif

    int n;
    cin>>n;
    vector<int>arr(n);
    int sqr=(int)(ceil(sqrt(n)));
    vector<vector<int>>blocks(sqr);
    for(int i=0; i<n; i++){
        cin>>arr[i];
        blocks[i/sqr].push_back(arr[i]);
    }
    int gg=0;
    for(int i=0;i<sqr;i++)
    {
        sort(blocks[i].begin(),blocks[i].end());
    }
    int q;
    cin>>q;
    while(q--){
        int t;
        cin>>t;
        if(t==0){
            int l,r,sum=0,c;
            cin>>l>>r>>c;
            --l,--r;
            for(int i=l; i<=r;){
                if(i%sqr==0 && i+sqr-1<=r){
                    sum+=sqr-(lower_bound(blocks[i/sqr].begin(), blocks[i/sqr].end(), c)-blocks[i/sqr].begin());
                    i+=sqr;
                }
                else {
                    if(arr[i++]>=c)
                        sum++;
                }
            }
            cout<<sum<<'\n';
        }
        else{
            int indx, newVal;
            cin>>indx>>newVal;
            indx--;
            int pos=find(blocks[indx/sqr].begin(),blocks[indx/sqr].end(),arr[indx])-blocks[indx/sqr].begin();
            blocks[indx/sqr][pos]=newVal;
            arr[indx]=newVal;
            sort(blocks[indx/sqr].begin(),blocks[indx/sqr].end());
        }
    }



    return 0;
}
