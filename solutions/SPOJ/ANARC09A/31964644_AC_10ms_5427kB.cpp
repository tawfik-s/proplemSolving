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
    int nn=0;
    while(true) {
        cin >> s;
        if ( s.find( '-' ) != string::npos )
            return 0;
         nn++;
        stack<char>st;
        for(int i=0;i<s.size();i++)
        {
            if(st.empty()||s[i]=='{')
            {
                st.push(s[i]);
            }
            else
            if(s[i]==st.top())
            {
                st.push(s[i]);
            }
            else
            {
                st.pop();
            }
        }
        if(st.size()==0)
        {
            cout<<nn<<". "<<st.size()<<endl;
            continue;
        }
        int x=0;
        int r=0;
        int l=0;
        while(!st.empty())
        {
            if(st.top()=='{')
            {
                l++;
            }
            else
            {
                r++;
            }
            st.pop();
        }
        if(l%2==0)
        {
            x+=l/2;
            l=0;
        }
        else
        {
            x+=l/2;
            l=1;
        }
        if(r%2==0)
        {
            x+=r/2;
            r=0;
        }
        else
        {
            x+=r/2;
            r=1;
        }

        if(l==1&&r==1)
            x+=2;


        cout<<nn<<". "<<x<<endl;

    }
    return 0;
}