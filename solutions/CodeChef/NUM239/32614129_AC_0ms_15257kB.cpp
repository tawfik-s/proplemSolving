#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
vector<vector<int>>v;
vector<bool>vis;
void dfs(int i)
{
    vis[i]=true;
    for(auto k:v[i])
    {
        if(!vis[k])
        {
            dfs(k);
        }
    }
}


int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif



    int n;
    cin>>n;
    while(n--)
    {
        int r=0;
        int a,b;

        cin>>a>>b;
        if(a>b)
            swap(a,b);
        r+=(abs(b/10-a/10)*3);
        b=b%10;
        a=a%10;
        if(a<=2)
        {

        }
        else
            if(a==3)
            {
                r--;
            }
            else
                if(a>3)
                {
                    r-=2;
                }

        if(b==2)
            r++;
        else if(b>=3)
            r+=2;
        if(b==9)
            r++;

        cout<<r<<endl;

    }






    return 0;
}