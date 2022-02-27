// Author : tawfik shalash
//8888888888888888888888888888888888888888888888888888888888888//
//8888888888888888888888888888888888888888888888888888888888888//
//88888888888888888888888 tawfik shalash 8888888888888888888888//
//8888888888888888888888888888888888888888888888888888888888888//
//8888888888888888888888888888888888888888888888888888888888888//

#include<bits/stdc++.h>
using namespace std;

const int N=25;

int target,n,bestSum,bestMsk;
int arr[N];

void backtrack(int idx,int msk,int sum)
{
    if(sum>target)
        return;
    if(sum>bestSum)
    {
        bestSum=sum;
        bestMsk=msk;
    }
    if(idx==n)
    {
        return;
    }
    backtrack(idx+1,msk,sum);
    backtrack(idx+1,msk|(1<<idx),sum+arr[idx]);
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

while(cin>>target)
{
    cin>>n;
    for(int i=0;i<n;++i)
    {
        cin>>arr[i];
    }
    bestMsk=bestSum=0;
    backtrack(0,0,0);

    // know we should print the numbers with one in it 
    for(int i=0;i<n;i++)
    {
        if(bestMsk&(1<<i))
        {
            cout<<arr[i]<<' ';
        }
    }
    cout<<"sum:"<<bestSum<<endl;
}





    return 0;
}





