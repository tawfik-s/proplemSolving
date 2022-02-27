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
    int t;
    cin>>t;
    while(t--)
    {


        int n,a,b;
        cin>>n>>a>>b;
        string s;
        cin>>s;
        int size=s.size();
        int num=1;
        for(int i=1;i<size;i++)
        {
            if(s[i]!=s[i-1])
            {
                num++;
            }
        }
        if(b>0)
        {
            cout<<a*size+size*b;
        }
        else if(b<0)
        {
            cout<<a*size+(num/2+1)*b;
        }
        else if(b==0)
        {
            cout<<a*size;
        }

        cout<<endl;
    }


    return 0;



}
