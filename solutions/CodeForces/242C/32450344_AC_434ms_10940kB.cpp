//8888888888888888888888888888888888888888888888888888888888888//
//8888888888888888888888888888888888888888888888888888888888888//
//88888888888888888888888 tawfik shalash 8888888888888888888888//
//8888888888888888888888888888888888888888888888888888888888888//
//8888888888888888888888888888888888888888888888888888888888888//

#include <bits/stdc++.h>
using namespace std;
#define ll long long

set<pair<int,int>>points;
bool valid(int x,int y)
{
    if(points.find({x,y})!=points.end())
         return true;

         return false;
}

int main()
{

    ios_base::sync_with_stdio(false); cin.tie(NULL);  cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
int x0,y0,x1,y1;


cin>>x0>>y0>>x1>>y1;
map<pair<int,int>,int>mp;
int n;
cin>>n;

while(n--)
{
    int a,b,r;
    cin>>r>>a>>b;
    for(int i=a;i<=b;i++)
    {
        points.insert({r,i});
        mp[{r,i}]=-1;
    }
}

queue<pair<int,int>> qu;
int X[] = {0, 0, 1, -1, 1, 1, -1, -1};
int Y[] = {1, -1, 0, 0, 1, -1, 1, -1};

mp[{x0,y0}]=0;
qu.push({x0,y0});
while(!qu.empty())
{
    int a=qu.front().first;
    int b=qu.front().second;
    qu.pop();
    if(a==x1&&b==y1)
    {
       cout<<mp[{a,b}];
       return 0;

    }
    for(int i=0;i<8;i++)
    {
        int xx=a+X[i];
        int yy=b+Y[i];

        if(mp.find({xx,yy})!=mp.end()&&mp[{xx,yy}]==-1)
        {
            mp[{xx,yy}]=mp[{a,b}]+1;
            qu.push({xx,yy});
        }
    }


}
cout<<-1;
   

    return 0;
}
