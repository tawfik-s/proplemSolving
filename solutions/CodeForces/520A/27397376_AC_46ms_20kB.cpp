#include<iostream>

#include <string>
#include <deque>

using namespace std;
int main(){
    int n,count=0;
    string x;
    cin>>n;
    cin>>x;
    deque<char> alpha;
    for(int i=0;i<n;i++)
    {
        x[i]=tolower(x[i]);
    }
    for(int i=0;i<n;i++)
    {
        bool flag=true;
        for(int j=i+1;j<n;j++)
        {
            if(x[i]==x[j])
                flag=false;
        }
        if (flag)
            alpha.push_back(x[i]);

    }
   alpha.shrink_to_fit();
    if(alpha.size()==26)
        cout<<"YES";
    else
        cout<<"NO";




       return 0;
}