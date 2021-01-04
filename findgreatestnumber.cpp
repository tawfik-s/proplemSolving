


// author tawfeek shalash problem solving important problems
// link: https://codeforces.com/group/8WqXTqwmkQ/contest/275783/problem/O



#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,q;
    scanf("%d",&n);
    int st[n];
    map<int,int> mp;

    for(int i=0;i<n;i++)
    {
        scanf("%d",&st[i]);
    }
    scanf("%d",&q);
    int l;
    stack <int> temp;
    for(int i=0;i<n;i++)
    {
        if(temp.empty()) { temp.push(i); continue; }

            while(!temp.empty()&&st[i]>st[temp.top()])
            {
                mp[temp.top()]=i;
               temp.pop();
            }

            temp.push(i);
    }
    while (q--){
        scanf("%d",&l);
        if(mp[l-1]!=NULL)
            printf("%d\n",mp[l-1]+1);
        else
            printf("%d\n",-1);


    }


    return 0;
}




/*

5
46 82 28 62 92
5
1
5
3
4
2


2
-1
4
5
5

