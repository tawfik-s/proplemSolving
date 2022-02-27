
/*
author: tawfik shalash
─▄█▄─█▀█▀█─▄█▄
▀▀████▄█▄████▀▀
─────▀█▀█▀

*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef set<int> si;
typedef pair<int, int> ii;

const ll INF = 1e14;
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define endl "\n"
ll M = 1e9 + 7;
ll OO = 1e9;
ll MOD = 1e9 + 7;
int Max = 1e9, q;

vector<int> dictionary;

int check(string str)
{
    int flag=0;
    for(int i=0;i<str.length();i++)
    {
        if(str[i]=='L')
        {
            flag=1;
            break;
        }
    }
    if(flag==0)
    {
        return 0;
    }
    for(int i=0,len=str.length(); i <len - 2; i++)
    {
        if((dictionary[str[i]] == 1 && dictionary[str[i + 1]] == 1 && dictionary[str[i + 2]] == 1)
        ||((!dictionary[str[i]]) && (!dictionary[str[i + 1]]) && (!dictionary[str[i + 2]]))) return 0;

    }

    return flag;

}

long long solve(int i,string str)
{

    int len=str.length();
    while(str[i] != '_' && i < len)
        i++;
    if(i==len) return  check(str);
    long long ans=0;
        str[i] = 'K';
        ans += solve(i + 1, str) * 20;
        str[i] = 'O';
        ans += solve(i + 1, str) * 5;
        str[i] = 'L';
        ans += solve(i + 1, str);
        str[i]='_';
    return ans;
}

int main() {
   ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);


    dictionary.resize(200,0);
    dictionary['A']= dictionary['E']= dictionary['I']= dictionary['O']= dictionary['U']=1;
    string str;
    cin >> str;
    cout<<solve(0, str);


    return 0;
}

