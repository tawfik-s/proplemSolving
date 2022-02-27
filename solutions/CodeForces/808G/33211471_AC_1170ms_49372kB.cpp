
/*
author: tawfik shalash
　　██░▀██████████████▀░██
　　█▌▒▒░████████████░▒▒▐█
　　█░▒▒▒░██████████░▒▒▒░█
　　▌░▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒░▐
　　░▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒░
　 ███▀▀▀██▄▒▒▒▒▒▒▒▄██▀▀▀██
　 ██░░░▐█░▀█▒▒▒▒▒█▀░█▌░░░█
　 ▐▌░░░▐▄▌░▐▌▒▒▒▐▌░▐▄▌░░▐▌
　　█░░░▐█▌░░▌▒▒▒▐░░▐█▌░░█
　　▒▀▄▄▄█▄▄▄▌░▄░▐▄▄▄█▄▄▀▒
　　░░░░░░░░░░└┴┘░░░░░░░░░
　　██▄▄░░░░░░░░░░░░░░▄▄██
　　████████▒▒▒▒▒▒████████
　　█▀░░███▒▒░░▒░░▒▀██████
　　█▒░███▒▒╖░░╥░░╓▒▐█████
　　█▒░▀▀▀░░║░░║░░║░░█████
　　██▄▄▄▄▀▀┴┴╚╧╧╝╧╧╝┴┴███
　　██████████████████████
*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef set<int> si;
typedef pair<ll, int> ii;
const ll INF = 1e14;
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define endl "\n"
ll M = 1e9 + 7;

ll fixMod(ll a, ll m)
{
    return (a + m) % m;
}

ll pushBack(ll h, ll x, ll p, char ch)
{
    return (((h * x) % p) + ch) % p;
}

ll pushFront(ll h, ll xp, ll p, char ch)
{ // xp=XP[len]
    return (h + (xp * ch) % p) % p;
}

ll popFront(ll h, ll xp, ll p, char ch)
{ // xp=XP[len-1]
    return fixMod(h - ((xp * ch) % p), p);
}

//kmp
vector<int> prefix;
void buildprefix(string s, int n)
{
    prefix = vector<int>(n);
    int border = 0;
    for (int i = 1; i < n; i++)
    {
        while (border > 0 && s[i] != s[border])
        {
            border = prefix[border - 1];
        }
        if (s[i] == s[border])
            border++;
        prefix[i] = border;
    }
}

vector<int> Z;
void buildZ(string s, int n)
{
    Z = vector<int>(n);
    int l = 0, r = 0;
    Z[0] = 0;
    for (int i = 1; i < n; i++)
    {
        int k = i - l;
        if (i >= r || i + Z[k] >= r)
        {
            l = i;
            r = max(r, i);
            while (r < n && s[r - l] == s[r])
                r++;
            Z[i] = r - l;
        }
        else
            Z[i] = Z[k];
    }
}
string isgood; int k;
int ans=0;
class Trie {
private:
    struct node {
        bool leaf;
        int num;
        int mx;
        node *child[26];
    };
    node *root;

public:
    Trie() {
        root = create();
    }

    node *create() {
        node *nd = new node();
        for (int i = 0; i < 26; i++)
            nd->child[i] = NULL;
        nd->mx=0;
        nd->leaf = 1;
        nd->num = 0;
        return nd;
    }
    node * getroot(){
        return root;
    }

    void add(string s) {
        node *nd = root;
        for (int i = 0; i < s.length(); i++) {

            if (nd->child[s[i] - 'a'] == NULL) {
                nd->leaf = 0;
                nd->child[s[i] - 'a'] = create();
            }
            nd = nd->child[s[i] - 'a'];
        }
        nd->num++;
    }

    void dfs(node * nd)
    {
        nd->mx=nd->num;
        for(int i=0;i<26;i++)
        {
            if(nd->child[i]==NULL) continue;
            dfs(nd->child[i]);
            nd->mx=max(nd->mx,nd->child[i]->mx);
        }
    }

    pair<string,int>query(string s)
    {
        string ret1=s;
        node* nd=root;
        for(int i=0;i<s.length();i++)
        {
            if(nd->child[s[i]-'a']==NULL)
            {
                return{"",-1};
            }
            nd=nd->child[s[i]-'a'];
        }
        int ret2=nd->mx;
        while(nd->mx!=nd->num)
        {
            for(int i=0;i<26;i++)
            {
                if(nd->child[i]!=NULL&&nd->child[i]->mx==ret2)
                {
                    nd=nd->child[i];
                    ret1+=(char)(i+'a');
                    break;
                }
            }
        }
        return{ret1,ret2};
    }


};

string s,t;
int n,m;

vector<vector<int>>nxt,mem;

int getBorder(int br,char ch){
    if(br==m) br=prefix[br-1];
    while(br>0&&ch!=t[br]) br=prefix[br-1];
    if(ch==t[br]) br++;
    return br;
}

void build(){
    prefix[0]=0;
    for(int i=1;i<m;i++)
        prefix[i]=getBorder(prefix[i-1],t[i]);
    for(int br=0;br<=m;br++)
        for(int ch=0;ch<26;ch++)
            nxt[br][ch]=getBorder(br,ch+'a');
}

int solve(int i,int br){
    if(i==n) return br==m;
    if(mem[i][br]!=-1) return mem[i][br];

    if(s[i]!='?')
        return mem[i][br]=solve(i+1,nxt[br][s[i]-'a']) +(br==m);
    int ret=0;
    for(int ch=0;ch<26;ch++)
    {
        ret=max(ret,solve(i+1,nxt[br][ch])+(br==m));
    }
    return mem[i][br]=ret;

}


int main()
{

    fast
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
#endif
    cin>>s>>t;
     n=s.length();
     m=t.length();
    if(m>n)
        return cout<<"0\n",0;
     prefix=vector<int>(m);
     nxt=vector<vector<int>>(m+1,vector<int>(26));
     mem=vector<vector<int>>(n,vector<int>(m+1,-1));
     build();
     cout<<solve(0,0)<<"\n";

    return 0;
}

//    int x=128,x2=133, p1=1e9+7, p2=1e9+9;
//    vector<ll>XP1(1e5+1),XP2(1e5+1);
//    XP1[0]=XP2[0]=1;
//    for(int i=1; i<=100000; i++){
//        XP1[i]=(XP1[i-1]*x)%p1;
//        XP2[i]=(XP2[i-1]*x2)%p2;
//    }
