// Author : tawfik shalash
//8888888888888888888888888888888888888888888888888888888888888//
//8888888888888888888888888888888888888888888888888888888888888//
//88888888888888888888888 tawfik shalash 8888888888888888888888//
//8888888888888888888888888888888888888888888888888888888888888//
//8888888888888888888888888888888888888888888888888888888888888//

#include<bits/stdc++.h>

using namespace std;
#define  endl "\n"
vector<string>v;
int k,j;

int dfs(int x,int y)
{
    if(x>=k||y>=j||0>y||0>x||v[y][x]=='0')
    {
        return 0;
    }

    int sum=1;
    v[y][x]='0';
    sum+=dfs(x,y+1)+dfs(x+1,y)+dfs(x+1,y+1)+dfs(x-1,y-1)+dfs(x-1,y+1)+dfs(x+1,y-1);


    return sum;

}

int main()
{

#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
#endif
    int n;
    scanf("%d\n\n",&n);
   while(n--) {
        v.clear();
        string s;
        while (getline(cin,s)) {
            if(s=="")
                break;
            v.push_back(s);
        }

        k = v[0].size();
        j = v.size();
        int maxx = 0;
        for (int i = 0; i < k; i++) {
            for (int ii = 0; ii < j; ii++) {
                maxx = max(maxx, dfs(i, ii));
            }
        }


        cout << maxx<<endl;
        if(n!=0) cout<<endl;
    }


    return 0;
}





