#include <bits/stdc++.h>
using namespace std;
#define fo(i, n) for (i = 0; i < n; i++)
#define Fo(i, k, n) for (i = k; k < n ? i < n : i > n; k < n ? i += 1 : i -= 1)
#define ll long long
#define ull unsigned long long
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define pb push_back
#define mp make_pair
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pll> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
void solve();
void solveGraphProblem();
int *dp;
vector<int> takeArrayInput(int n);
void dfs();
void bfs();

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
vector<int> takeArrayInput(int n)
{
    vi arr(n, 0);
    int i;
    fo(i, n)
    {
        cin >> arr[i];
    }
    return arr;
}
void dfsUtil(int u, vector<int> adj[], vector<bool> &visited)
{
    cout << u << " ";
    visited[u] = 1;
    for (auto x : adj[u])
    {
        if (!visited[x])
            dfsUtil(x,adj,visited);
    }
}
void dfs(int V, vector<int> adj[])
{
    vector<bool> visited(V, 0);
    for (int i = 0; i < V; i++)
        if (!visited[i])
            dfsUtil(i, adj, visited);
}
void bfs(int u, int V, vector<int> adj[])
{
    queue<int> q;
    vector<bool> visited(V, 0);
    q.push(u);
    visited[u] = true;
    int curr;
    while (!q.empty())
    {
        curr = q.front();
        q.pop();
        cout << curr << " ";
        for (int x : adj[curr])
        {
            if (!visited[x])
            {
                q.push(x);
                visited[x] = true;
            }
        }
    }
}

int bellman_ford(int n, vector<vector<int>> edges)
{
    vector<int> dist(n, INT_MAX);
    int s = edges.size();
    dist[0] = 0;

    //limiting the number of iteration to n-1
    //because  edges between s and des of a vertex shouldnot exceed n-1 
    //in dijkastra you cannot stop the algo in case of -ve cycle 
    for (int i = 1; i <= n - 1; i++)
    {
        for (int j = 0; j < s; j++)
        {
            int u = edges[j][0];
            int v = edges[j][1];
            int w = edges[j][2];
            
            if (dist[u] != INT_MAX && dist[u] + w < dist[v])
            //means number of edges are more but giving smaller distance
            //improving dist of v by vertex u->v
                dist[v] = dist[u] + w;
        }
    }

    for (int i = 0; i < s; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];
        //look at edge inside the cycle from u->v
        //lets say it was looping through the cycle and at 
        //the termination time it got trminated than also it will give the ans
        //for remerbering think like u->v where u is start point of cycle
        if (dist[u] != INT_MAX && dist[u] + w < dist[v])
            return 1;
    }
    return 0;
}

void solveGraphProblem()
{
    int V, E;
    cin >> V >> E;

    vector<int> adj[V];

    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
}

void solve()
{
    //if it is graph problrm call
    // solveGraphProblem();
}