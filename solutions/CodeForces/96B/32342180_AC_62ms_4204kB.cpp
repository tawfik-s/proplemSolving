// Author : tawfik shalash
//8888888888888888888888888888888888888888888888888888888888888//
//8888888888888888888888888888888888888888888888888888888888888//
//88888888888888888888888 tawfik shalash 8888888888888888888888//
//8888888888888888888888888888888888888888888888888888888888888//
//8888888888888888888888888888888888888888888888888888888888888//

#include<bits/stdc++.h>
using namespace std;
long long n;
long long result=-1;
void backtrack(int j4, int i7, long long num)
{
    if(num>=n)
    {
        if(result>num||result==-1)
        {
            if(i7==j4)
            {
                result=num;
                return;
                }
        }
        if(num>n*100)
        {
            return;
        }
    }
    
        backtrack(j4+1,i7,(num*10)+4 );
        backtrack(j4,i7+1,(num*10)+7);


}

int main()
{

ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
#endif
cin>>n;

backtrack(0,0,0);
cout<<result;






    return 0;
}





