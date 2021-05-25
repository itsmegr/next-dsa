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
void dfsUtil(int u, vector<int> adj[], vi &disc, vi &low, int time, int parent)
{
    time++;
    disc[u] = low[u] = time;
    
    for(auto v  :adj[u]){
        if(disc[v]==-1){
            dfsUtil(v, adj, disc, low, time, u);
            low[u] = min(low[u], low[v]);

            //if(low[v] <disc[u])//then it is a backedge
            //else if(low[v] ==disc[u])//then its self loop
            //in both the above its not bridge
            if(low[v]>disc[u]){
                cout<<u<<"------->"<<v<<endl;
            }

        }
        else if (v != parent){
            low[u] = min(low[u], low[v]);
        }
    }


}

void bridgesInGraph(vector<int> adj[], int V, int E)
{
    vi disc(V, -1);
    vi low(V, 0);
    for (int i = 0; i < V; i++)
        if (disc[i]==-1)
            dfsUtil(i, adj, disc, low, -1, -1);
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
        adj[v].push_back(u);
    }
    bridgesInGraph(adj, V, E);
}

void solve()
{
    //if it is graph problrm call
    solveGraphProblem();
}