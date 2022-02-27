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
int ans=0;
int jo;
vector<string>v;
set<string>vv;
class Trie {
private:
    struct node {
        bool leaf;
        int num;
        int state;
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
        nd->leaf = 1;
        nd->num = 1;
        nd->state=-1;
        return nd;
    }

    void add(string s) {
        node *nd = root;
        for (int i = 0; i < s.length(); i++) {

            if (nd->child[s[i] - 'a'] == NULL) {
                nd->leaf = 0;
                nd->child[s[i] - 'a'] = create();

            } else {
                nd->child[s[i]-'a']->num =nd->child[s[i]-'a']->num + 1;
            }
            nd = nd->child[s[i] - 'a'];

        }
        nd->state=jo;
    }


    void bfs(string s)
    {
        node *nd = root;
        for (int i = 0; i < s.length(); i++) {

            if (nd->child[s[i] - 'a'] == NULL) {
                cout<<"No match."<<endl;
                return;
            }
            nd = nd->child[s[i] - 'a'];
        }
        queue<node *>qu;
        for(int i=0;i<26;i++)
        {
            if(nd->child[i]!=NULL)
            {
                qu.push(nd->child[i]);
            }
        }
        while(!qu.empty())
        {
            node * nn=qu.front();
            if(nn->state!=-1)
            {
                //
                vv.insert(v[nn->state]);
            }
            qu.pop();
            for(int i=0;i<26;i++)
            {
                if(nn->child[i]!=NULL)
                {
                    qu.push(nn->child[i]);
                }
            }
        }
        for(auto vk:vv)
        {
            cout<<vk<<endl;
        }
    }



};



int main()
{

    fast
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
#endif

    int n;
    cin>>n;
    Trie trie=Trie();
    v=vector<string>(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
        jo=i;
        trie.add(v[i]);
    }
    int q;
    cin>>q;
    for(int i=0;i<q;i++)
    {
        cout<<"Case #"<<i+1<<":"<<endl;
        vv.clear();
        string s;
        cin>>s;
       trie.bfs(s);
    }

    return 0;
}

//    int x=128,x2=133, p1=1e9+7, p2=1e9+9;
//    vector<ll>XP1(1e5+1),XP2(1e5+1);
//    XP1[0]=XP2[0]=1;
//    for(int i=1; i<=100000; i++){
//        XP1[i]=(XP1[i-1]*x)%p1;
//        XP2[i]=(XP2[i-1]*x2)%p2;
//    }
