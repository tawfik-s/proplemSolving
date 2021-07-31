// Author : tawfik shalash
//8888888888888888888888888888888888888888888888888888888888888//
//8888888888888888888888888888888888888888888888888888888888888//
//88888888888888888888888 tawfik shalash 8888888888888888888888//
//8888888888888888888888888888888888888888888888888888888888888//
//8888888888888888888888888888888888888888888888888888888888888//
#include<bits/stdc++.h>
//cpp 11
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef set<int> si;
#define fast     ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define endl "\n"

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vll;

const int MAX=1000;
vector<vector<int>>adj;
vector<bool>visited(1000,0);
int vid=1;

void dfs(int node)
{
    visited[node]=vid;
    for(auto k:adj[node])
    {
        if(visited[k]!=vid)
              dfs(k);
    }
}



int main() {

    fast
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
#endif



int n,m;
cin>>n>>m;
adj.resize(n+1);
int a,b;
for(int i=0;i<m;i++)
{
    cin>>a>>b;
    adj[a].push_back(b);
    adj[b].push_back(a);
}

int count=0;
for(int i=1;i<=m;i++)
{
    if(!visited[i])
    {
        dfs(i);
        count++;
    }
}

cout<<count<<endl;









    return 0;
}



raverse:

///Using recursion
#define MAXNODES 100000+9
#define PB push_back
typedef vector<int> vi;
vector<vi> edges(MAXNODES);
bool visited[MAXNODES];

void dfs(int node)
{
	visited[node] = true;
	for(int neighbor: edges[node])	if(!visited[neighbor])
	{
		dfs(neighbor);
	}
}

int main()
{
	int n, m;	cin >> n >> m;
	
	while(m--)
	{
		int u, v;	cin >> u >> v;
		edges[u].PB(v);
		edges[v].PB(u);
	}
	
	int ans = 0;
	for(int node = 1; node <= n; node++)
	{
		if(!visited[node])
		{
			ans++;
			dfs(node);
		}
	}
	
	cout << ans << endl;
	return 0;
}


///Another solution using a stack:
#define MAXNODES 100000+9
bool visited[MAXNODES];

int main()
{
	int n, m;	cin >> n >> m;
	
	while(m--)
	{
		int u, v;	cin >> u >> v;
		edges[u].PB(v);
		edges[v].PB(u);
	}
	
	int ans = 0;
	for(int node = 1; node <= n; node++)
	{
		if(!visited[node])
		{
			ans++;
			
			stack<int> s;
			s.push(node);
			while(!s.empty())
			{
				int u = s.top();	s.pop();
				visited[u] = true;	
				
				for(int v: edges[u])	if(!visited[v])
				{
					s.push(v);
				}
			}
		}
	}
	
	cout << ans << endl;
	return 0;
}

///When to use recursion?
- Many parameters.
- Need to solve a subproblem first.


///Find the height of a tree:

int treeHeight(int node, int prev)
{
    int h = 0;

    for(int child: edges[node]) if(child != prev)
    {
        h = max(h, 1+treeHeight(child, node));
    }

    return h;
}

int main()
{
    int n, root;  cin >> n >> root;

    loop(n-1)
    {
        int u, v;   cin >> u >> v;
        edges[u].PB(v);
        edges[v].PB(u);
    }

    cout << treeHeight(root, -1) << endl;
    return 0;
}