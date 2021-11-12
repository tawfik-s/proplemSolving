#include <bits/stdc++.h>
#define FIO                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
using namespace std;
typedef long long ll;

const int N = 1e5 + 5, M = 1e3 + 5, MOD = 1e9 + 7, OO = 0x3f3f3f3f;
const ll LOO = 0x3f3f3f3f3f3f3f3f;
const long double EPS = 1e-8;

class Trie
{
private:
    struct node
    {
        bool leaf;
        node *child[26];
    };

    node *root;

    node *create()
    {
        node *nd = new node();
        for (int i = 0; i < 26; i++)
            nd->child[i] = NULL;
        nd->leaf = 1;
        return nd;
    }

public:
    Trie()
    {
        root = create();
    }

    void add(string s)
    {
        node *nd = root;
        for (int i = 0; i < s.length(); i++)
        {
            if (nd->child[s[i] - 'a'] == NULL)
            {
                nd->leaf = 0;
                nd->child[s[i] - 'a'] = create();
            }
            nd = nd->child[s[i] - 'a'];
        }
    }
};

int main()
{
    FIO
        //    freopen("input.txt","rt",stdin);
        //    freopen("output.txt","wt",stdout);
        Trie trie = Trie();
    return 0;
}
