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
void dijkastra(int v, vector<pair<int, int>> adj[])
{
    int s;
    cin>>s;
    //1st is distance another is node
    priority_queue<pii, vector<pii>, greater<pii> > pq;

    vi parent(v, -1);
    vi dist(v, INT_MAX);

    //made the dist of source ==0
    dist[s]=0;
    pq.push({0, s});
    pii curr;

    //here we are using greedy approach for this
    while(!pq.empty()){
        curr = pq.top();
        pq.pop();
        int totalDis;
        for(auto x : adj[curr.second]){
            totalDis = curr.first + x.second;

            if(totalDis <dist[x.first]){
                parent[x.first] = curr.second;
                dist[x.first] = totalDis;
                pq.push({totalDis, x.first});
            }
        }
    }

    for(int i=0;i<v;i++){
        deb2(i, parent[i]);
    }
    int par;
    for(int i=0;i<v;i++){
        par = parent[i];
        cout<<i<<" ";
        while(par!=s){
            cout<<par<<" ";
            par = parent[par];
        }
        cout<<endl;

    }


}
void solveGraphProblem()
{
    int V, E, W;
    cin >> V >> E;

    vector<pair<int, int>> adj[V];

    for (int i = 0; i < E; i++)
    {
        int u, v,w;
        cin >> u >> v>>w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    dijkastra(V, adj);
}

void solve()
{
    //if it is graph problrm call
    solveGraphProblem();
}