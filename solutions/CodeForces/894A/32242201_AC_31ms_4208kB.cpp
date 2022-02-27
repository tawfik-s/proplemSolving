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

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vll;



int main() {

    fast
#ifndef ONLINE_JUDGE
freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
#endif

    string s;
    cin>>s;
    vector<char>v;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='A'||s[i]=='Q')
            v.push_back(s[i]);
    }

    int count=0;
    if(v.size()<3)
    {
        cout<<count;
        return 0;
    }
    for(int i=0;i<v.size()-2;i++)
    {
        if(v[i]=='Q')
        {
            for(int j=i+1;j<v.size()-1;j++)
            {
                if(v[j]=='A')
                {
                    for(int k=j+1;k<v.size();k++)
                    {
                        if(v[k]=='Q')
                        {
                            count++;
                        }
                    }
                }
            }
        }
    }

    cout<<count;


    return 0;
}