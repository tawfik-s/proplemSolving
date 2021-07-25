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

vector<int> v;   //empty vector of int
vector<int> v2(4,100);  //set 4 ints with value 100
vector<int>v3(v2.begin(),v2.end()); //iterate around v2 to copy data to v3
vector<int>v4(v3); //copy all data in v3 into v4

int myints[]={1,2,3,4,5};

vector<int>v5(myints,myints+5);   //you can seperate the step in two steps
//one for initialization with no assignment 
//and another step for assignment    v5.assign(myints,myints+5);

v5.push_back(12);
v5.push_back(23);
v5.emplace_back(44);

cout<<"888888888888 display the vector elements 8888888888888"<<endl<<endl;


for(auto i:v5)
{
    cout<<i<<endl;
}
////////////////to return the size
cout<<"888888888888 return sizes 8888888888888"<<endl<<endl;

cout<<"the vector size is "<<v5.size()<<endl;
cout<<"the vector capacity in memory now "<<v5.capacity()<<endl;
cout<<"the vector max size "<<v5.max_size()<<endl;


cout<<"888888888888 insert elements 8888888888888"<<endl<<endl;

vector<int>::iterator it=v.end();

v5.emplace(v5.end(),200);
v5.emplace(v5.end()-1,100);

for(auto i:v5)
{
    cout<<i<<endl;
}

cout<<"888888888888 erase 8888888888888"<<endl<<endl;

v5.erase(v5.begin()+1);  //erase the second element

v5.erase(v5.begin(),v5.begin()+4);  //eras interval

for(auto i:v5)
{
    cout<<i<<endl;
}


cout<<"888888888888 swap 8888888888888"<<endl<<endl;

v5.swap(v3);

for(auto i:v5)
{
    cout<<i<<endl;
}


    return 0;
}





