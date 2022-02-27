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

map<char,int>mp;
    char a='A';
    for(int i=0;i<26;i++)
    {
        mp[a]=i+1;
          a=(char)(a+1);
    }

    int n;
    cin>>n;
    getchar();
    cin>>a;
    for(int j=0;j<n;j++)
    {

        int k=mp[a];

        v.clear();
        vis.clear();
        v.resize(k+1);
        vis.resize(k+1,false);

        string s;
        while(cin>>s) {
            
            if(s.size()!=2)
            {
                a=s[0];
                break;
            }

            int b = mp[s[0]];
            int c = mp[s[1]];

            v[b].push_back(c);
            v[c].push_back(b);
        }
        int count=0;
        for(int i=1;i<=k;i++)
        {
            if(!vis[i])
            {

                count++;
                dfs(i);
            }
        }
        if(j==n-1)
        cout<<count<<endl;
        else
            cout<<count<<"\n\n";

    }


    return 0;
}