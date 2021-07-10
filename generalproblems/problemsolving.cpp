#include<bits/stdc++.h>
using namespace std;

int main(){
     string s;
     cin>>s;
     stack <char>st;

     for(int i=0;i<s.size();i++)
     {

         if(s[i]==st.top()&&!st.empty())
         {
             st.pop();
         }
         else
         {
             st.push(s[i]);
         }
     }
     if(st.empty())
         cout<<"Yes";
     else
         cout<<"No";
    return 0;
}
