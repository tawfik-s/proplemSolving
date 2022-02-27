
#include <iostream>
#include <string>
#include<cmath>
#include<algorithm>
using namespace std;
int main(){

    char z;
    cin>>z;
    string s1="qwertyuiop",s2="asdfghjkl;",s3="zxcvbnm,./",r=""
            ,st,s="qwertyuiopasdfghjkl;zxcvbnm,./",lt="";
    cin>>st;
    if(z=='R')
    {
        for(int i=0;i<st.length();i++)
        {
            for(int j=1;j<s.length();j++)
            {
                lt=s[j-1];
                if(st[i]==s[j]) {
                    r+= lt;
                    break;
                }

            }
        }
    }
    if(z=='L')
    {
        for(int i=0;i<st.length();i++)
        {
            for(int j=0;j<s.length()-1;j++)
            {
                lt=s[j+1];
                if(st[i]==s[j]) {
                    r+= lt;
                    break;
                }

            }
        }
    }

    cout<<r;
    return 0;
}
