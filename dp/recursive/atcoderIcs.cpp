
/*
author: tawfik shalash
─▄█▄─█▀█▀█─▄█▄
▀▀████▄█▄████▀▀
─────▀█▀█▀

*/
#include <bits/stdc++.h>

using namespace std;
string s1,s2;

vector<vector<int>> memo(3050,vector<int>(3050,0));


string solvestr()
{
    s1="!"+s1;
    s2="!"+s2;
    for(int i=1;i<=s1.length()+1;i++)
        for(int j=1;j<=s2.length()+1;j++)
        {
            if(s1[i]==s2[j]) { memo[i][j] = memo[i - 1][j - 1] + 1; }
            else memo[i][j]=max(memo[i-1][j],memo[i][j-1]);

        }
    string res="";
      int  i=s1.length()-1;
      int  j=s2.length()-1;
    while(memo[i][j]!=0)
    {
        if(s1[i]==s2[j])
        {
            res=s1[i]+res;
            i--;
            j--;
        }
        else
        {
            if(memo[i-1][j]>=memo[i][j-1])
            {
                i--;
            }
            else
            {
                j--;
            }
        }
    }
   return res;
}


int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
#endif
   cin>>s1>>s2;

   cout<<solvestr();



    return 0;

}