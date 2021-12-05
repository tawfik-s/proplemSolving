
/*
author: tawfik shalash
─▄█▄─█▀█▀█─▄█▄
▀▀████▄█▄████▀▀
─────▀█▀█▀

*/
#include <bits/stdc++.h>

using namespace std;

vector<int>data;
int n;
int sum=0;
int memo[120][500050];
int solve(int indx,int cursum)
{
    if(indx>=n)
    {
        return abs(2*cursum - sum);
    }
    if(memo[indx][cursum]!=-1)
        return memo[indx][cursum];


    int chose=min(solve(indx+1,cursum),solve(indx+1,cursum+data[indx]));

    return memo[indx][cursum]=chose;
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
#endif
    int t;
    cin>>t;
    while(t--)
    {
        memset(memo,-1,sizeof memo);
        sum=0;
        cin>>n;
        data.resize(n);
        for(int i=0;i<n;i++)
        {
            cin>>data[i];
            sum+=data[i];
        }
        cout<<solve(0,0)<<endl;
    }


    return 0;

}