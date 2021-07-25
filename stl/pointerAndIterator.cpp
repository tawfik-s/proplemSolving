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
cout<<"********************pointer*************************\n"<<endl;

int n=5;
int *ptr=&n;
n=6;
cout<<ptr<<endl;
cout<<&n<<endl;
cout<<*ptr<<endl;
cout<<n<<endl;


cout<<"********************iterator*************************\n"<<endl;
vector<int>v ={1,2,3,4,5};

vector<int>::iterator it= v.begin();

cout<<" iterator point to v.begin() "<<*it<<endl;
it=next(it,1);
cout<<" iterator after next(it,1) = "<<*it<<endl;
it=prev(it,1);
cout<<" iterator after prev(it,1) = "<<*it<<endl;
advance(it,3);
cout<<" iterator after advance(it,3)= "<<*it<<endl;




cout<<"**************iterate to print the vector**************\n"<<endl;
for(vector<int>::iterator it=v.begin();it!=v.end();it++)   //iterate arount the elments using iterator
{
    cout<<*it<<endl;
}


    return 0;
}





