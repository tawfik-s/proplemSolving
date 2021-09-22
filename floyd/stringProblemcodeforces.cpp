#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
//link: https://codeforces.com/problemset/problem/33/B

/*
author: tawfik shalash
　　██░▀██████████████▀░██
　　█▌▒▒░████████████░▒▒▐█
　　█░▒▒▒░██████████░▒▒▒░█
　　▌░▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒░▐
　　░▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒░
　 ███▀▀▀██▄▒▒▒▒▒▒▒▄██▀▀▀██
　 ██░░░▐█░▀█▒▒▒▒▒█▀░█▌░░░█
　 ▐▌░░░▐▄▌░▐▌▒▒▒▐▌░▐▄▌░░▐▌
　　█░░░▐█▌░░▌▒▒▒▐░░▐█▌░░█
　　▒▀▄▄▄█▄▄▄▌░▄░▐▄▄▄█▄▄▀▒
　　░░░░░░░░░░└┴┘░░░░░░░░░
　　██▄▄░░░░░░░░░░░░░░▄▄██
　　████████▒▒▒▒▒▒████████
　　█▀░░███▒▒░░▒░░▒▀██████
　　█▒░███▒▒╖░░╥░░╓▒▐█████
　　█▒░▀▀▀░░║░░║░░║░░█████
　　██▄▄▄▄▀▀┴┴╚╧╧╝╧╧╝┴┴███
　　██████████████████████


*/
int main() {

#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif


    int n;
    string s1,s2;
    cin>>s1>>s2;

    scanf("%d",&n);
    vector<vector<ll>> adj;
    adj.resize(26, vector<ll>(26,(ll)1e14));
    for(int i=0;i<26;i++)
    {
        adj[i][i]=0;
    }
        for(int j=0;j<n;j++)
        {
            char a,b;
            ll c;
            cin>>a>>b>>c;
            int u=(int)a-(int)'a';
            int v=(int)b-(int)'a';
            adj[u][v]=min(adj[u][v],c);
        }

    for(int k=0;k<26;k++)
        for(int i=0;i<26;i++)
            for(int j=0;j<26;j++)
                adj[i][j]=min(adj[i][j],adj[i][k]+adj[k][j]);

            string res="";
            ll cost=0;
            if(s1.length()!=s2.length())
            {
                cout<<-1;
                return 0;
            }
    for(int i=0;i<s1.length();i++)
    {
        int a=s1[i]-'a';
        int b=s2[i]-'a';

        if(a==b)
        {
            res+=s1[i];
        }
        else
        {
            int u=0;
            for (int ii = 0; ii < 26; ii++) {
                if(adj[a][ii]+adj[b][ii]<adj[a][u]+adj[b][u])
                {
                    u=ii;
                }
            }
            cost+=adj[a][u]+adj[b][u];
            res+=(char)(u+'a');
            if(cost>(ll)1e14)
            {
                cout<<-1;
                return 0;
            }
        }

    }
    cout<<cost<<endl<<res;





return 0;
}