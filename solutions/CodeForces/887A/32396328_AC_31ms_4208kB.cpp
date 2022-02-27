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

string s;
cin>>s;
//reverse(s.begin(),s.end());
ll num=0;
bool flag=false;
int k=0;
for(int i=0;i<s.size();i++)
{
    if(!flag&&s[i]=='1')
    {
       flag=!flag;

    }
   if(flag&&s[i]=='0')
    {
        k++;
    }
   if(k>=6)
   {
       cout<<"yes";
       return 0;
   }
}

cout<<"no";















    return 0;

}
