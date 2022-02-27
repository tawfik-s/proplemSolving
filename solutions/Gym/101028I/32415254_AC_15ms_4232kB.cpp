// Author : tawfik shalash
//8888888888888888888888888888888888888888888888888888888888888//
//8888888888888888888888888888888888888888888888888888888888888//
//88888888888888888888888 tawfik shalash 8888888888888888888888//
//8888888888888888888888888888888888888888888888888888888888888//
//8888888888888888888888888888888888888888888888888888888888888//
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef set<int> si;
#define fast     ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define endl "\n"

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;


int main() {

    fast
#ifndef ONLINE_JUDGE
freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
#endif


    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;// second is the number of strips
        vector<int>a(n);

        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        int l=0;
        int r=a[n-1]/m+1;
        while(l<=r){
            int mid=(l+r)/2;
            int x=a[0]+mid-1;
            int count=1;

            for(int i=0;i<n;i++){
                if(a[i]>x){
                    count++;
                    x=a[i]+mid-1;
                }
            }
            if(count<=m){
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        cout<<r+1<<endl;
    }

    return 0;
}