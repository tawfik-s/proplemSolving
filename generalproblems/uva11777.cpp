// Author : tawfik shalash
//8888888888888888888888888888888888888888888888888888888888888//
//8888888888888888888888888888888888888888888888888888888888888//
//88888888888888888888888 tawfik shalash 8888888888888888888888//
//8888888888888888888888888888888888888888888888888888888888888//
//8888888888888888888888888888888888888888888888888888888888888//

#include<bits/stdc++.h>

using namespace std;


int main()
{

#ifndef ONLINE_JUDGE
freopen("in.txt","r",stdin);
freopen("out.txt","w",stdout);
#endif


int x;cin>>x;
for(int k=1;k<=x;k++)
{
    int j,sum=0;
    for(int i=0;i<4;i++)
    {
        cin>>j;
        sum+=j;
    }
    vector<int>tem(3);
    for(int i=0;i<3;i++)
    {
       cin>>tem[i];
    }
    sort(tem.begin(),tem.end());
    sum+=((tem[2]+tem[1])/2);
    
    if(sum>=90)
    {
        cout<<"Case "<<k<<": A"<<endl;
    }
    else if(sum>=80)
    {
        cout<<"Case "<<k<<": B"<<endl;
    }
    else if(sum>=70)
    {
        cout<<"Case "<<k<<": C"<<endl;
    }
    else if(sum>=60)
    {
        cout<<"Case "<<k<<": D"<<endl;
    }
    else{
        cout<<"Case "<<k<<": F"<<endl;

    }
 



}




    return 0;
}





