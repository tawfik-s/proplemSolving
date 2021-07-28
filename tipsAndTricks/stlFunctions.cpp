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



vector<int>v={10,20,30,30,40,30,30,40};

//max element function


cout<<"max Element position  "<<max_element(v.begin(),v.end())-v.begin()<<endl;
cout<<"max Element value "<<*max_element(v.begin(),v.end())<<endl;


//accumilate function

cout<<"the elements sum is"<<accumulate(v.begin(),v.end(),0)<<endl;

reverse(v.begin(),v.end());

for(auto i:v)
{
    cout<<i<<" ";
}

cout<<endl;

reverse(v.begin(),v.end());

cout<<" find function  "<<find(v.begin(),v.end(),30)-v.begin()<<endl;

cout<<" find function return value  "<<*find(v.begin(),v.end(),30)<<endl;

cout<<" binary search function  "<<binary_search(v.begin(),v.end(),50)<<endl;

//binary search function return ture or false

cout<<" lower bound 30 "<<lower_bound(v.begin(),v.end(),30)-v.begin()<<endl;

cout<<" upper bound 30 "<<upper_bound(v.begin(),v.end(),30)-v.begin()<<endl;

v.erase(unique(v.begin(),v.end()),v.end());

for(auto i:v)
{
    cout<<i<<" ";
}

cout<<endl;
puts("**************************prev*********************************");

vector<int>vec{2,1,3};

do{

for(auto i:vec)
{
    cout<<i<<" ";
}

cout<<endl;

}while(prev_permutation(vec.begin(),vec.end()));

puts("**********************next********************************");
do{

for(auto i:vec)
{
    cout<<i<<" ";
}

cout<<endl;

}while(next_permutation(vec.begin(),vec.end()));



    return 0;
}





