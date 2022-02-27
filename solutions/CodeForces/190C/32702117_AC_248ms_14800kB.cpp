#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
int n;

int X[]={1,-1,0,0,1,-1,1,-1};
int Y[]={0,0,1,-1,1,1,-1,-1};

string  fs="";
bool flag=false;
bool flag2=true;
int num=0;
void solve(){
    string s;
    if(cin>>s)
    {
        if(s=="pair")
        {
            fs+=(s+"<");
            solve();
            fs+=",";
            solve();
            fs+=">";
        }
        else
        {
            fs+=s;
        }
    }
    else
    {
        flag=true;
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    cin>>n;
    solve();
    string x;
    cin>>x;
    if(x=="int"||x=="pair")
        cout<<"Error occurred\n";
    else
    if(flag)cout<<"Error occurred\n";
    else  cout<<fs<<endl;


    return 0;
}