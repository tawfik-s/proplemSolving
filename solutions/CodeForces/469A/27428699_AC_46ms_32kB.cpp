#include <iostream>
#include <algorithm>
#include <string>
#include <deque>
#include <set>
using namespace std;
bool found(set <int> s,int i)
{
    for(auto s:s)
    {
        if(s==i)
        {
            return true;
        }
    }
return false;
}

int main(){
    set<int>s;
 int n;
 cin>>n;
 int p;
 cin>>p;
 int ap[100];
 for(int i=0;i<p;i++)
 {
     cin>>ap[i];
     s.insert(ap[i]);
 }
 int q;
 cin>>q;
 int bq[100];
 for(int i=0;i<q;i++)
 {
     cin>>bq[i];
     s.insert(bq[i]);
 }
 /////////////////////////////////////////////////
    for(int i=1;i<=n;i++)       //for search
    {
        if(found(s,i))
        {
            continue;
        }
        else
        {
            cout<<"Oh, my keyboard!";
            return 0;
        }

    }
cout<<"I become the guy.";

}











