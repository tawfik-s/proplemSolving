// Author : tawfik shalash
//8888888888888888888888888888888888888888888888888888888888888//
//8888888888888888888888888888888888888888888888888888888888888//
//88888888888888888888888 tawfik shalash 8888888888888888888888//
//8888888888888888888888888888888888888888888888888888888888888//
//8888888888888888888888888888888888888888888888888888888888888//
#include<bits/stdc++.h>
//cpp 11
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef set<int> si;
#define fast     ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define endl "\n"





using namespace std;
int main() {

    fast
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
#endif
    int n;
    while(cin>>n)
    {
        if(n==0)
            break;

        int pos=0,x=0;
        int maxx=0;
        for(int i=0;i<n;i++)
        {
            cin>>x;
            pos+=x;
            if(x<0)
            {
                if(pos<0)
                    pos=0;
            }
            maxx=max(pos,maxx);
        }
        if(maxx==0)
        {
            cout<<"Losing streak."<<endl;
        }
        else
        {
            cout<<"The maximum winning streak is "<<maxx<<".\n";
        }
    }



    return 0;



}
